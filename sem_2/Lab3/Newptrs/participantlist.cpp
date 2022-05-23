#include "participantlist.h"
#include <QDebug>
/*ParticipantList::~ParticipantList()
{
    Participant* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}*/

ParticipantList::ParticipantList()
{

}

void ParticipantList::Add(my_shared_ptr<Participant> item)
{
    if(!head){
        head=item;
    }
    else {
        tail->next=item;
        item->previos=tail;
    }
    tail=item;

}

void ParticipantList::Remove(int index)
{
    if(!head) return;
    if(index == 0){
        if(head->next) head = head->next;
        else head.~my_shared_ptr();
        return;
    }
        my_shared_ptr<Participant> prev = head;

        my_shared_ptr<Participant> current = head->next;

        for(int i=1; current; i++){
            if(i==index) {
                if(!current->next) tail = prev;
                else {
                     current->next->previos=prev;
                     prev->next = current->next;
                }
                return;
            }
            prev = current;
            if(current->next) current = current->next;
            else {
                tail = prev;
                break;
            }
        }




}
