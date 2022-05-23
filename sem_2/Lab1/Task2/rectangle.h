#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QGraphicsRectItem>

#include "mainwindow.h"
class Rectangle : public Figure
{

public:
    Rectangle(size_t size1, size_t size2);
    double FigureArea() override;
    double FigurePerimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
protected:
    size_t m_size1;
    size_t m_size2;
};

#endif // RECTANGLE_H
