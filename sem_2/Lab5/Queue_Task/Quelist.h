#ifndef QUELIST_H
#define QUELIST_H
#include "Que.h"
template <class Tp>
class Quelist : public Que<Tp>
{
public:
    Quelist() = default;

    void Add(const Tp& x){
        shared_ptr<Node <Tp>> item(new Node<Tp>);
        item->data = x;

        if(this->s==0){
            this->head = item;
            this->tail = item;
        }
        else {
            this->tail->next = item;
            item->prev = this->tail;
            this->tail = item;
        }
        this->s++;
    }

    void Remove(int index){
        if(!this->head) return;
        if(index == 0){
            if(this->head->next) this->head = this->head->next;
            else this->head.~my_shared_ptr();
            return;
        }
            shared_ptr<Node <Tp>> previo = this->head;

            shared_ptr<Node <Tp>> current = this->head->next;

            for(int i=1; current; i++){
                if(i==index) {
                    if(!current->next) this->tail = previo;
                    else {
                         current->next->prev=previo;
                         previo->next = current->next;
                    }
                    return;
                }
                previo = current;
                if(current->next) current = current->next;
                else {
                    this->tail = previo;
                    break;
                }
            }
    }

};
#endif // QUELIST_H
