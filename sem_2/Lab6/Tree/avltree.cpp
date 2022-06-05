#include "avltree.h"
#include <assert.h>

std::vector<Node*>* AVLTree::getPath(std::pair<KeyType, ItemType> item) const
{
    Node *currNode = this->root;
    if(!currNode)
        return NULL;

    std::vector<Node*> *pathElements = new std::vector<Node*>;
    while(currNode->item != item && currNode != NULL)
    {
        //
        pathElements->push_back(currNode);

        if(currNode->item > item){
            currNode = currNode->left;
        }else if(currNode->item < item){
            currNode = currNode->right;
        }
    }
    pathElements->push_back(currNode);

    return pathElements;
}

Node* AVLTree::createNewNodeWithItem(std::pair<KeyType, ItemType> item)
{
    Node* newNode = BinarySearchTree::createNewNodeWithItem(item);
    newNode->height = 1;
    return newNode;
}
int max(int first, int second)
{
    return (first > second) ? first : second ;
}
int AVLTree::balanceFactor(Node* subtreePtr)
{
    int balanceF = subtreePtr->right->getHeight() - subtreePtr->left->getHeight();
    if (balanceF < -1){
        return -2;
    }
    else if (balanceF > 1){
        return 2;
    }
    else
        return balanceF;
}
void AVLTree::updateHeight(Node *node)
{
    #ifdef _DEBUG_
    assert(node!=NULL);
    #endif
    node->height = 1 + max(node->left->getHeight(), node->right->getHeight());
}

void AVLTree::leftRotate(Node* &nodeA, Node* &parentOfA)
{
    Node* A = nodeA;
    Node* B = nodeA->right;

    if (nodeA == this->root){
        this->root = B;
    }
    else{
        if (nodeA == parentOfA->left){
            parentOfA->left = B;
        }
        else {
            parentOfA->right = B;
        }
    }
    A->right = B->left;
    B->left = A;

    updateHeight(A);
    updateHeight(B);
}
void AVLTree::rightRotate(Node* &nodeA, Node* &parentOfA)
{
    Node* A = nodeA;
    Node* B = nodeA->left;

    if (nodeA == this->root){
        this->root = B;
    }
    else{
        if (nodeA == parentOfA->left){
            parentOfA->left = B;
        }
        else {
            parentOfA->right = B;
        }
    }
    A->left = B->right;
    B->right = A;

    updateHeight(A);
    updateHeight(B);
}
void AVLTree::balancePath(Node* &node)
{
    vector<Node*>* pathFromNodeEToRoot = getPath(node->item);
    Node* parentOfA;

    for (int i=pathFromNodeEToRoot->size()-1; i >= 0; i--)
    {
        updateHeight(pathFromNodeEToRoot->at(i));
        if(i >= 1){
            parentOfA = pathFromNodeEToRoot->at(i-1);
        }else{
            parentOfA = NULL;
        }

        switch(balanceFactor(pathFromNodeEToRoot->at(i))){
            case -2:
                if (balanceFactor(pathFromNodeEToRoot->at(i)->left) > 0){
                    this->leftRotate(pathFromNodeEToRoot->at(i)->left, pathFromNodeEToRoot->at(i));
                }
                this->rightRotate(pathFromNodeEToRoot->at(i), parentOfA);
            break;
            case 2:
                if (balanceFactor(pathFromNodeEToRoot->at(i)->right) < 0){
                    this->rightRotate(pathFromNodeEToRoot->at(i)->right, pathFromNodeEToRoot->at(i));
                }
                this->leftRotate(pathFromNodeEToRoot->at(i), parentOfA);
            break;
        }
    }
}
bool AVLTree::add(const std::pair<KeyType, ItemType> newData)
{
    if(this->getEntry(newData.first)!=-1) this->remove(newData.first);
    Node *newNode = NULL;
    try{
        newNode = AVLTree::createNewNodeWithItem(newData);
    }
    catch (bad_alloc e){
    }
    insertInOrder(root, newNode);

    balancePath(newNode);

    numberOfNodes++;
    return false;
}
bool AVLTree::remove(const KeyType& data)
{
    if(root == NULL)
        return false;

    Node* currNode = root;
    Node* parentNode = NULL;

    while(currNode != NULL){

        if(data > currNode->item.first){
            parentNode = currNode;
            currNode= currNode->right;
        }else if (data < currNode->item.first){
            parentNode = currNode;
            currNode = currNode->left;
        }else{
            break;
        }
    }

    if(currNode == NULL)
        return false;

    if(currNode->left == NULL){
        if(parentNode == NULL)
            root = currNode->right;
        else {
            if(data < parentNode->item.first )
                parentNode->left = currNode->right;
            else
                parentNode->right = currNode->right;

            balancePath(parentNode);
        }
    }
    else
    {
        Node *parentOfRightMost = currNode;
        Node *rightMost = currNode->left;

        while(rightMost->right != NULL){
            parentOfRightMost = rightMost;
            rightMost = rightMost->right;
        }

        currNode->item = rightMost->item;

        if(parentOfRightMost->right == rightMost)
            parentOfRightMost->right = rightMost->left;
        else
            parentOfRightMost->left = rightMost->left;

        // Balance the tree if necessary
        balancePath(parentOfRightMost);
    }
    return true;
}
