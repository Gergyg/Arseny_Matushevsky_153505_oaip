#ifndef VECTORLIB_H
#define VECTORLIB_H
#include <iostream>
#include <memory>
#include "memory.h"
#include <string>
template <typename T>
class VectorIterator : std::iterator<std::input_iterator_tag, T> {
private:
//    using iterator_category  = std::forward_iterator_tag;
//    using different_type  = std::ptrdiff_t;
//    using value_type  = T;
//    using reference = T&;
    using pointer = T*;

public:
    explicit VectorIterator(pointer p) : m_ptr(p) {};
    VectorIterator(const VectorIterator& it) : m_ptr(it.m_ptr) {};

    // bool comparison iterators
    friend bool operator !=(VectorIterator const &a, VectorIterator const &b)
    {return a.m_ptr != b.m_ptr;};
    friend bool operator ==(VectorIterator const &a, VectorIterator const &b)
    {return a.m_ptr == b.m_ptr;};

    //member access
    T& operator*() {return *m_ptr; };
    T* operator->() {return m_ptr; }

    // increment and decrement operators
    VectorIterator operator++(int) { VectorIterator<T> temp = *this; ++(*this); return temp;}
    VectorIterator operator--(int) { VectorIterator<T> temp = *this; --(*this); return temp;}
    VectorIterator& operator++() { m_ptr++; return *this;}
    VectorIterator& operator--() { m_ptr--; return *this;}
    VectorIterator operator+(int number) {VectorIterator<T> temp = *this; temp.m_ptr += number; return temp;}
    VectorIterator operator-(int number) {VectorIterator<T> temp = *this; temp.m_ptr -= number; return temp;}
    VectorIterator& operator+=(int number) {m_ptr += number; return *this;}
    VectorIterator& operator-=(int number) {m_ptr -= number; return *this;}


    //iterator - iterator
    friend int operator-(const VectorIterator& first, const VectorIterator& second) {
        return first.m_ptr - second.m_ptr;
    }
    //implicit conversion to const iterator
    operator VectorIterator<const T>() {return VectorIterator<const T>(m_ptr);}

private:
pointer m_ptr;
};


template<typename T>
class VectorReverseIterator : std::iterator<std::input_iterator_tag, T>{
private:
//    using iterator_category  = std::forward_iterator_tag;
//    using different_type  = std::ptrdiff_t;
//    using value_type  = T;
//    using reference  = T&;
    using pointer = T*;

public:
    explicit VectorReverseIterator(pointer p) : m_ptr(p) {};
    VectorReverseIterator(const VectorReverseIterator& it) : m_ptr(it.m_ptr) {};

    // bool comparison iterators
    friend bool operator !=(VectorReverseIterator const &a, VectorReverseIterator const &b)
    {return a.m_ptr != b.m_ptr;};
    friend bool operator ==(VectorReverseIterator const &a, VectorReverseIterator const &b)
    {return a.m_ptr == b.m_ptr;};

    //member access
    T& operator*() {return *m_ptr; };
    T* operator->() {return m_ptr; }

    // increment and decrement operators
    VectorReverseIterator operator--(int) { VectorReverseIterator<T> temp = *this; ++(*this); return temp;}
    VectorReverseIterator operator++(int) { VectorReverseIterator<T> temp = *this; --(*this); return temp;}
    VectorReverseIterator& operator++() { m_ptr--; return *this;}
    VectorReverseIterator& operator--() { m_ptr++; return *this;}
    VectorReverseIterator operator+(int number) {VectorReverseIterator<T> temp = *this; temp.m_ptr -= number; return temp;}
    VectorReverseIterator operator-(int number) {VectorReverseIterator<T> temp = *this; temp.m_ptr += number; return temp;}
    VectorReverseIterator& operator+=(int number) {m_ptr -= number; return *this;}
    VectorReverseIterator& operator-=(int number) {m_ptr += number; return *this;}

    //iterator - iterator
    friend int operator-(const VectorReverseIterator& first, const VectorReverseIterator& second) {
        return first.m_ptr - second.m_ptr;
    }
    //implicit conversion to const iterator
    explicit operator VectorReverseIterator<const T>() {return VectorReverseIterator<const T>(m_ptr);}

private:
    pointer m_ptr;
};


template<typename T>
struct RawMemory{
    T* buf = nullptr;
    size_t capacity = 0;

    static T* Allocate(size_t _n) {
        return static_cast<T*>(operator new(_n * sizeof(T)));
    }
    static void Deallocate(T* buf) {
        operator delete(buf);
    }

    RawMemory() = default;

    RawMemory(const RawMemory&) = delete;
    RawMemory& operator = (const RawMemory&) = delete;

    RawMemory(RawMemory&& other)  noexcept {
        Swap(other);
    }

    RawMemory& operator = (RawMemory&& other)  noexcept {
        Swap(other);
        return *this;
    }

