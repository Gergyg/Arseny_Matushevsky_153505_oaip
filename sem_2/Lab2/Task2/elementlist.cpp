#include "elementlist.h"

ElementList::~ElementList()
{
    Element* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}

ElementList::ElementList()
{

}

void ElementList::Push(Element *item)
{
    if(!head){
        head=item;
    }
    else {
        item->next=head;
        head = item;
    }
}

void ElementList::Pop()
{
    if(!head) return;

    Element* x=head->next;
    delete head;
    head = x;
}
