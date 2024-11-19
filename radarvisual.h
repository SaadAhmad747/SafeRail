#ifndef RADARVISUAL_H
#define RADARVISUAL_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QResizeEvent>
#include "entity.h"

class RadarVisual : public QWidget{

public:
    RadarVisual(QWidget *parent = nullptr);
    QVector<RadarCluster> clusters;
    std::vector<bool> showProperties;

private:
    uint64_t lastDrawMs = 0;

    QPainter *painter;

    // NOTE: Config grid
    int sliceOneSide   = 5; // parts
    int minLeftM        = 2000; // meters
    int gridStepPx      = 0;
    float gridStepM     = 0.0f;

    void paintEvent(QPaintEvent *) override;

    void drawZones();
    void drawAxes();
    void drawRadar();
    void drawClusters();
    void drawArcs();
};

#endif // RADARVISUAL_H
