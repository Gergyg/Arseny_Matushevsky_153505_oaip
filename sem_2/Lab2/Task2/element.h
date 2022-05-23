#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element* next = nullptr;
    Element(char t, int i, int j);
    bool is_opening = false;
    char skobka;
    int str, stlb;
};

#endif // ELEMENT_H
