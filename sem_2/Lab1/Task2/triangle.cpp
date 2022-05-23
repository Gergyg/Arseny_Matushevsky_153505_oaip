#include "triangle.h"

triangle::triangle()
{

}

QRectF triangle::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(100,100));
}

void triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygonF polygon;
    polygon<<QPointF(50,0)<<QPointF(93.3,75)<<QPointF(6.7,75);
    painter->drawPolygon(polygon);
}
