#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>
typedef int ItemType ;
typedef int KeyType;
struct Node
{

   std::pair<KeyType, ItemType> item;
   Node *left;
   Node *right;
   int level;
   int height;
   Node *next = nullptr;
   Node *prev = nullptr;
   int getHeight();
};
class BinarySearchTree
{

public:
    Node *root;
    unsigned int numberOfNodes;
public:

  BinarySearchTree();

   bool isEmpty() const;
   int getHeight() const;
   int getNumberOfNodes() const;
   std::pair<KeyType, ItemType> getRootData() const;
   void setRootData(const std::pair<KeyType&, ItemType&> newData);
   virtual bool add(const std::pair<KeyType, ItemType> newData);
   virtual bool remove(const KeyType& data);
   void clear();
   ItemType getEntry(const ItemType& anEntry) const ;
   bool contains(const ItemType& anEntry) const;

   void preorderTraverse(void visit(KeyType&, ItemType&)) const;
   void inorderTraverse(void visit(KeyType&, ItemType&)) const;
   void postorderTraverse(void visit(KeyType&, ItemType&)) const;


   void insertInOrder(Node* &subtrePtr, Node *newNodePtr);
   ItemType searchForEntry(const ItemType& anEntry, Node* treePtr) const;
   bool findNodeToRemove(Node* &subtrePtr, int data);
   void removeNode(Node*&);
   Node* locateInOrderSuccessor(Node* node);
   virtual  Node* createNewNodeWithItem(std::pair<KeyType, ItemType> item);

    void preTraverse(void visit(KeyType&, ItemType&), Node* treePtr)const;
    void inTraverse(void visit(KeyType&, ItemType&), Node* treePtr)const;
    void postTraverse(void visit(KeyType&, ItemType&), Node* treePtr)const;

};
#endif // BINARYSEARCHTREE_H
