#include "elementlist.h"

ElementList::ElementList()
{

}

void ElementList::Push(my_unique_ptr<Element> item)
{
    if(!head){
        head=move(item);
    }
    else {
        item->next=move(head);
        head = move(item);
    }
}

void ElementList::Pop()
{
    if(!head) return;

    my_unique_ptr<Element> x=move(head->next);
    head = move(x);
}
