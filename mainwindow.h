#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "settingsmanager.h"
#include <QMainWindow>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateStatusBar(const QString &message);

private slots:
    void connectButton();
    void devButton();
    void settingButton();
    void backButton();
    void onFieldChanged();
    void onSaveButtonClicked();
    void onTabCloseRequested(int index);

private:
    Ui::MainWindow *ui;
    SettingsManager settingsManager;
    QString cameraIp;
    QString cameraId;
    QString cameraPass;

    void PopulateSettings();
};

#endif // MAINWINDOW_H
