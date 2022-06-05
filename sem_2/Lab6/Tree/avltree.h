#ifndef AVLTREE_H
#define AVLTREE_H

#include "binarysearchtree.h"

#include <vector>
#include <iostream>

using std::vector;
using std::bad_alloc;
class AVLTree : public BinarySearchTree
{

    public:
        bool add(const std::pair<KeyType, ItemType> newData);
        bool remove(const KeyType& data);

    private:
        void balancePath(Node* &node);

        void leftRotate(Node* &nodeA, Node* &parentOfA);
        void rightRotate(Node* &nodeA, Node* &parentOfA);

        void updateHeight(Node *node);
        int balanceFactor(Node* subtreePtr);

        public: std::vector<Node*>* getPath(std::pair<KeyType, ItemType> item) const;
        public: Node* createNewNodeWithItem(std::pair<KeyType, ItemType> item);
};

#endif // AVLTREE_H
