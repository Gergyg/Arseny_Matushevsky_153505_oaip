#ifndef QUEUE_H
#define QUEUE_H
#include "element.h"

class Queue
{
public:
    Element* head = nullptr;
    Element* tail = nullptr;
public:
    ~Queue();
    Queue();
    void Push(Element* item);
    void Pop();
};

#endif // QUEUE_H
