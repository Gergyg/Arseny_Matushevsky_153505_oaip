#ifndef FINALSTACK_H
#define FINALSTACK_H
#include "finalelement.h"

class finalStack
{
public:
    finalElement* head = nullptr;
public:
    ~finalStack();
    finalStack();
    void Push(finalElement* item);
    void Pop();
};

#endif // FINALSTACK_H
