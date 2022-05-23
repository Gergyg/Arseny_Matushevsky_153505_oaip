#ifndef MY_UNIQUE_PTR_H
#define MY_UNIQUE_PTR_H

#include <stdexcept>
template <class T>
class my_unique_ptr
{
private:
    T * ptr = nullptr;

public:
    my_unique_ptr() : ptr(nullptr)
    {
    }

    my_unique_ptr(T * ptr) : ptr(ptr)
    {
    }

    my_unique_ptr(const my_unique_ptr & obj) = delete;
    my_unique_ptr& operator=(const my_unique_ptr & obj) = delete;

    my_unique_ptr(my_unique_ptr && dyingObj)
    {

        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(my_unique_ptr && dyingObj)
    {
        __cleanup__();


        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    explicit operator bool() const noexcept {
        if(ptr) return true;
        else return false;

    };

    T* operator->()
    {
        return this->ptr;
    }

    T& operator*()
    {
        return *(this->ptr);
    }

    ~my_unique_ptr()
    {
        __cleanup__();
    }

private:
    void __cleanup__()
    {
        if (ptr != nullptr)
            delete ptr;
    }
};

template <class T>
class my_unique_ptr<T[]>
{
private:
    T * ptr = nullptr;

public:
    my_unique_ptr() : ptr(nullptr)
    {
    }

    my_unique_ptr(T * ptr) : ptr(ptr)
    {
    }

    my_unique_ptr(const my_unique_ptr & obj) = delete;
    my_unique_ptr& operator=(const my_unique_ptr & obj) = delete;

    my_unique_ptr(my_unique_ptr && dyingObj)
    {
        __cleanup__();


        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    void operator=(my_unique_ptr && dyingObj)
    {
        __cleanup__();

        this->ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T* operator->()
    {
        return this->ptr;
    }

    T& operator*()
    {
        return *(this->ptr);
    }

    T& operator[](int index)
    {
        if(index < 0)
        {

            throw std::runtime_error("Negative index exception");
        }
        return this->ptr[index];
    }

    ~my_unique_ptr()
    {
        __cleanup__();
    }

private:
    void __cleanup__()
    {
        if (ptr != nullptr)
            delete[] ptr;
    }
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

template <typename T, typename... Args>
my_unique_ptr<T> make_unique(Args&&... args) {
    return my_unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif // MY_UNIQUE_PTR_H
