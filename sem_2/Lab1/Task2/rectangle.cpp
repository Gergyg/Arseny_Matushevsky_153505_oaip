#include "rectangle.h"

Rectangle::Rectangle(size_t size1, size_t size2) : m_size1(size1), m_size2(size2)
{

}

double Rectangle::FigureArea()
{
    return m_size1*m_size2;

}

double Rectangle::FigurePerimeter()
{
    return 2*(m_size1+m_size2);

}

QRectF Rectangle::boundingRect() const
{
    return QRectF(QPoint(0,0),
                  QPoint(m_size1,m_size2));
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawRect(0,0,m_size1,m_size2);
}

/*QPolygonF Rectangle::polygon() const
{
    QPolygonF polygon;
    polygon << QPointF(x_size_scene - m_size / 2, m_size / 4 + y_size_scene - m_size / 2)
            << QPointF(x_size_scene - m_size / 2, m_size * 3 / 4 + y_size_scene - m_size / 2)
            << QPointF(m_size + x_size_scene - m_size / 2, m_size * 3 / 4 + y_size_scene - m_size / 2)
            << QPointF(m_size + x_size_scene - m_size / 2, m_size / 4 + y_size_scene - m_size / 2);
    return polygon;
}*/
