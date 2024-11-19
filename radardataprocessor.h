#ifndef RADARDATAPROCESSOR_H
#define RADARDATAPROCESSOR_H

#include <QObject>
#include <QVector>
#include "entity.h"

class RadarDataProcessor : public QObject {
    Q_OBJECT
public:
    explicit RadarDataProcessor(QObject *parent = nullptr);
    void processRadarData();
    void stopProcess();

public slots:
    void storeData(const QVector<RadarCluster> &clusters);

signals:
    void clusterProcessed(const RadarCluster &cluster);
    void clustersProcessed(const QVector<RadarCluster>& clusters);

private:
    QVector<RadarCluster> filterClusters(const QVector<RadarCluster> &clusters);

    QVector<RadarCluster> clustersFromSource;
    bool inProcess;
};

#endif // RADARDATAPROCESSOR_H
