#ifndef ELEMENT_H
#define ELEMENT_H


class Element
{
public:
    Element* next = nullptr;
    Element(char t);
    char elem;
};

#endif // ELEMENT_H
