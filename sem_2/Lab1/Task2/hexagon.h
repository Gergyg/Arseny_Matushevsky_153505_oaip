#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // HEXAGON_H
