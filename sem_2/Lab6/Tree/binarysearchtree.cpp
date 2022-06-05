#include "binarysearchtree.h"
#include <iostream>

int Node::getHeight(){

        if(this) return height;
        return 0;
}

BinarySearchTree::BinarySearchTree() : root(NULL), numberOfNodes(0)
{}
bool BinarySearchTree::isEmpty() const
{
    return this->root == NULL;
}
int BinarySearchTree::getNumberOfNodes() const
{
    return this->numberOfNodes;
}
std::pair<KeyType, ItemType> BinarySearchTree::getRootData() const
{
    return root->item;
}
void BinarySearchTree::setRootData(const std::pair<KeyType&, ItemType&> newData)
{
    this->root->item = newData;
}

Node* BinarySearchTree::createNewNodeWithItem(std::pair<KeyType, ItemType> item)
{
    Node* newNode = new Node;
    try {
        newNode = new Node;
    }catch(std::bad_alloc e){
        std::cout << "Bad alloc!";
    }
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->item = item;
    return newNode;
}
bool BinarySearchTree::add(const std::pair<KeyType, ItemType> newData)
{
    //add
    Node *newNodePtr = createNewNodeWithItem(newData);
    insertInOrder(root, newNodePtr);
    numberOfNodes ++;
    return 1;

}

bool BinarySearchTree::remove(const KeyType& data)
{
    bool success = false;
    success = findNodeToRemove(root, data);

    return success;
}

bool BinarySearchTree::findNodeToRemove(Node* &subtrePtr, int data)
{
    //if located
    if (subtrePtr == NULL)
    {
        return false;
    }
    if (subtrePtr->item.first == data)
    {
        std::cout << "для удаления: " << subtrePtr->item.first << " " << subtrePtr << std::endl;;
        removeNode(subtrePtr);
        return true;
    }
    else if (data < subtrePtr->item.first)
    {
        return findNodeToRemove(subtrePtr->left, data);
    }
    else
    {
        return findNodeToRemove(subtrePtr->right, data);
    }
}

void BinarySearchTree::removeNode(Node* &nodeToRemove)
{
    Node* delPtr;
    const bool isLeaf = !nodeToRemove->left && !nodeToRemove->right;

    const bool hasOneChild = (nodeToRemove->left && !nodeToRemove->right) ||
        (!nodeToRemove->left && nodeToRemove->right);

    const bool hasTwoChildren = nodeToRemove->left && nodeToRemove->right;

    if (isLeaf)
    {
        delete nodeToRemove;
        nodeToRemove = NULL;
    }
    else if(hasOneChild)
    {
        delPtr = nodeToRemove;
        if (nodeToRemove->left)
        {
            nodeToRemove = nodeToRemove->left;
            delPtr->left = NULL;
        }
        else
        {
            nodeToRemove = nodeToRemove->right;
            delPtr->right = NULL;
        }
        delete delPtr;
        delPtr = NULL;
    }
    else if(hasTwoChildren){
        Node* inOrderSuccessor = locateInOrderSuccessor(nodeToRemove->right);
        nodeToRemove->item = inOrderSuccessor->item;
        removeNode(inOrderSuccessor);
    }

}
Node* BinarySearchTree::locateInOrderSuccessor(Node* node)
{
    if (node->left == NULL)
    {
        return node;
    }
    else
    {
        return locateInOrderSuccessor(node->left);
    }

}

void BinarySearchTree::insertInOrder(Node* &subtrePtr, Node *newNodePtr)
{
    if(subtrePtr == NULL)
    {
        subtrePtr = newNodePtr;

    }else if(subtrePtr->item < newNodePtr->item)
    {
        insertInOrder(subtrePtr->right, newNodePtr);
    }else
    {
        insertInOrder(subtrePtr->left, newNodePtr);
    }
}

ItemType BinarySearchTree::getEntry(const ItemType& anEntry) const
{
    return searchForEntry(anEntry, this->root);
}
ItemType BinarySearchTree::searchForEntry(const ItemType& anEntry, Node* treePtr)const
{
    if (treePtr == NULL)
    {
        return -1;
    }
    if (anEntry == treePtr->item.first)
    {
        return treePtr->item.second;
    }
    else if (anEntry > treePtr->item.first)
    {
        return searchForEntry(anEntry, treePtr->right);
    }
    else {
        return searchForEntry(anEntry, treePtr->left);
    }

}

void BinarySearchTree::preorderTraverse(void visit(KeyType&, ItemType&))const
{
    preTraverse(visit, this->root);
}
void BinarySearchTree::inorderTraverse(void visit(KeyType&, ItemType&)) const
{
    inTraverse(visit, this->root);
}
void BinarySearchTree::postorderTraverse(void visit(KeyType&, ItemType&))const
{
    postTraverse(visit, this->root);
}
void BinarySearchTree::preTraverse(void visit(KeyType&, ItemType&), Node* treePtr) const
{
    if(treePtr != NULL)
    {
        visit(treePtr->item.first, treePtr->item.second);
        preTraverse(visit, treePtr->left);
        preTraverse(visit, treePtr->right);
    }
}
void BinarySearchTree::inTraverse(void visit(KeyType&, ItemType&), Node* treePtr) const
{
    if(treePtr != NULL)
    {
        inTraverse(visit, treePtr->left);
        visit(treePtr->item.first, treePtr->item.second);
        inTraverse(visit, treePtr->right);
    }
}
void BinarySearchTree::postTraverse(void visit(KeyType&, ItemType&), Node* treePtr) const
{
    if(treePtr != NULL)
    {
        postTraverse(visit, treePtr->left);
        postTraverse(visit, treePtr->right);
        visit(treePtr->item.first, treePtr->item.second);
    }
}