    void Swap(RawMemory& other) {
        std::swap(capacity, other.capacity);
        std::swap(buf, other.buf);
    }


    RawMemory(size_t _n) : capacity(_n) {
        buf = Allocate(_n);
    }
    ~RawMemory() {
        Deallocate(buf);
    }

    T* operator +(size_t i) {
        return buf + i;
    }
    const T* operator +(size_t i) const {
        return buf + i;
    }
    T& operator[](size_t i) {
        return buf[i];
    }
    const T& operator[](size_t i) const {
        return buf[i];
    }
};

template<typename T>
class vector {


private:
    RawMemory<T> data;
    size_t m_size = 0;

    static void Construct(void* buf) {
        new (buf) T();
    }
    static void Construct(void* buf, const T& element) {
        new (buf) T(element);
    }
    static void Construct(void* buf, T&& element) {
        new (buf) T(std::move(element));
    }
    static void Destruct(T* buf) {
        buf->~T();
    }

public:
    using value_type = T;
    using const_reference = const value_type&;
    using reference = value_type&;
    using size_type = size_t;
    using iterator = VectorIterator<T>;
    using const_iterator = VectorIterator<const T>;
    using reverse_iterator = VectorReverseIterator<T>;
    using const_reverse_iterator = VectorReverseIterator<const T>;

    explicit vector() = default;

    explicit vector(size_type _n) : data(_n){
        uninitialized_value_construct_n(data.buf, _n);
        m_size = _n;
    }

    vector(const vector& other) : data(other.m_size){
        std::uninitialized_copy_n(other.data.buf, other.m_size, data.buf);
        m_size = other.m_size;
    }

    vector(std::initializer_list<T> _l) : data(_l.size()){
        std::uninitialized_copy_n(_l.begin(), _l.size(), data.buf);
        m_size = _l.size();

    }

    vector(vector&& other)  noexcept {
        Swap(other);
    }
    void Swap(vector& other) {
        data.Swap(other.data);
        std::swap(m_size, other.m_size);
    }

    vector& operator = (vector&& other)  noexcept {
        Swap(other);
        return *this;
    }

    vector& operator = (const vector& other) {
        if(data.capacity < other.m_size) {
            vector temp(other);
            Swap(temp);
        } else {
            for(size_t i = 0; i < m_size && i < other.m_size; ++i) {
                data[i] = other.data[i];
            }
            if(m_size > other.m_size) {
                destroy_n(data.buf + other.m_size,
                               m_size - other.m_size);
            } else if(m_size < other.m_size) {
                std::uninitialized_copy_n(other.data.buf + m_size,
                                          other.m_size - m_size,
                                          data.buf + m_size);
            }
           m_size = other.m_size;
        }
        return *this;
    }
    void resize(size_type _n) {
        reserve(_n);
        if(m_size < _n) {
            uninitialized_value_construct_n(data.buf + m_size, _n - m_size);
        } else if(m_size > _n) {
            destroy_n(data.buf, m_size - _n);
        }
        m_size = _n;
    }

    void resize(size_type _n, const value_type& _x) {
        reserve(_n);
        if(m_size < _n) {
            std::uninitialized_fill_n(data.buf, _n - m_size, _x);
        } else {
            destroy_n(data.buf + m_size, m_size - _n);
        }
        m_size = _n;
    }

    void reserve(size_type _n) {
        if(_n > data.capacity) {
            RawMemory<T> data2(_n);
            uninitialized_move_n(data.buf, m_size, data2.buf);
            destroy_n(data.buf, m_size);
            data.Swap(data2);
        }
    }

    void assign(std::initializer_list<value_type> _l) {
        auto it = this->begin();
        for(auto i : _l) {
            *it = i;
            it++;
        }
        m_size = _l.size();
    }

    void assign(size_type _n, const value_type& _x) {
        auto it = this->begin();
        for(int i = 0; i < _n; ++i, ++it) {
            *it = _x;
        }
        m_size = _n;
    }

