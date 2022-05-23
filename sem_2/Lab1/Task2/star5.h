#ifndef STAR5_H
#define STAR5_H
#include "figure.h"

class Star5 : public Figure
{
public:
    Star5();
    virtual double FigureArea() override;
    virtual double FigurePerimeter() override;
    QPolygonF drawStar(int m_count_angle);
protected:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*, QWidget*) override;
};

#endif // STAR5_H
