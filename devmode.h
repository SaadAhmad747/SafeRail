#ifndef DEVMODE_H
#define DEVMODE_H

#include "settingsmanager.h"
#include "streammanager.h"
#include "radarvisual.h"
#include "radardataprocessor.h"
#include "networkdatareader.h"
#include <QWidget>

namespace Ui {
class DevMode;
}

class DevMode : public QWidget
{
    Q_OBJECT

public:
    explicit DevMode(SettingsManager* settingsManager, QWidget *parent = nullptr);
    ~DevMode();
    void updateCheckBoxes();

private slots:
    void onConnectBtnClicked();
    void onProcessComplete(const QVector<RadarCluster> &processedClusters);

private:
    Ui::DevMode *ui;
    RadarVisual *vDraw;
    StreamManager* streamManager;
    NetworkDataReader *networkDataReader;
    RadarDataProcessor *radarDataProcessor;
    bool radarSwitch;

    void StartStreams();
    void onRadarBtnClicked();
};

#endif // DEVMODE_H
