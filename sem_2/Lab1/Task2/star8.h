#ifndef STAR8_H
#define STAR8_H
#include "star5.h"

class Star8 : public Star5
{
public:
    Star8();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // STAR8_H
