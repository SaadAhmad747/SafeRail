#include "devmode.h"
#include "ui_devmode.h"

DevMode::DevMode(SettingsManager *settingsManager, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DevMode)
    , streamManager (new StreamManager(settingsManager))
    , networkDataReader(new NetworkDataReader(settingsManager, this))
    , radarDataProcessor(new RadarDataProcessor(this))
{
    ui->setupUi(this);
    //Radar Visual
    vDraw = new RadarVisual(this);
    ui->sAVisual->setWidget(vDraw);
    ui->RadarBtn->setDisabled(true);

    //Radar Connections
    connect(ui->RadarBtn, &QPushButton::clicked, this, &DevMode::onRadarBtnClicked);
    connect(ui->NetworkButton, &QPushButton::clicked, this, &DevMode::onConnectBtnClicked);
    connect(networkDataReader, &NetworkDataReader::dataReady, radarDataProcessor, &RadarDataProcessor::storeData);
    connect(radarDataProcessor, &RadarDataProcessor::clustersProcessed, this, &DevMode::onProcessComplete);
    connect(networkDataReader, &NetworkDataReader::connectionStatusChanged, this, &DevMode::statusUpdate);
    connect(networkDataReader, &NetworkDataReader::connectionErrorOccurred, this, &DevMode::statusUpdate);


    //delete this later
    ui->lZoom->hide();
    ui->hSZoom->hide();

    StartStreams(); // start videos
}

DevMode::~DevMode()
{
    radarDataProcessor->stopProcess();
    delete radarDataProcessor;
    delete networkDataReader;
    delete streamManager;
    delete vDraw;
    delete ui;
}
/**********************************Stream Code*******************************************/
void DevMode::StartStreams(){
    streamManager->SetupAndStartFusedPipeline(ui->FuseFeed);
    streamManager->SetupAndStartOpticalPipeline(ui->OpticFeed);
    streamManager->SetupAndStartThermalPipeline(ui->ThermalFeed);
}

/**********************************Radar Code*******************************************/
void DevMode::onConnectBtnClicked()
{
    networkDataReader->start();
    ui->RadarBtn->setEnabled(true);
}

void DevMode::onRadarBtnClicked()
{
    if(!radarSwitch){
        ui->RadarLabel->setText("On");
        ui->RadarLabel->setStyleSheet("background-color: lightgreen");
        radarDataProcessor->processRadarData();
        radarSwitch = true;
    }
    else if(radarSwitch){
        ui->RadarLabel->setText("Off");
        ui->RadarLabel->setStyleSheet("background-color: red");
        radarDataProcessor->stopProcess();
        networkDataReader->stop();
        radarSwitch = false;
    }
}

void DevMode::updateCheckBoxes()
{
    int noOfCheckBoxes = ui->gridProps->rowCount();
    vDraw->showProperties.resize(noOfCheckBoxes);
    for(int i = 0; i < noOfCheckBoxes; i++){
        QCheckBox* cb = qobject_cast<QCheckBox*>(ui->gridProps->itemAtPosition(i, 0 )->widget());
        vDraw->showProperties[i] = cb->isChecked();
    }
}

void DevMode::onProcessComplete(const QVector<RadarCluster> &processedClusters)
{
    updateCheckBoxes();
    vDraw->clusters.append(processedClusters); // Update the visual component with processed data
    vDraw->update(); // Refresh the visual representation
}
