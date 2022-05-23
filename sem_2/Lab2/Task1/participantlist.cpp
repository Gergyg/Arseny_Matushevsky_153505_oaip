#include "participantlist.h"
#include <QDebug>
ParticipantList::~ParticipantList()
{
    Participant* next = nullptr;
    while(head){
        next = head->next;
        delete head;
        head = next;
    }

}

ParticipantList::ParticipantList()
{
    
}

void ParticipantList::Add(Participant *item)
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
        Participant* old_head = head;
        head = head->next;
        if(head) head->previos = nullptr;
        delete old_head;
        return;
    }
    Participant* prev = head; Participant* current = head->next;

    for(int i=1; current; i++){
        if(i==index) {
            if(!current->next) tail = prev;
            else current->next->previos=prev;
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }



}

void ParticipantList::QSort_country(Participant* left, Participant* right)
{
    Participant* f=left;
    Participant* l=right;
    
    Participant* x=f;
    Participant* y=l;
    
    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }
    
    string middle = x->country;
    Participant* current;
    bool flag;
    do {
        while(f->country<middle) f=f->next;
        while(l->country>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

                string g;
                g=f->country;
                f->country=l->country;
                l->country=g;
                g=f->comandName;
                f->comandName=l->comandName;
                l->comandName=g;
                g=f->fio;
                f->fio=l->fio;
                l->fio=g;
                int h;
                h=f->number;
                f->number=l->number;
                l->number=h;
                h=f->age;
                f->age=l->age;
                l->age=h;
                h=f->height;
                f->height=l->height;
                l->height=h;
                h=f->weight;
                f->weight=l->weight;
                l->weight=h;

                f=f->next;
                l=l->previos;
                        

        }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_country(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_country(left,l);
}

void ParticipantList::QSort_comandName(Participant *left, Participant *right)
{

    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    string middle = x->comandName;
    Participant* current;
    bool flag;
    do {
        while(f->comandName<middle) f=f->next;
        while(l->comandName>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_comandName(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_comandName(left,l);
}

void ParticipantList::QSort_fio(Participant *left, Participant *right)
{
    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    string middle = x->fio;
    Participant* current;
    bool flag;
    do {
        while(f->fio<middle) f=f->next;
        while(l->fio>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_fio(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_fio(left,l);

}

void ParticipantList::QSort_number(Participant *left, Participant *right)
{
    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    int middle = x->number;
    Participant* current;
    bool flag;
    do {
        while(f->number<middle) f=f->next;
        while(l->number>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_number(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_number(left,l);

}

void ParticipantList::QSort_age(Participant *left, Participant *right)
{
    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    int middle = x->age;
    Participant* current;
    bool flag;
    do {
        while(f->age<middle) f=f->next;
        while(l->age>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_age(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_age(left,l);
}

void ParticipantList::QSort_height(Participant *left, Participant *right)
{
    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    int middle = x->height;
    Participant* current;
    bool flag;
    do {
        while(f->height<middle) f=f->next;
        while(l->height>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_height(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_height(left,l);
}

void ParticipantList::QSort_weight(Participant *left, Participant *right)
{
    Participant* f=left;
    Participant* l=right;

    Participant* x=f;
    Participant* y=l;

    while(x != y){
        x=x->next;
        if(x==y) break;
        y=y->previos;
    }

    int middle = x->weight;
    Participant* current;
    bool flag;
    do {
        while(f->weight<middle) f=f->next;
        while(l->weight>middle) l=l->previos;
        flag=false;
        current = f;
        while(current){
            if(current==l) flag = true;
            current=current->next;
        }
        if(flag){

            string g;
            g=f->country;
            f->country=l->country;
            l->country=g;
            g=f->comandName;
            f->comandName=l->comandName;
            l->comandName=g;
            g=f->fio;
            f->fio=l->fio;
            l->fio=g;
            int h;
            h=f->number;
            f->number=l->number;
            l->number=h;
            h=f->age;
            f->age=l->age;
            l->age=h;
            h=f->height;
            f->height=l->height;
            l->height=h;
            h=f->weight;
            f->weight=l->weight;
            l->weight=h;

            f=f->next;
            l=l->previos;


    }
        flag=false;
        if(f) {
            current = f->next;
            while(current){
                if(current==l) flag = true;
                current=current->next;
            }

        }

    } while(flag);

    flag=false;
    if(f){
        current = f->next;
        while(current){
            if(current==right) flag = true;
            current=current->next;
        }

    }
    if(flag)
        QSort_weight(f,right);

    flag=false;
    current = left->next;
    while(current){
        if(current==l) flag = true;
        current=current->next;
    }
    if(flag)
        QSort_weight(left,l);
}
