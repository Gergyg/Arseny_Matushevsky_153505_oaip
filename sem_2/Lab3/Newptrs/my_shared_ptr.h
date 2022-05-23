#ifndef MY_SHARED_PTR_H
#define MY_SHARED_PTR_H
#include <iostream>
#include <QDebug>
typedef unsigned int uint;
template <typename U>
struct ControlBlock {
    size_t shared_count;
    size_t weak_count;
    U* object;
    template <typename... Args>
    ControlBlock(size_t shared_count, size_t weak_count, Args&&... args) : shared_count(shared_count), weak_count(weak_count), object(args...) {} ;
};

template <typename T>
typename std::remove_reference<T>::type&& move(T&& arg)
{
  return static_cast<typename std::remove_reference<T>::type&&>(arg);
}

template<typename T> void myswap(T& t1, T& t2) {
    T temp = move(t1);
    t1 = move(t2);
    t2 = move(temp);
}


template<class T>
class my_shared_ptr{
private:
    T* ptr = nullptr;
    ControlBlock<T>* cptr = nullptr;



    template <typename U>
    friend class my_weak_ptr;



    template <typename U, typename... Args>
    friend my_shared_ptr<U> make_shared(Args&&... args);

    my_shared_ptr(ControlBlock<T>* ptr): cptr(ptr), ptr(ptr->object) {}


public:
    my_shared_ptr() {}
    explicit my_shared_ptr(T* ptr):
        cptr(new ControlBlock<T>{1,0,ptr}), ptr(ptr) {}

    my_shared_ptr(const my_shared_ptr& other) :
        ptr(other.ptr), cptr(other.cptr) {
        ++cptr->shared_count;
        //++cptr->weak_count;
    }

    my_shared_ptr(my_shared_ptr&& other):
        ptr(other.ptr), cptr(other.cptr){
        other.ptr=nullptr;
        other.cptr=nullptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }

    my_shared_ptr& operator=(const my_shared_ptr& other) {
        ptr = other.ptr;
        cptr = other.cptr;
        ++cptr->shared_count;
        //++cptr->weak_count;
        return *this;
    }


    my_shared_ptr& operator= (my_shared_ptr&& other) noexcept{
        ptr = other.ptr;
        cptr = other.cptr;
        other.ptr=nullptr;
        other.cptr=nullptr;
    }

    explicit operator bool() const noexcept {
        if(ptr) return true;
        else return false;

    };

    size_t use_count() const {
          if(cptr->shared_count != nullptr) {
              return cptr->shared_count;
          } else {
              return 0;
          }
    }

    ~my_shared_ptr() {

        if(!cptr) return;
        --cptr->shared_count;
        if(cptr->shared_count==0 && cptr->weak_count==0){
            delete cptr;
            return;
        }
        if(cptr->shared_count ==0) {
            cptr->object->~T();
        }
    }
};


template <typename T>
class my_weak_ptr
{
private:
    ControlBlock<T>* cptr = nullptr;

public:
    my_weak_ptr() {}
    my_weak_ptr(const my_shared_ptr<T>& p): cptr(p.cptr) {++cptr->weak_count;}

    bool expired() const {
        return cptr->shared_count == 0;
    }

    my_weak_ptr& operator=(my_shared_ptr<T>& optr) {
        //ptr = optr.ptr;
        cptr = optr.cptr;
        ++cptr->weak_count;

        return *this;
    }

    my_shared_ptr<T> lock() const {
        return my_shared_ptr<T>(cptr);
    }

    size_t use_count() const noexcept {
        return cptr->weak_count;
    }

    ~my_weak_ptr() {
        if(!cptr) return;
        --cptr->weak_count;

        if(cptr->weak_count==0 && cptr->shared_count == 0) {
            delete cptr;

        }
    }
};



template<typename U, typename... Args>
my_shared_ptr<U> make_shared(Args &&... args) {
    auto ptr = new ControlBlock<U>(1, 0, std::forward<Args>(args)...);
    return my_shared_ptr<U>(ptr);
}

#endif // MY_SHARED_PTR_H
