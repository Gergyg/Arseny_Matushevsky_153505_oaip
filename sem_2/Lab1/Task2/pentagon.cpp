#include "pentagon.h"

Pentagon::Pentagon()
{

}
double Pentagon::FigureArea()
{
    return 1188.82;

}

double Pentagon::FigurePerimeter()
{
    return 314.6;
}

QRectF Pentagon::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(100,100));
}

void Pentagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygonF polygon;
    polygon<<QPointF(50,0)<<QPointF(98.9,39.6)<<QPointF(75,93.3)<<QPointF(25,93.3)<<QPointF(1.1,39.6);
    painter->drawPolygon(polygon);
}
