#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <forward_list>
#define THRESHOLD (0.70)

using namespace std;

template<typename K, typename V>
class node {
public:
    K key;
    V value;
    node<K, V> *next = nullptr;

    node(K key, V value) {
        this->key = key;
        this->value = value;
    }

    ~node() {
        if(next) delete next;
    }
};

template<typename K, typename V, typename Compare = std::less<K> >
class HashMap {
public:
    int n;
    int m;
    node<K, V> **buckets;

    int hashcode(int key) {
        return key % m;
    }

    int hashcode(string key) {
        const int PRIME = 43;


        int res = 0;
        int pow = 1;

        // Apple
        // hash = A*PRIME^0 + p* PRIME^1 + p*PRIME^2 +...e*PRIME^4
        for (char ch : key) {
            res += ch * pow;
            pow = pow * PRIME;

            pow %= m;
            res %= m;
        }

        return res;
    }

    void resize() {
        node<K, V> **oldbuckets = buckets;
        int num_old_buckets = m;

        m = (m << 1) | 1;
        n = 0;

        buckets = new node<K, V> *[m];
        for (int i = 0; i < m; i++)
            buckets[i] = nullptr;


        for (int i = 0; i < num_old_buckets; i++) {
            auto temp = oldbuckets[i];

            if (temp != nullptr) {
                while (temp != nullptr) {
                    insert(temp->key, temp->value);
                    temp = temp->next;
                }

                delete oldbuckets[i];
            }
        }

        delete[] oldbuckets;
    }

public:
    HashMap(int bucket_count = 11) {
        this->n = 0;
        this->m = bucket_count;

        this->buckets = new node<K, V> *[this->m];

        for (int i = 0; i < m; i++)
            this->buckets[i] = nullptr;
    }


    void insert(K key, V value) {
        int i = hashcode(key);
        auto *temp = new node<K, V>(key, value);

        temp->next = this->buckets[i];
        this->buckets[i] = temp;

        this->n += 1;

        float load_factor = (float) this->n / this->m;

        if (load_factor > THRESHOLD) {
            resize();
        }
    }

    void clear() {

        for (int i = 0; i < m; i++)
            delete this->buckets[i];
        delete[] buckets;

        this->n = 0;
        this->m = 11;


        this->buckets = new node<K, V> *[this->m];

        for (int i = 0; i < m; i++)
            this->buckets[i] = nullptr;
    }

    V *find(K key) {
        int idx = hashcode(key);

        node<K, V> *ptr = buckets[idx];
        while (ptr != nullptr) {
            if (ptr->key == key)
                return &(ptr->value);

            ptr = ptr->next;
        }

        return nullptr;
    }

    bool contains(K key) {
        if(find(key)!=nullptr)
            return true;
        return false;
    }

    bool erase(K key) {
        int idx = hashcode(key);

        node<K, V> *prev = nullptr;
        node<K, V> *ptr = buckets[idx];

        while (ptr != nullptr) {
            if (ptr->key == key)
                break;

            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == nullptr) {
            return false;
        }


        if (prev == nullptr) {
            buckets[idx] = ptr->next;
        } else {
            prev->next = ptr->next;
        }

        free(ptr);

        n -= 1;
        return true;
    }


    V &operator[](K i){
        V s = NULL;
        if(!contains(i))
            insert(i, s);

        return *find(i);
    }

};


#endif // HASHMAP_H
