#include "star8.h"

Star8::Star8()
{

}
double Star8::FigureArea()
{
    return 1256.21;

}

double Star8::FigurePerimeter()
{
    return 356.12;
}


void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{

    painter->drawPolygon(drawStar(8));
}