    void push_back(const value_type& _x) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }
        new (data.buf + m_size) T(_x);
        m_size++;
    }

    void push_back(value_type&& _x) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }
        new (data.buf + m_size) T(std::move(_x));
        m_size++;
    }

     void pop_back() noexcept{
        destroy_at(data.buf + m_size - 1);
        m_size--;
    }

    template<typename... Args>
      reference emplace_back(Args&&... _args) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }

        auto ptr = new(data.buf + m_size) T(std::forward<Args>(_args)...);
        m_size++;
        return *ptr;
    }

    template<typename... Args>
      iterator emplace(const_iterator _position, Args&&... _args) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for(auto it = this->cbegin(); it != _position; it++, current_it++);
        for(auto it = this->end(); it != current_it; --it, --num) {
            *(it) = *(it - 1);
        }

        new(data.buf + num) T(std::forward<Args>(_args)...);
        m_size++;
        return current_it;
    }

     iterator insert(const_iterator _position, const value_type& _x) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for(auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for(auto it = this->end(); it != current_it; --it, --num) {
            *(it) = *(it - 1);
        }

        new(data.buf + num) T(_x);
        m_size++;
        return current_it;
    }

     iterator insert(const_iterator _position, value_type&& _x) {
        if(m_size == data.capacity) {
            reserve(m_size == 0 ? 1 : m_size * 2);
        }
        size_t num = m_size;

        auto current_it = this->begin();
        for(auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for(auto it = this->end(); it != current_it; --it, --num) {
            *it = *(it - 1);
        }
        new (data.buf + num) T(std::move(_x));
        m_size++;
        return current_it;
    }
     iterator insert(const_iterator _position, std::initializer_list<value_type> _l) {
        if(m_size + _l.size() > data.capacity) {
            reserve(data.capacity == 0 ? 1 : data.capacity * 2);
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for(auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for(auto it = this->end(); it != current_it; --it, --num) {
            *(it + _l.size() - 1) = *(it - 1);
        }
        for(int i : _l) {
            new (data.buf + num) T(i);
            num++;
        }
        m_size += _l.size();
        return current_it;
    }

     iterator insert(const_iterator _position, size_type _n, const value_type& _x) {
        if(m_size + _n > data.capacity) {
            reserve(data.capacity == 0 ? 1 : data.capacity * 2);
        }
        size_t num = m_size;
        auto current_it = this->begin();
        for(auto it = this->cbegin(); it != _position; it++, current_it++) {}
        for(auto it = this->end(); it != current_it; --it, --num) {
            *(it + _n - 1) = *(it - 1);
        }
        for(int i = 0; i < _n; ++i) {
            new (data.buf + num) T(_x);
            num++;
        }
        m_size += _n;
        return current_it;
    }


     iterator erase(const_iterator _position) {
        auto current_it = this->begin();
        for(auto cit = this->cbegin(); cit != _position; ++cit, ++current_it);
        for(auto it = current_it; it != this->end() - 1; ++it) {
            *(it) = *(it + 1);
        }
        m_size--;
        return current_it;
    }

     iterator erase(const_iterator _first, const_iterator _last) {
        size_type _n = _last - _first;
        auto current_it_first = this->begin();
        auto current_it_last = this->begin();
        for(auto cit = this->cbegin(); cit != _first; ++cit, ++current_it_first) {}
        for(auto cit = this->cbegin(); cit != _last; ++cit, ++current_it_last) {}
        std::cout << _n << std::endl;
        for(auto it = current_it_first; it != this->end(); ++it) {
            *(it) = *(it + _n);
        }
        m_size -= _n;
        return current_it_first;
    }

     reference front() noexcept{
        return data[0];
    }
     reference back() noexcept{
        return data[m_size - 1];
    }
     reference at(size_type _n) noexcept {
        if(_n < 0 || _n >= m_size) {
            throw new std::out_of_range("out");
        }
        return data[_n];
    }

     void clear() {
        m_size = 0;
    }

     bool empty() const noexcept {
        return m_size == 0;
    }
    size_t size() const noexcept {
        return m_size;
    }

    size_t max_size() const noexcept {
        size_t ret = -1;
        return ret;
    }
    ~vector() {
        destroy_n(data.buf, m_size);
    }

    reference operator [](int index){
        return data[index];
    }

    const_reference operator [](int index) const{
        return data[index];
    }


    iterator begin() noexcept{
        return iterator(data.buf);
    }
    iterator end() noexcept{
        return iterator(data.buf + m_size);
    }


    const_iterator cbegin() noexcept{
        return const_iterator(data.buf);
    }
    const_iterator cend() noexcept{
        return const_iterator(data.buf + m_size);
    }


     reverse_iterator rbegin() noexcept{
        return reverse_iterator(data.buf + m_size - 1);
    }
     reverse_iterator rend() noexcept{
        return reverse_iterator(data.buf - 1);
    }


     const_reverse_iterator crbegin() noexcept{
        return const_reverse_iterator(data.buf + m_size - 1);
    }
     const_reverse_iterator crend() noexcept{
        return const_reverse_iterator(data.buf - 1);
    }
};

template<typename T, typename U>
class pair {
public:
    T first;
    U second;
    pair() = default;
    pair(T value1, U value2) : first(value1), second(value2){}
    pair(const pair<T, U> &pair1) noexcept: first(pair1.first), second(pair1.second){}

    void swap(pair<T, U> &other) {
        T tempT = other.first;
        U tempU = other.second;
        other.first = first;
        other.second = second;
        first = tempT;
        second = tempU;
    }
    friend constexpr pair<T, U> make_pair(T&& value1, U&& value2);
    //  template<typename Y, typename X>

};
template<typename T, typename U>
pair<T, U> constexpr make_pair(T&& value1, U&& value2) {
    pair<T, U> temp{std::forward<T>(value1), std::forward<U>(value2)};
    return temp;
}



#endif // VECTORLIB_H
