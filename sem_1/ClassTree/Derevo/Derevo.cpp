int sizeOfTree = 0;
int sizeOfArr = 1;
template <class T>
class Node {
public:
    Node() = default;

    Node(T key, Node<T>* parent = nullptr, Node<T>* firstChild = nullptr, Node<T>* nextSibling = nullptr)
    {
        Key = key;
        Parent = parent;
        FirstChild = firstChild;
        NextSibling = nextSibling;

    }
    ~Node() = default;

    T Key;
    Node<T>* Parent;
    Node<T>* FirstChild;
    Node<T>* NextSibling;
};
#include <iostream>
#include <queue>
//void obhod(Node<int> *arr);
void hod(std::queue <Node<int>>& f, Node<int> k, bool isSibling);
int main()
{
    Node<int> t0(0);
    Node<int> t1(1, &t0);
    t0.FirstChild = &t1;
    Node<int> t2(2, &t0);
    t1.NextSibling = &t2;
    Node<int> t3(3, &t0);
    t2.NextSibling = &t3;
    Node<int> t4(4, &t1);
    t1.FirstChild = &t4;
    Node<int> t5(5, &t1);
    t4.NextSibling = &t5;
    Node<int> t6(6, &t3);
    t3.FirstChild = &t6;
    Node<int> t7(7, &t4);
    t4.FirstChild = &t7;
    Node<int> t8(8, &t4);
    t7.NextSibling = &t8;
    Node<int> t9(9, &t6);
    t6.FirstChild = &t9;

    std::queue <Node<int>> q;
    q.push(t0);
    
    
    //Node<int> a[100] = { t0 };
    hod(q,t0,false);
    std::cout << sizeOfTree;
}
void hod(std::queue <Node<int>>& f, Node<int> k, bool isSibling) {
   
    std::cout << k.Key << '\n';
    if (!isSibling) {
        f.pop();
    }
        
    
    

    sizeOfTree++;

    if (k.FirstChild != nullptr) {
        f.push(*k.FirstChild);

    }

    if (k.NextSibling != nullptr) {
        hod(f, *k.NextSibling, true);
        return;
    }

    if (!f.empty()) {
        hod(f, f.front(),false);
    }


}

/*void obhod(Node<int>* arr) {
    Node<int> array[100];
    int size = 0;
    for (int j = 0; j < sizeOfArr; j++) {
        sizeOfTree++;
        if (arr[j].FirstChild == nullptr) continue;
        

        Node<int> x;
        x = *(arr[j].FirstChild);

        array[size] = x;
        while (x.NextSibling != nullptr) {

            ++size;
            array[size] = *x.NextSibling;

            x = *(x.NextSibling);

        }
        ++size;
    }
    sizeOfArr = size;
    if (size != 0) obhod(array);
}
*/