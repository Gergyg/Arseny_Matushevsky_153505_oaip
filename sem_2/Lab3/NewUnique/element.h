#ifndef ELEMENT_H
#define ELEMENT_H
#include "my_unique_ptr.h"

class Element
{
public:
    my_unique_ptr<Element> next = nullptr;
    Element(char t, int i, int j);
    bool is_opening = false;
    char skobka;
    int str, stlb;
};

#endif // ELEMENT_H
