#include "finalstack.h"

finalStack::~finalStack()
{
    finalElement* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}

finalStack::finalStack()
{

}

void finalStack::Push(finalElement *item)
{
    if(!head){
        head=item;
    }
    else {
        item->next=head;
        head = item;
    }

}

void finalStack::Pop()
{
    if(!head) return;
    finalElement* old_head = head;
    head = head->next;
    delete old_head;
    return;

}
