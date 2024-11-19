#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

#include <QLineEdit>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QString>

class SettingsManager {
public:
    SettingsManager(const QString& filename = "Settings.json");
    QJsonObject getSettings() const;
    void setSettings(const QJsonObject& newSettings);
    void loadSettings();
    void saveSettings();

private:
    QString filename;
    QJsonObject settingsJson;

    void createDefaultSettings();
};

#endif // SETTINGSMANAGER_H
