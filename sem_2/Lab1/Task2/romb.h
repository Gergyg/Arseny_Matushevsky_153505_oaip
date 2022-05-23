#ifndef ROMB_H
#define ROMB_H
#include "figure.h"

class Romb : public Figure
{
public:
    Romb();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;


};

#endif // ROMB_H
