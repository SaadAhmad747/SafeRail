#include "stream.h"
#include "ui_stream.h"
#include <QTimer>

Stream::Stream(SettingsManager* settingsManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Stream)
    , streamManager(new StreamManager(settingsManager))
    , networkDataReader(new NetworkDataReader(settingsManager, this))
    , radarDataProcessor(new RadarDataProcessor(this))
{
    ui->setupUi(this);

    //Radar Visual
    const int w = 500;
    vDraw = new RadarVisual(this);
    vDraw->setFixedSize(w, w/1.5);
    ui->savisual->insertWidget(1, vDraw);

    //Stream Connections
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &Stream::onTabChanged);

    //Radar Connections
    connect(ui->RadarBtn, &QPushButton::clicked, this, &Stream::onRadarBtnClicked);
    connect(networkDataReader, &NetworkDataReader::dataReady, radarDataProcessor, &RadarDataProcessor::storeData);
    connect(radarDataProcessor, &RadarDataProcessor::clustersProcessed, this, &Stream::onProcessComplete);

    onTabChanged(0); //set Fused Tab as Default
}

Stream::~Stream()
{
    delete radarDataProcessor;
    delete networkDataReader;
    delete streamManager;
    delete vDraw;
    delete ui;
}

/**************************************Stream Code***********************************************/
void Stream::onTabChanged(int index)
{
    ui->tabWidget->setEnabled(false);

    QTimer::singleShot(500, [=]() {
        streamManager->DestroyPipelines();

        // Setup the selected pipeline
        if (index == 0) {
            streamManager->SetupAndStartFusedPipeline(ui->FusedVideoWidget);
        } else if (index == 1) {
            streamManager->SetupAndStartOpticalPipeline(ui->OpticalVideoWidget);
        } else if (index == 2) {
            streamManager->SetupAndStartThermalPipeline(ui->ThermalVideoWidget);
        }

        // Re-enable the tab widget
        ui->tabWidget->setEnabled(true);
    });
}

/**************************************Radar Code***********************************************/
void Stream::onRadarBtnClicked()
{
    if(!radarSwitch){
        ui->RadarLabel->setText("On");
        ui->RadarLabel->setStyleSheet("background-color: lightgreen");
        radarDataProcessor->processRadarData();
        networkDataReader->start();
        radarSwitch = true;
    }
    else if(radarSwitch){
        ui->RadarLabel->setText("Off");
        ui->RadarLabel->setStyleSheet("background-color: Red");
        networkDataReader->stop();
        radarDataProcessor->stopProcess();
        radarSwitch = false;
    }
}

void Stream::onProcessComplete(const QVector<RadarCluster> &processedClusters)
{
    vDraw->clusters.append(processedClusters);
    vDraw->update();
}


// #include "stream.h"
// #include "ui_stream.h"
// #include "settingsmanager.h"
// #include <gst/gst.h>
// #include <gst/video/videooverlay.h>
// #include <Qtimer>

// Stream::Stream(SettingsManager* settingsManager, QWidget *parent)
//     : QWidget(parent)
//     , ui(new Ui::Stream)
//     , pipelineOptical(nullptr)
//     , pipelineThermal(nullptr)
//     , pipelineFused(nullptr)
//     , settingsManager(settingsManager)
// {
//     ui->setupUi(this);
//     gst_init(nullptr, nullptr);

//     QJsonObject settings = settingsManager->getSettings();

//     cameraIp = settings["CameraIp"].toString();
//     cameraId = settings["CameraId"].toString();
//     cameraPass = settings["CameraPass"].toString();
//     jetsonIp = settings["JetsonIp"].toString();
//     jetsonPort = settings["JetsonPort"].toString();

//     // Set up connections for radio buttons
//     connect(ui->OpticalRadio, &QRadioButton::toggled, this, &Stream::OnRadioButtonToggled);
//     connect(ui->FusedRadio, &QRadioButton::toggled, this, &Stream::OnRadioButtonToggled);
//     connect(ui->ThermalRadio, &QRadioButton::toggled, this, &Stream::OnRadioButtonToggled);

//     encodedPass = QUrl::toPercentEncoding(cameraPass);

//     // delete this later
//     ui->RadarINLabel->hide();

//     // Start with Optical feed if it's the default
//     ui->FusedRadio->setChecked(true);
//     OnRadioButtonToggled();
// }

// Stream::~Stream()
// {
//     // Properly clean up resources
//     if (pipelineOptical) {
//         gst_element_set_state(pipelineOptical, GST_STATE_NULL);
//         gst_object_unref(pipelineOptical);
//     }
//     if (pipelineThermal) {
//         gst_element_set_state(pipelineThermal, GST_STATE_NULL);
//         gst_object_unref(pipelineThermal);
//     }
//     if (pipelineFused) {
//         gst_element_set_state(pipelineFused, GST_STATE_NULL);
//         gst_object_unref(pipelineFused);
//     }

//     delete ui;
// }

// void Stream::OnRadioButtonToggled()
// {
//     SetupAndStartOpticalPipeline();
//     SetupAndStartThermalPipeline();
//     SetupAndStartFusedPipeline();

