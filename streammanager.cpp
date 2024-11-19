#include "streammanager.h"

StreamManager::StreamManager(SettingsManager *settingsManager)
    : pipelineOptical(nullptr)
    , pipelineThermal(nullptr)
    , pipelineFused(nullptr)
    , pipelineInternal(nullptr)
    , settingsManager(settingsManager)
{
    gst_init(nullptr, nullptr);

    QJsonObject settings = settingsManager->getSettings();

    cameraIp = settings["CameraIp"].toString();
    cameraId = settings["CameraId"].toString();
    cameraPass = settings["CameraPass"].toString();
    jetsonIp = settings["JetsonIp"].toString();
    jetsonPort = settings["JetsonPort"].toString();
    encodedPass = QUrl::toPercentEncoding(cameraPass);
}

StreamManager::~StreamManager()
{
    DestroyPipelines();
}

/********************************* Creating Pipelines ****************************************/

GstElement* StreamManager::CreatePipeline(const QString& channel)
{
    QString rtspLink = QString("rtsp://%1:%2@%3:554/Streaming/Channels/%4")
    .arg(cameraId, encodedPass, cameraIp, channel);

    QString pipelineString = QString("rtspsrc location=%1 latency=100 ! decodebin ! videoconvert ! glimagesink")
                                 .arg(rtspLink);

    QByteArray pipelineByteArray = pipelineString.toUtf8();
    const char *pipelineStr = pipelineByteArray.constData();
    // const char *pipelineStr = "playbin uri=file:///D:/Sines%20Work/MMI/2_optical.mp4 video-sink=glimagesink";

    GstElement *pipeline = gst_parse_launch(pipelineStr, nullptr);
    if (!pipeline) {
        qDebug() << "Failed to create pipeline for channel: " << channel;
        return nullptr;
    }

    return pipeline;
}

GstElement *StreamManager::CreateFusedPipeline()
{
    pipelineInternal = gst_pipeline_new("videp-pipeline");
    tcpSrc = gst_element_factory_make("tcpclientsrc", "tcp-source");
    jpegDec = gst_element_factory_make("jpegdec","jpeg-decoder");
    videoConvert = gst_element_factory_make("videoconvert", "video-converter");
    videoSink = gst_element_factory_make("glimagesink", "video-output");

    if(!pipelineInternal || !tcpSrc || !jpegDec || !videoConvert || !videoSink){
        qWarning() << "Failed to create Gstreamer elements.";
        return nullptr;
    }

    g_object_set(tcpSrc, "host", jetsonIp.toStdString().c_str(), "port", jetsonPort.toInt(), nullptr);
    gst_bin_add_many(GST_BIN(pipelineInternal), tcpSrc, jpegDec, videoConvert, videoSink, nullptr);

    if(!gst_element_link_many(tcpSrc, jpegDec, videoConvert, videoSink, nullptr)){
        qWarning() << "Failed to link Gstreamer elements!";
        return nullptr;
    }

    return pipelineInternal;
}

/********************************* Starting Pipelines ****************************************/

void StreamManager::SetupAndStartOpticalPipeline(QWidget* videoWidget)
{
    // if (pipelineOptical) {
    //     gst_element_set_state(pipelineOptical, GST_STATE_NULL);
    //     gst_object_unref(pipelineOptical);
    //     pipelineOptical = nullptr;
    // }

    pipelineOptical = CreatePipeline("101");  // Use channel 101 for optical
    if (!pipelineOptical) {
        qDebug() << "Failed to create optical pipeline!";
        return;
    }

    GstElement *videoSinkOptical = gst_bin_get_by_interface(GST_BIN(pipelineOptical), GST_TYPE_VIDEO_OVERLAY);
    if (videoSinkOptical) {
        gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkOptical), videoWidget->winId());
    } else {
        qDebug() << "Failed to get video sink for optical pipeline!";
    }
    gst_element_set_state(pipelineOptical, GST_STATE_PLAYING);
}

void StreamManager::SetupAndStartThermalPipeline(QWidget *videoWidget)
{
    // if (pipelineThermal) {
    //     gst_element_set_state(pipelineThermal, GST_STATE_NULL);
    //     gst_object_unref(pipelineThermal);
    //     pipelineThermal = nullptr;
    // }

    pipelineThermal = CreatePipeline("201");  // Use channel 201 for thermal
    if (!pipelineThermal) {
        qDebug() << "Failed to create thermal pipeline!";
        return;
    }

    GstElement *videoSinkThermal = gst_bin_get_by_interface(GST_BIN(pipelineThermal), GST_TYPE_VIDEO_OVERLAY);
    if (videoSinkThermal) {
        gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkThermal), videoWidget->winId());
    } else {
        qDebug() << "Failed to get video sink for thermal pipeline!";
    }
    gst_element_set_state(pipelineThermal, GST_STATE_PLAYING);
}

void StreamManager::SetupAndStartFusedPipeline(QWidget *videoWidget)
{
    // if(pipelineFused){
    //     gst_element_set_state(pipelineFused, GST_STATE_NULL);
    //     gst_object_unref(pipelineFused);
    //     pipelineFused = nullptr;
    // }

    pipelineFused = CreateFusedPipeline();
    if(!pipelineFused){
        qWarning() << "Failed to create fused pipeline!";
        return;
    }

    GstElement* videoSinkTcp = gst_bin_get_by_interface(GST_BIN(pipelineFused), GST_TYPE_VIDEO_OVERLAY);
    if(videoSinkTcp){
        gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkTcp), videoWidget->winId());
    }else {
        qWarning() << "Failed to get video sink for fuse pipeline!";
    }
    gst_element_set_state(pipelineFused, GST_STATE_PLAYING);
}

void StreamManager::DestroyPipelines()
{
    if (pipelineOptical) {
        gst_element_set_state(pipelineOptical, GST_STATE_NULL);
        gst_object_unref(pipelineOptical);  // Safe unref if the element exists
        pipelineOptical = nullptr;
    }
    if (pipelineThermal) {
        gst_element_set_state(pipelineThermal, GST_STATE_NULL);
        gst_object_unref(pipelineThermal);  // Safe unref if the element exists
        pipelineThermal = nullptr;
    }
    if (pipelineFused) {
        gst_element_set_state(pipelineFused, GST_STATE_NULL);
        gst_object_unref(pipelineFused);  // Safe unref if the element exists
        pipelineFused = nullptr;
    }
    if (pipelineInternal) {
        gst_element_set_state(pipelineInternal, GST_STATE_NULL);
        gst_object_unref(pipelineInternal);  // Safe unref if the element exists
        pipelineInternal = nullptr;
    }
}
