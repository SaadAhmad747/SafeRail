#include "settingsmanager.h"
#include <QDebug>

SettingsManager::SettingsManager(const QString& filename) : filename(filename) {
    QFile file(filename);
    if (!file.exists()) {
        createDefaultSettings(); //Create a File with empty fields if there is not any
    }
    loadSettings();
}

void SettingsManager::createDefaultSettings() {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonObject defaultSettings;
        defaultSettings["CameraIp"] = "";
        defaultSettings["CameraId"] = "";
        defaultSettings["CameraPass"] = "";
        defaultSettings["JetsonIp"] = "";
        defaultSettings["JetsonPort"] = "";
        defaultSettings["RadarIp"] = "";
        defaultSettings["RadarPort"] = "";

        QJsonDocument doc(defaultSettings);
        file.write(doc.toJson());
        file.close();
    }
}

QJsonObject SettingsManager::getSettings() const {
    return settingsJson;
}

void SettingsManager::setSettings(const QJsonObject& newSettings) {
    settingsJson = newSettings;
}

void SettingsManager::loadSettings() {
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        settingsJson = doc.object();
        file.close();
    } else {
        qWarning() << "Could not open settings file:" << file.errorString();
    }
}

void SettingsManager::saveSettings() {
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        QJsonDocument doc(settingsJson);
        file.write(doc.toJson());
        file.close();
    } else {
        qWarning() << "Could not save settings file:" << file.errorString();
    }
}
