#ifndef FIGURE_H
#define FIGURE_H
#include <QPoint>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsItem>

class Figure : public QGraphicsObject
{
public:
    virtual double FigureArea();
    virtual double FigurePerimeter();
    Figure();
protected:
    size_t x_size_scene = 0;
    size_t y_size_scene = 50;
};

#endif // FIGURE_H
