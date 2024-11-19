#ifndef STREAM_H
#define STREAM_H

#include "streammanager.h"
#include "settingsmanager.h"
#include "radarvisual.h"
#include "networkdatareader.h"
#include "radardataprocessor.h"
#include <QWidget>
#include <QRadioButton>

namespace Ui {
class Stream;
}

class Stream : public QWidget
{
    Q_OBJECT

public:
    explicit Stream(SettingsManager *settingsManager, QWidget *parent = nullptr);
    ~Stream();

private slots:
    void onTabChanged(int index);
    void onProcessComplete(const QVector<RadarCluster> &processedClusters);

private:
    Ui::Stream *ui;
    StreamManager *streamManager;
    RadarVisual *vDraw;
    NetworkDataReader *networkDataReader;
    RadarDataProcessor *radarDataProcessor;
    bool radarSwitch;

    void onRadarBtnClicked();
};

#endif // STREAM_H






// #ifndef STREAM_H
// #define STREAM_H

// #include <QWidget>
// #include <gst/gst.h>
// #include <gst/video/videooverlay.h>
// #include <settingsmanager.h>

// namespace Ui {
// class Stream;
// }

// class Stream : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit Stream(SettingsManager* settingsManager, QWidget *parent = nullptr);
//     ~Stream();

// private slots:
//     void OnRadioButtonToggled();


// private:
//     Ui::Stream *ui;
//     GstElement *pipelineOptical;
//     GstElement *pipelineThermal;
//     //fusedpipeline elements
//     GstElement *pipelineFused;
//     GstElement *pipelineInternal;
//     GstElement *tcpSrc;
//     GstElement *jpegDec;
//     GstElement *videoConvert;
//     GstElement *videoSink;
//     GstElement* CreatePipeline(const QString& channel);
//     GstElement* CreateFusedPipeline();

//     //camera strings
//     QString cameraIp;
//     QString cameraId;
//     QString cameraPass;
//     QString encodedPass;
//     QString jetsonIp;
//     QString jetsonPort;
//     SettingsManager* settingsManager;

//     void SetupAndStartOpticalPipeline();
//     void SetupAndStartThermalPipeline();
//     void SetupAndStartFusedPipeline();
//     void ShowBlackScreen();
// };

// #endif // STREAM_H
