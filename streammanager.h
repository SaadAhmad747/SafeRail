#ifndef STREAMMANAGER_H
#define STREAMMANAGER_H

#include "settingsmanager.h"
#include <gst/gst.h>
#include <gst/video/videooverlay.h>

class StreamManager
{
public:
    StreamManager(SettingsManager* settingsManager);
    ~StreamManager();

    void SetupAndStartOpticalPipeline(QWidget *videoWidget);
    void SetupAndStartThermalPipeline(QWidget *videoWidget);
    void SetupAndStartFusedPipeline(QWidget *videoWidget);

    void DestroyPipelines();

private:
    GstElement *pipelineOptical;
    GstElement *pipelineThermal;
    //fusedpipeline elements
    GstElement *pipelineFused;
    GstElement *pipelineInternal;
    GstElement *tcpSrc;
    GstElement *jpegDec;
    GstElement *videoConvert;
    GstElement *videoSink;
    GstElement* CreatePipeline(const QString& channel);
    GstElement* CreateFusedPipeline();

    //camera strings
    QString cameraIp;
    QString cameraId;
    QString cameraPass;
    QString encodedPass;
    QString jetsonIp;
    QString jetsonPort;
    SettingsManager* settingsManager;
};

#endif // STREAMMANAGER_H
