#ifndef STACK_H
#define STACK_H
#include "element.h"

class Stack
{
public:
    Element* head = nullptr;
public:
    ~Stack();
    Stack();
    void Push(Element* item);
    void Pop();
};

#endif // STACK_H
