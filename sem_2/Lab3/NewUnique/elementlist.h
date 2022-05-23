#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H
#include "element.h"
#include "my_unique_ptr.h"
class ElementList
{
public:
    my_unique_ptr<Element> head = nullptr;
public:
    ElementList();
    void Push(my_unique_ptr<Element> item);
    void Pop();
};

#endif // ELEMENTLIST_H
