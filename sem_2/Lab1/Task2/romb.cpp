#include "romb.h"
#include <QPolygonF>
Romb::Romb()
{

}

double Romb::FigureArea()
{
    return 4800;

}

double Romb::FigurePerimeter()
{
    return 288.4441;

}

QRectF Romb::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(80,120));
}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygonF polygon;
    polygon<<QPointF(40,0)<<QPointF(0,60)<<QPointF(40,120)<<QPointF(80,60);
    painter->drawPolygon(polygon);
}
