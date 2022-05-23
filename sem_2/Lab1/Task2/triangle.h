#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "figure.h"

class triangle : public Figure
{
public:
    triangle();
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // TRIANGLE_H
