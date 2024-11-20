#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stream.h"
#include "devmode.h"
#include <QDebug>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabVisible(1, false);
    this->showMaximized();
    ui->BtnSave->setEnabled(false);

    PopulateSettings();

    //Connect Buttons to slots
    connect(ui->BtnConnect, &QPushButton::clicked, this, &MainWindow::connectButton);
    connect(ui->BtnDevmode, &QPushButton::clicked, this, &MainWindow::devButton);
    connect(ui->BtnSettings, &QPushButton::clicked, this, &MainWindow::settingButton);
    connect(ui->BtnBack, &QPushButton::clicked, this, &MainWindow::backButton);
    connect(ui->BtnSave, &QPushButton::clicked, this, &MainWindow::onSaveButtonClicked);

    //Connect Field Events
    connect(ui->CameraIp, &QLineEdit::textChanged, this, &MainWindow::onFieldChanged);
    connect(ui->CameraId, &QLineEdit::textChanged, this, &MainWindow::onFieldChanged);
    connect(ui->CameraPass, &QLineEdit::textChanged, this, &MainWindow::onFieldChanged);
    connect(ui->JetsonIp, &QLineEdit::textChanged, this, &MainWindow::onFieldChanged);
    connect(ui->JetsonPort, &QLineEdit::textEdited, this, &MainWindow::onFieldChanged);
    connect(ui->RadarIP, &QLineEdit::textEdited, this, &MainWindow::onFieldChanged);
    connect(ui->RadarPort, &QLineEdit::textEdited, this, &MainWindow::onFieldChanged);

    //Signals
    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::onTabCloseRequested);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectButton()
{
    Stream *stream = new Stream(&settingsManager, this);
    connect(stream, &Stream::statusUpdate, this, &MainWindow::updateStatusBar);
    ui->tabWidget->addTab(stream, "Stream");
    ui->tabWidget->setTabVisible(0, false);
    ui->tabWidget->setTabsClosable(true);
}

void MainWindow::devButton(){
    DevMode *devMode = new DevMode(&settingsManager, this);
    connect(devMode, &DevMode::statusUpdate, this, &MainWindow::updateStatusBar);
    ui->tabWidget->addTab(devMode, "Dev Mode");
    ui->tabWidget->setTabVisible(0, false);
    ui->tabWidget->setTabsClosable(true);
}

void MainWindow::settingButton()
{
    ui->tabWidget->setTabVisible(1, true);
    ui->tabWidget->setCurrentIndex(1);
    ui->tabWidget->setTabVisible(0,false);
}

void MainWindow::backButton()
{
    ui->tabWidget->setTabVisible(0, true);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->setTabVisible(1, false);
}

void MainWindow::onFieldChanged()
{
    ui->BtnSave->setEnabled(true);
}

void MainWindow::onSaveButtonClicked()
{
    QJsonObject settings = settingsManager.getSettings();
    settings["CameraIp"] = ui->CameraIp->text();
    settings["CameraId"] = ui->CameraId->text();
    settings["CameraPass"] = ui->CameraPass->text();
    settings["JetsonIp"] = ui->JetsonIp->text();
    settings["JetsonPort"] = ui->JetsonPort->text();
    settings["RadarIp"] = ui->RadarIP->text();
    settings["RadarPort"] = ui->RadarPort->text();

    settingsManager.setSettings(settings);
    settingsManager.saveSettings();
    ui->BtnSave->setEnabled(false);
    QMessageBox::information(this, "Settings Saved", "Changes saved successfully!");
}

void MainWindow::onTabCloseRequested(int index)
{
    ui->BtnConnect->setEnabled(false);
    ui->BtnDevmode->setEnabled(false);
    QWidget *tab = ui->tabWidget->widget(index);
    if (tab) {
        // Disconnect signals to prevent crashes
        disconnect(tab, nullptr, this, nullptr);

        ui->tabWidget->removeTab(index);
        tab->deleteLater(); // Schedule object deletion
    }

    // Restore default tab visibility
    ui->tabWidget->setTabVisible(0, true);
    ui->tabWidget->setTabsClosable(false);
    // Re-enable BtnConnect and BtnDevmode after 3 seconds
    QTimer::singleShot(3000, this, [this]() {
        ui->BtnConnect->setEnabled(true);
        ui->BtnDevmode->setEnabled(true);
    });
}

void MainWindow::PopulateSettings()
{
    QJsonObject settings = settingsManager.getSettings();
    ui->CameraIp->setText(settings["CameraIp"].toString());
    ui->CameraId->setText(settings["CameraId"].toString());
    ui->CameraPass->setText(settings["CameraPass"].toString());
    ui->JetsonIp->setText(settings["JetsonIp"].toString());
    ui->JetsonPort->setText(settings["JetsonPort"].toString());
    ui->RadarIP->setText(settings["RadarIp"].toString());
    ui->RadarPort->setText(settings["RadarPort"].toString());
}

void MainWindow::updateStatusBar(const QString &message)
{
    ui->statusBar->showMessage(message, 5000); // Message visible for 5 seconds
}
