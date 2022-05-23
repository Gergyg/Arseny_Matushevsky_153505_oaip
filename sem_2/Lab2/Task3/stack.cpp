#include "stack.h"

Stack::~Stack()
{
    Element* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}

Stack::Stack()
{

}

void Stack::Push(Element *item)
{
    if(!head){
        head=item;
    }
    else {
        item->next=head;
        head = item;
    }
}

void Stack::Pop()
{
    if(!head) return;
    Element* old_head = head;
    head = head->next;
    delete old_head;
    return;
}
