#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <stack>
#include <algorithm>

template<typename T>
class HashTable {
private:
    static const size_t default_size = 1;
    constexpr static const double rehash_size = 0.8;

    std::stack<T> *Array;
    size_t size;
    size_t capacity;

public:
    HashTable() {
        capacity = default_size;
        size = 0;
        Array = new std::stack<T>[capacity];
    }

    ~HashTable(){
        delete[] Array;
    }

    int HashFunc(int k, int n) {
        k = abs(k);
        return floor(n * fmod(k * 0.618033, 1));
    }

    void Resize() {
        size_t previos_size = capacity;
        capacity *= 2;
        size = 0;

        auto Array2 = new std::stack<T>[capacity];
        std::swap(Array, Array2);

        for(int i=0; i < previos_size; i++){

            while( !Array2[i].empty() ){
                Add( Array2[i].top() );
                Array2[i].pop();
            }

        }

        delete[] Array2;
    }

    bool Find(const T& value) {
        int h = HashFunc(value, capacity);
        std::stack<T> temp = Array[h];

        while( !temp.empty() ) {
            if(temp.top() == value) {
                return true;
            }
            temp.pop();
        }
    }

    bool Remove(const T& value) {
        int h = HashFunc(value, capacity);
        std::stack<T> temp = Array[h];
        std::vector<T> elements;

        while( !temp.empty() ) {
            if(temp.top() == value) {
                temp.pop();
                for(int i=elements.size()-1; i>=0; i--){
                    temp.push(elements[i]);
                }
                std::swap(temp, Array[h]);
                size--;
                return true;
            }

            elements.push_back(temp.top());
            temp.pop();
        }
        return false;
    }

    bool Add(const T& value) {
        if(size + 1 > int(rehash_size * capacity)) {
            Resize();
        }

        int h = HashFunc(value, capacity);
        Array[h].push(value);

        size++;
        return true;
    }

    auto GetArray() {
        return Array;
    }

    size_t GetCapacity() {
        return capacity;
    }

    size_t GetSize() {
        return size;
    }
};

#endif // HASHTABLE_H
