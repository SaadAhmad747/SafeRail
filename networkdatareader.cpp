#include "networkdatareader.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

NetworkDataReader::NetworkDataReader(SettingsManager *settingsManager, QObject *parent) : QObject(parent)
    , socket(new QTcpSocket(this))
    , settingsManager(settingsManager)
{
    QJsonObject settings = settingsManager->getSettings();
    RadarIp = settings["RadarIp"].toString();
    RadarPort = settings["RadarPort"].toString();
}

NetworkDataReader::~NetworkDataReader()
{
    if (socket->state() == QAbstractSocket::ConnectedState) {
        socket->disconnectFromHost();
        if (socket->state() != QAbstractSocket::UnconnectedState) {
            socket->waitForDisconnected(1000); // Wait briefly for disconnection
        }
    }
    // Explicitly disconnect signals
    disconnect(socket, &QTcpSocket::readyRead, this, &NetworkDataReader::onReadyRead);
}

void NetworkDataReader::start()
{
    socket->connectToHost(RadarIp, RadarPort.toInt());
    connect(socket, &QTcpSocket::connected, this, [this]() {
        emit connectionStatusChanged("Connected to Radar");
    });
    connect(socket, &QTcpSocket::disconnected, this, [this]() {
        emit connectionStatusChanged("Disconnected from Radar");
    });
    connect(socket, &QTcpSocket::errorOccurred, this, [this](QAbstractSocket::SocketError socketError) {
        Q_UNUSED(socketError);
        emit connectionErrorOccurred("Connection Error: " + socket->errorString());
    });
    connect(socket, &QTcpSocket::readyRead, this, &NetworkDataReader::onReadyRead);
}

void NetworkDataReader::stop()
{
    socket->disconnectFromHost();
    emit connectionStatusChanged("Radar connection stopped");
}

void NetworkDataReader::onReadyRead()
{
    // Read all available data from the socket
    QByteArray data = socket->readAll();
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON parse error:" << parseError.errorString();
        return;  // Return if JSON is malformed
    }

    QVector<RadarCluster> clusterList;
    // Check if the incoming data is an array of clusters
    if (doc.isArray()) {
        QJsonArray array = doc.array();
        for (int i = 0; i < array.size(); ++i) {
            QJsonObject obj = array.at(i).toObject();
            RadarCluster cluster;
            cluster.rangeM = obj["range"].toDouble();
            cluster.angleDeg = obj["angle"].toDouble();
            cluster.velocity = obj["velocity"].toDouble();
            clusterList.append(cluster);
        }
    }
    // If it's a single object, process it as a single cluster packet
    else if (doc.isObject()) {
        QJsonObject obj = doc.object();
        RadarCluster cluster;
        cluster.rangeM = obj["range"].toDouble();
        cluster.angleDeg = obj["angle"].toDouble();
        cluster.velocity = obj["velocity"].toDouble();
        clusterList.append(cluster);
    }
    // Emit the list of clusters
    emit dataReady(clusterList);
}
