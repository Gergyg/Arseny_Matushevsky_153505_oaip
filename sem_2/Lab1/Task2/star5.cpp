#include "star5.h"

Star5::Star5()
{

}



double Star5::FigureArea()
{
    return 1188.82;

}

double Star5::FigurePerimeter()
{
    return 314.6;
}

QPolygonF Star5::drawStar(int m_count_angle)
{
    QPolygonF polygon;
    double angleUnit = 6.283185307 / m_count_angle;
    double angleVertex = 4.71238898037;
    double angleCentralVertex = angleVertex;
    double a, size_central;
    double PI = 3.14159265359;
    double angle = (180 * (m_count_angle - 2)) / m_count_angle;
    a = 100 / (tan(angle / 2 / 180 * PI) + tan((180 - angle) / 180 * PI));
    size_central = a / cos(angle / 2 / 180 * PI);
    angleCentralVertex += (180 - angle) / 360 * PI;

    for(int i = 0; i < m_count_angle; ++i) {
        polygon << QPointF((cos(angleVertex) * 100 + 100) / 2 + x_size_scene - 50,
                           (sin(angleVertex) * 100 + 100) / 2 + y_size_scene - 50);
        polygon << QPointF((cos(angleCentralVertex) * size_central + 100) / 2 + x_size_scene - 50,
                           (sin(angleCentralVertex) * size_central + 100) / 2 + y_size_scene - 50);

        angleVertex += angleUnit;
        angleCentralVertex += angleUnit;
    }
    return polygon;

}

QRectF Star5::boundingRect() const
{
    return QRectF(QPoint(-50,0),
                  QPoint(100,100));
}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPolygon(drawStar(5));
}
