#ifndef NETWORKDATAREADER_H
#define NETWORKDATAREADER_H

#include "settingsmanager.h"
#include <QTcpSocket>
#include <QVector>
#include "entity.h"

class NetworkDataReader : public QObject {
    Q_OBJECT
public:
    explicit NetworkDataReader(SettingsManager* settingsManager,QObject *parent = nullptr);
    ~NetworkDataReader();
    void start();
    void stop();

signals:
    void dataReady(const QVector<RadarCluster>& clusters);
    void connectionStatusChanged(const QString &status);
    void connectionErrorOccurred(const QString &error);

private slots:
    void onReadyRead();

private:
    QTcpSocket *socket;
    SettingsManager* settingsManager;
    QString RadarIp;
    QString RadarPort;

};

#endif // NETWORKDATAREADER_H
