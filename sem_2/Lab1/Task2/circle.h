#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"

class Circle : public Figure
{
public:
    Circle(size_t size);
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
protected:
    size_t m_size;
};

#endif // CIRCLE_H