//     // Switch to the corresponding feed based on radio button selection
//     if (ui->OpticalRadio->isChecked()) {
//         gst_element_set_state(pipelineOptical, GST_STATE_PLAYING);  // Play optical feed
//     }
//     else if (ui->ThermalRadio->isChecked()) {
//         gst_element_set_state(pipelineThermal, GST_STATE_PLAYING);  // Play thermal feed
//     }
//     else if (ui->FusedRadio->isChecked()) {
//         gst_element_set_state(pipelineFused, GST_STATE_PLAYING);  // Play thermal feed
//     }
// }

// GstElement* Stream::CreatePipeline(const QString& channel)
// {
//     QString rtspLink = QString("rtsp://%1:%2@%3:554/Streaming/Channels/%4")
//     .arg(cameraId, encodedPass, cameraIp, channel);

//     QString pipelineString = QString("rtspsrc location=%1 latency=100 ! decodebin ! videoconvert ! glimagesink")
//                                  .arg(rtspLink);

//     QByteArray pipelineByteArray = pipelineString.toUtf8();
//     const char *pipelineStr = pipelineByteArray.constData();
//     // const char *pipelineStr = "playbin uri=file:///D:/Sines%20Work/MMI/2_optical.mp4 video-sink=glimagesink";

//     GstElement *pipeline = gst_parse_launch(pipelineStr, nullptr);
//     if (!pipeline) {
//         qDebug() << "Failed to create pipeline for channel: " << channel;
//         ShowBlackScreen();
//         return nullptr;
//     }

//     return pipeline;
// }

// GstElement *Stream::CreateFusedPipeline()
// {
//     pipelineInternal = gst_pipeline_new("videp-pipeline");
//     tcpSrc = gst_element_factory_make("tcpclientsrc", "tcp-source");
//     jpegDec = gst_element_factory_make("jpegdec","jpeg-decoder");
//     videoConvert = gst_element_factory_make("videoconvert", "video-converter");
//     videoSink = gst_element_factory_make("glimagesink", "video-output");

//     if(!pipelineInternal || !tcpSrc || !jpegDec || !videoConvert || !videoSink){
//         qWarning() << "Failed to create Gstreamer elements.";
//         return nullptr;
//     }

//     g_object_set(tcpSrc, "host", jetsonIp.toStdString().c_str(), "port", jetsonPort.toInt(), nullptr);
//     gst_bin_add_many(GST_BIN(pipelineInternal), tcpSrc, jpegDec, videoConvert, videoSink, nullptr);

//     if(!gst_element_link_many(tcpSrc, jpegDec, videoConvert, videoSink, nullptr)){
//         qWarning() << "Failed to link Gstreamer elements!";
//         return nullptr;
//     }

//     return pipelineInternal;
// }

// void Stream::SetupAndStartOpticalPipeline()
// {
//     if (pipelineOptical) {
//         gst_element_set_state(pipelineOptical, GST_STATE_NULL);
//         gst_object_unref(pipelineOptical);
//         pipelineOptical = nullptr;
//     }

//     pipelineOptical = CreatePipeline("101");  // Use channel 101 for optical
//     if (!pipelineOptical) {
//         qDebug() << "Failed to create optical pipeline!";
//         return;
//     }

//     GstElement *videoSinkOptical = gst_bin_get_by_interface(GST_BIN(pipelineOptical), GST_TYPE_VIDEO_OVERLAY);
//     if (videoSinkOptical) {
//         gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkOptical), ui->VideoWidget->winId());
//         ui->stackedWidget->setCurrentWidget(ui->VideoWidget);
//     } else {
//         qDebug() << "Failed to get video sink for optical pipeline!";
//     }
// }

// void Stream::SetupAndStartThermalPipeline()
// {
//     if (pipelineThermal) {
//         gst_element_set_state(pipelineThermal, GST_STATE_NULL);
//         gst_object_unref(pipelineThermal);
//         pipelineThermal = nullptr;
//     }

//     pipelineThermal = CreatePipeline("201");  // Use channel 201 for thermal
//     if (!pipelineThermal) {
//         qDebug() << "Failed to create thermal pipeline!";
//         return;
//     }

//     GstElement *videoSinkThermal = gst_bin_get_by_interface(GST_BIN(pipelineThermal), GST_TYPE_VIDEO_OVERLAY);
//     if (videoSinkThermal) {
//         gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkThermal), ui->VideoWidget->winId());
//         ui->stackedWidget->setCurrentWidget(ui->VideoWidget);
//     } else {
//         qDebug() << "Failed to get video sink for thermal pipeline!";
//     }
// }

// void Stream::SetupAndStartFusedPipeline()
// {
//     if(pipelineFused){
//         gst_element_set_state(pipelineFused, GST_STATE_NULL);
//         gst_object_unref(pipelineFused);
//         pipelineFused = nullptr;
//     }

//     pipelineFused = CreateFusedPipeline();
//     if(!pipelineFused){
//         qWarning() << "Failed to create fused pipeline!";
//         return;
//     }

//     GstElement* videoSinkTcp = gst_bin_get_by_interface(GST_BIN(pipelineFused), GST_TYPE_VIDEO_OVERLAY);
//     if(videoSinkTcp){
//         gst_video_overlay_set_window_handle(GST_VIDEO_OVERLAY(videoSinkTcp), ui->VideoWidget->winId());
//         ui->stackedWidget->setCurrentWidget(ui->VideoWidget);
//     }else {
//         qWarning() << "Failed to get video sink for fuse piepline!";
//     }
// }

// void Stream::ShowBlackScreen()
// {
//     ui->stackedWidget->setCurrentWidget(ui->BlackScreen);
// }
