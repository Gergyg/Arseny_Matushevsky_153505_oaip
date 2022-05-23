#ifndef PENTAGON_H
#define PENTAGON_H
#include "figure.h"

class Pentagon : public Figure
{
public:
    Pentagon();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // PENTAGON_H
