#include "radardataprocessor.h"
#include <QtConcurrent>
#include <QThread>

RadarDataProcessor::RadarDataProcessor(QObject *parent) : QObject(parent) {}

void RadarDataProcessor::storeData(const QVector<RadarCluster> &clusters)
{
    clustersFromSource.append(clusters);
}

void RadarDataProcessor::processRadarData()
{
    inProcess = true;
    QtConcurrent::run([=]()
                      {
                          while (inProcess) {
                              if (!clustersFromSource.isEmpty()) {
                                  QVector<RadarCluster> processedClusters = filterClusters(clustersFromSource);

                                  emit clustersProcessed(processedClusters); // Emit batch of clusters
                                  clustersFromSource.clear(); // Clear processed data
                              }
                              QThread::msleep(100); // Small delay to prevent high CPU usage
                          }
                      });
}


void RadarDataProcessor::stopProcess()
{
    inProcess = false;
}

QVector<RadarCluster> RadarDataProcessor::filterClusters(const QVector<RadarCluster> &clusters)
{
    QVector<RadarCluster> filteredClusters;

    // Example filter: only include clusters within a certain range
    for (const RadarCluster &cluster : clusters) {
        if (cluster.rangeM > 100.0) { // Only keep clusters less than 100 meters
            filteredClusters.append(cluster);
        }
    }

    return filteredClusters;
}
