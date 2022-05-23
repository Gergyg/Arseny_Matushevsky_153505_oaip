#include "element.h"

Element::Element(char t, int i, int j)
{
    skobka = t;
    if(t=='[' || t=='{' || t=='(') {
        is_opening = true;
    }

    str=i;
    stlb=j;
}
