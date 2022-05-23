#include "star6.h"

Star6::Star6()
{

}

double Star6::FigureArea()
{
    return 1215.5;

}

double Star6::FigurePerimeter()
{
    return 335.2;
}


void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPolygon(drawStar(6));
}
