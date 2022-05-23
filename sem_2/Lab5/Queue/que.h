#ifndef QUE_H
#define QUE_H

#include <memory>
#include <iostream>

using namespace std;

template <class Tp>
struct Node
{
    Tp data;
    shared_ptr<Node> next;

    Node()
    {
        next = NULL;
    }
};

template <class Tp>
class Que
{
public:
    Que()
    {
        shared_ptr<Node <Tp>> p(new Node<Tp>);
        head = tail = p;
        s = 0;
    }

    Que(const Que& other) {
        shared_ptr<Node<int>> temp = other.head;
        while(temp != nullptr) {
            this->push(temp->data);
            temp = temp->next;
        }
    }

    inline void push(const Tp &x)
    {
        shared_ptr<Node <Tp>> p(new Node<Tp>);

        p->data = x;

        tail->next = p;
        tail = p;

        s++;
    }

    inline void pop()
    {
        shared_ptr<Node <Tp>> p = head->next;

        head->next = p->next;

        if (tail == p)
            tail = head;

        s--;
    }

    template<typename... Args>
    void emplace(Args&&... args) {
        shared_ptr<Node<Tp>> temp(new Node<Tp>);
        Tp obj(std::forward<Args>(args)...);
        temp->data = std::move(obj);
        temp->next = nullptr;
        temp->prev = tail;

        if(tail != nullptr) {
            tail->next = temp;
        }

        if(s == 0) {
            head = temp;
        }

        tail = temp;
        s++;
    }

    inline Tp front() const
    {
        return head->next->data;
    }

    inline Tp back() const
    {
        return tail->data;
    }

    inline int size() const
    {
        return s;
    }

    inline bool empty() const
    {
        return !s;
    }


protected:
    shared_ptr<Node <Tp>> head;
    shared_ptr<Node <Tp>> tail;
    int s;
};

#endif // QUE_H
