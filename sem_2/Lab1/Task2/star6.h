#ifndef STAR6_H
#define STAR6_H
#include "star5.h"

class Star6 : public Star5
{
public:
    Star6();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // STAR6_H
