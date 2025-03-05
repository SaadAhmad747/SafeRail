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
    connect(networkDataReader, &NetworkDataReader::connectionStatusChanged, this, &Stream::statusUpdate);
    connect(networkDataReader, &NetworkDataReader::connectionErrorOccurred, this, &Stream::statusUpdate);

    onTabChanged(0); //set Fused Tab as Default
}

Stream::~Stream()
{
    radarDataProcessor->stopProcess();
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
