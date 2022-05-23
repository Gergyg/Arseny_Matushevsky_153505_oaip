#include "hexagon.h"

Hexagon::Hexagon()
{

}

double Hexagon::FigureArea()
{
    return 6495.2;

}

double Hexagon::FigurePerimeter()
{
    return 300;
}

QRectF Hexagon::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(100,100));
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygonF polygon;
    polygon<<QPointF(50,0)<<QPointF(93.3,25)<<QPointF(93.3,75)<<QPointF(50,100)<<QPointF(6.7,75)<<QPointF(6.7,25);
    painter->drawPolygon(polygon);
}
