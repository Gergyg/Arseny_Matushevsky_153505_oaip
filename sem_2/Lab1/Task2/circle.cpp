#include "circle.h"

Circle::Circle(size_t size)
{
    m_size = size;

}

double Circle::FigureArea()
{
    return (m_size / 2) * (m_size / 2) * 3.14159265359;

}

double Circle::FigurePerimeter()
{
    return 2 * (m_size / 2) * 3.14159265359;
}

QRectF Circle::boundingRect() const
{
    return QRectF(QPoint(x_size_scene - m_size / 2, y_size_scene - m_size / 2),
                  QPoint(m_size / 2 + x_size_scene, m_size / 2 + y_size_scene));
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawEllipse(x_size_scene - m_size / 2, y_size_scene - m_size / 2, m_size, m_size);

}
