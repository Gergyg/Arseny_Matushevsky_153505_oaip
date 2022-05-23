#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H
#include "element.h"

class ElementList
{
public:
    Element* head = nullptr;
public:
    ~ElementList();
    ElementList();
    void Push(Element* item);
    void Pop();
};

#endif // ELEMENTLIST_H
