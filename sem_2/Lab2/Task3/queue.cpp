#include "queue.h"

Queue::~Queue()
{
    Element* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}

Queue::Queue()
{

}

void Queue::Push(Element *item)
{
    if(!tail){
        tail=item;
        head=item;
    }
    else {
        tail->next=item;
        tail=item;
    }

}

void Queue::Pop()
{
    if(!head) return;

    Element* x=head->next;
    delete head;
    head = x;
}
