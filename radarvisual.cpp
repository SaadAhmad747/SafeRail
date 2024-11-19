#include "radarvisual.h"

RadarVisual::RadarVisual(QWidget *parent) : QWidget(parent){
    this->setStyleSheet("background-color: #F5F5F5"); // start color
}

void RadarVisual::paintEvent(QPaintEvent *){
    uint64_t diffDraw = GET_CUR_TIME_MILLI - lastDrawMs;
    if(diffDraw < UPDATE_DRAW_MS) return;
    lastDrawMs = GET_CUR_TIME_MILLI;

    painter = new QPainter(this);
    painter->eraseRect(rect());

    drawZones();
    // if(!showProperties.empty() && showProperties[3]){
    drawArcs();
    // }
    drawAxes();
    drawRadar();
    drawClusters();

    painter->end();
}

void RadarVisual::drawZones()
{
    uint8_t transp = 230;

    // Red Area
    float farDistance = 2000.0f;
    int farRadius = (farDistance / (float)gridStepM) * gridStepPx;
    QPainterPath farPath;
    farPath.moveTo(width() / 2, height());
    QRectF rectFar(width() / 2 - farRadius, height() - farRadius, farRadius * 2, farRadius * 2);
    farPath.arcTo(rectFar, 80, 20);

    QColor lightBlue(160, 210, 255, transp);
    QPen penZoneBlue = QPen(lightBlue, 1);
    painter->setPen(penZoneBlue);
    painter->setBrush(lightBlue);
    painter->drawPath(farPath);

    // Blue Area
    float nearDistance = farDistance / 2;
    int nearRadius = (nearDistance / (float)gridStepM) * gridStepPx;
    QPainterPath nearPath;
    nearPath.moveTo(width() / 2, height());
    QRectF rectNear(width() / 2 - nearRadius, height() - nearRadius, nearRadius * 2, nearRadius * 2);
    nearPath.arcTo(rectNear, 80, 20);

    QColor lightRed(255, 200, 200, transp);
    QPen penZoneRed = QPen(lightRed, 1);
    painter->setPen(penZoneRed);
    painter->setBrush(lightRed);
    painter->drawPath(nearPath);
}

void RadarVisual::drawArcs()
{
    QPen penArc = QPen(Qt::gray, 1);
    painter->setPen(penArc);
    // Draw lines at every 30 degrees from the radar center
    for (int angle = 0; angle <= 180; angle += 30) {
        if(angle == 90) continue;
        float angleRad = qDegreesToRadians(angle);

        // Calculate endpoint of the line
        int xEnd = width() / 2 + qCos(angleRad) * height();  // Adjust for horizontal direction
        int yEnd = height() - qSin(angleRad) * height();     // Adjust for vertical direction

        // Draw the line from radar center to calculated endpoint
        painter->drawLine(QLine(width() / 2, height(), xEnd, yEnd));
    }
}

void RadarVisual::drawAxes()
{
    QPen penAx = QPen(Qt::black, 1.5);
    painter->setPen(penAx);

    // Draw main axes
    painter->drawLine(QLine(0, height() - 1, width(), height() - 1)); // Horizontal axis
    // painter->drawLine(QLine(width() / 2, 0, width() / 2, height()));  // Vertical axis
    painter->drawLine(QLine(width() / 2 - 6, 0, width() / 2 - 6, height())); // Vertical line
    painter->drawLine(QLine(width() / 2 + 6, 0, width() / 2 + 6, height()));

    // Calculate grid step sizes
    gridStepM = minLeftM / sliceOneSide;
    gridStepPx = height() / (minLeftM / gridStepM);

    QPen penArc = QPen(Qt::gray, 1);
    painter->setPen(penArc);

    // Draw horizontal arcs and y-axis labels
    for (uint8_t i = 1; i <= sliceOneSide; i++) {
        float distanceM = gridStepM * i;
        int radiusPx = (distanceM / gridStepM) * gridStepPx;

        QRectF arcRect((width() / 2) - radiusPx, height() - radiusPx, radiusPx * 2, radiusPx * 2);
        painter->drawArc(arcRect, 0, 180 * 16);

        // Draw radial labels at intersection points
        for (int angle = 0; angle < 180; angle += 30) { // Radial lines at intervals (e.g., every 30 degrees)
            if(angle == 90) continue;
            float radian = qDegreesToRadians(static_cast<float>(angle));
            int xCoord = width() / 2 + radiusPx * std::cos(radian);
            int yCoord = height() - radiusPx * std::sin(radian);

            painter->save();
            painter->translate(xCoord, yCoord);
            painter->rotate(90 - angle);

            if (angle <= 90) {
                painter->drawText(QPoint(5, 0), QString::number(distanceM) + "m");
            } else {
                painter->drawText(QPoint(-35, 0), QString::number(distanceM) + "m"); // Adjust offset for readability
            }
            painter->restore();
        }
    }

    // Draw x-axis labels (now extend to ±2000m)
    // int steps = minLeftM / gridStepM; // Calculate how many steps for the x-axis labels
    // for (int i = -steps; i <= steps; i++) { // Cover both sides (left and right)
    //     float distanceM = i * gridStepM;
    //     int xCoord = width() / 2 + (distanceM / gridStepM) * gridStepPx;

    //     painter->drawText(QPoint(xCoord - 10, height() - 2), QString::number(std::abs(distanceM)) + "m");
    // }
}

void RadarVisual::drawRadar()
{
    QPen penRad = QPen(Qt::black, 1);
    painter->setPen(penRad);
    painter->setBrush(Qt::darkGray);

    if(gridStepPx <= 0) return;
    int wRad = gridStepPx * 0.5f;
    int hRad = gridStepPx * 0.15f;
    painter->drawRect(width() / 2 - wRad / 2, height() - hRad, wRad, hRad);
}

void RadarVisual::drawClusters() {
    // Define the bounds of the red zone
    int redZoneLeftX = width() / 2 - 6;  // Left line x-coordinate
    int redZoneRightX = width() / 2 + 6; // Right line x-coordinate

    for (const RadarCluster &cluster : clusters) {
        // Calculate cluster position in pixels
        int rangePx = (cluster.rangeM / gridStepM) * gridStepPx;

        float angleRad = qDegreesToRadians(cluster.angleDeg);
        int xCord = width() / 2 + rangePx * qSin(angleRad);
        int yCord = height() - rangePx * qCos(angleRad);

        // Check if the cluster is inside the red zone
        if (xCord >= redZoneLeftX && xCord <= redZoneRightX) {
            painter->setBrush(Qt::red); // Inside the red zone
        } else {
            painter->setBrush(Qt::yellow); // Outside the red zone
        }

        // Draw the cluster point
        painter->drawEllipse(QPoint(xCord, yCord), 5, 5);

        // Draw text information if any properties are enabled
        if (showProperties.empty()) {
            // Show range by default if no properties are selected
            QString textInfo = QString::number(cluster.rangeM);
            painter->setPen(Qt::black);
            painter->drawText(xCord + 2, yCord - 2, textInfo);
        }
        else {
            QString textInfo;
            if (showProperties[0]) textInfo += QString::number(cluster.rangeM);
            if (showProperties[1]) textInfo += ", " + QString::number(cluster.angleDeg);
            if (showProperties[2]) textInfo += ", " + QString::number(cluster.velocity);

            if (!textInfo.isEmpty()) {
                painter->setPen(Qt::black);
                painter->drawText(xCord + 2, yCord - 2, textInfo);
            }
        }
    }
    clusters.clear();
}
