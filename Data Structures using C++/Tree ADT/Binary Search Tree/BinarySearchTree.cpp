/**
 * Data Structures : Binary Search Tree
 * Author : Sachin Singh
 * Filename : BinarySearchTree.cpp
 * 
*/

#include "BinarySearchTree.h" // include the prototype declarations
#include <iostream> // for printing exception message on the console
#include <cstring> // for coping the exception detalis in BSTException class
using namespace std;

//----------BST Exception Class-------------

BSTException::BSTException() {}
BSTException::BSTException(const char *error) {
    strcpy(this->error,error);
}

void BSTException::printError() {  // utility function for printing the exception details.
    cout<<error<<endl;
}

//----------------Binary Node Structure-------------------------
BST::BSTNode::BSTNode() {
    data = key = 0;
    left = right = nullptr;
}

BST::BSTNode::BSTNode(int key , int data) {
    this->key = key;
    this->data = data;
    left = right = nullptr;
}
//----------getters and setters for data and key -----------------
int BST::BSTNode::getData() {
    return this->data;
}

void BST::BSTNode::setData(int data) {
    this->data = data;
}

int BST::BSTNode::getKey() {
    return this->key;
}

void BST::BSTNode::setKey(int key) {
    this->key = key;
}
//------------------ Binary Search Tree -------------------


//---------Public Function Definitions---------------------
BST::BST() {
    root = nullptr;
}

// to insert a node in BST
void BST::insert(int key , int data) {
    if (this->root == nullptr) {
        root = getNewNode(key,data); // make root node first if tree is empty.
    }
    else {
        insertNode(root,key,data);
    }
}

// returns the value of assosiated key
int BST::get(int key) {
    if (root == nullptr)
        throw(BSTException("Can't find node. Tree is Empty."));
    else  return getNode(root,key)->getKey();
     
}

// removes the node from BST
int BST::remove(int key) {
    if (root == nullptr)
        throw(BSTException("Tree is Empty. Can't Remove Node."));
    else
        remove_node(root,key);
}

// returns the height of the tree
int BST::getTreeHeight() {
    if (root == nullptr)
        return 0;
    else return height(root);
}

// returns the total number of nodes existing in BST.
int BST::getTotalNodes() {
    if (root == nullptr)
        return 0;
    else return totalNodes(root);
}

// returns the total number of nodes in BST which having only one child either left or right.
int BST::totalSingleNode() {
    if (root == nullptr)
        return 0;
    else return singleNodes(root);
}

// returns the Maximum Key that exist in BST.
int BST::getMaximumKey() {
    if (root == nullptr)
        return -1;
    else
        return largestKeyNode(root)->getKey();
}

// returns the Minimun key that exist in BST.
int BST::getMinimumKey() {
    if (root == nullptr)
        return -1;
    else
        return smallestKeyNode(root)->getKey();
}

// returns the total number of nodes that have at least one child either left or right. 
int BST::totalInternalNode() {
    if (root == nullptr)
        return 0;
    else 
        return internalNodes(root);
}

// returns the total number of nodes that does not have any child node.
int BST::totalExternalNode() {
    if (root == nullptr)
        return 0;
    else
        return externalNodes(root);
}

// visits each node in binary tree in BST in a specified order and print the data.
// if no order is specified . tree will be traversed in INORDER manner.
void BST::traverse(Traverse order) { // Traverse is a enum with posssible values {INORDER,PREORDER,POSTORDER}.
    if (root == nullptr) {
        cout<<"Tree is Empty"<<endl;
        return;
    }
    switch(order) {
        case Traverse::INORDER : inorderTraverse(root); break;
        case Traverse::PREORDER : preorderTraverse(root); break;
        case Traverse::POSTORDER : postorderTraverse(root); break;
    }
}
//************PRIVATE***********

/*NODE INSERTION IN BINARY SEARCH TREE*/
BST::BSTNode* BST::insert(BSTNode* loc, int key , int data) {
    if (loc == nullptr)
        return getNewNode(key,data);
    if (key < loc->getKey()) {
        loc->left = insert(loc->left,key,data);
        return loc;
    }
    else if (key > loc->getKey()) {
        loc->right = insert(loc->right,key,data);
        return loc;
    }
    else
        throw(BSTException("Duplicate Key")); // duplicate node found
}
/*RETURNS A NEWLY CREATED NODE*/
BST::BSTNode* BST::getNewNode(int key , int data) {
    return new BST::BSTNode(key,data);
}

/*RETURNS TOTAL NUMBER OF NODES IN THE TREE*/
int BST::totalNodes(BSTNode *loc) {
    if (loc == nullptr)
        return 0;
    else return totalNodes(loc->left) + totalNodes(loc->right) + 1;
}

/*Returns the Address of node specified by key. */
BST::BSTNode* BST::getNode(BSTNode *loc , int key) {
    if (loc == nullptr)
        throw(BSTException("Search Complete. Key Not Found.")); // throw not found exception if key not found.
    else if (key == loc->getKey())
        return loc;
    else if (key < loc->getKey())
        return getNode(loc->left,key);
    else
        return getNode(loc->right,key);
}

// counts the nodes which having only one child.
int BST::singleNodes(BSTNode *loc) {
    if (loc == nullptr)
        return 0;
    else if (((loc->left != nullptr) && (loc->right == nullptr))) // it has only left child
        return 1 + singleNodes(loc->left);
    else if ((loc->left == nullptr) && (loc->right != nullptr)) // it has only right child
        return 1 + singleNodes(loc->right);
    else
        return singleNodes(loc->left) + singleNodes(loc->right);
}

// counts the internals nodes in BST
int BST::internalNodes(BSTNode *loc) {
    if (loc == nullptr)
        return 0;
    else if (loc->left == nullptr && loc->right == nullptr)
        return 0;
    else return internalNodes(loc->left) + internalNodes(loc->right) + 1;
}

// counts externals nodes in BST
int BST::externalNodes(BSTNode *loc) {
    if (loc == nullptr)
        return 0;
    else if (loc->left == nullptr && loc->right == nullptr)
        return 1;
    else
        return externalNodes(loc->left) + externalNodes(loc->right);
}

// returns the pointer to the node which having largest key in BST
BST::BSTNode* BST::largestKeyNode(BSTNode *loc) {
    if (loc->right != nullptr)
        return largestKeyNode(loc->right);
    else
        return loc;
}

// removes the node from BST specified with key
BST::BSTNode* BST::remove_node(BSTNode *loc, int key) {
    if (loc == nullptr)
        throw(BSTException("Can't delete node , node not found."));
    else if (key == loc->getKey()) { // target node found.
        if (loc->left == nullptr && loc->right == nullptr) { // if its a leaf node
            delete loc;
            return nullptr;
        }

        else if (loc->left != nullptr && loc->right != nullptr) {  // if its a node with both child
                BST::BSTNode* largest_key_node = largestKeyNode(loc->left);
                loc->setKey(largest_key_node->getKey());
                loc->setData(largest_key_node->getData());
                loc->left = remove_node(loc->left,largest_key_node->getKey());
                return loc;
        }

        else if (loc->left !=nullptr && loc->right == nullptr) {  // node with only left child
                BSTNode* temp = loc->left;
                delete loc;
                return temp;
        }

        else {  // node with only right child
                BSTNode* temp = loc->right;
                delete loc;
                return temp;
        }
    }

    else if (key < loc->getKey()) {
        loc->left = remove_node(loc->left,key);
        return loc;
    }
    else  {
        loc->right = remove_node(loc->right,key);
        return loc;
    }
}

// returns the pointer to the node which having smallest key in BST
BST::BSTNode* BST::smallestKeyNode(BSTNode *loc) {
    if (loc->left != nullptr)
        return smallestKeyNode(loc->left);
    else
        return loc;
}

/*RETURNS THE HEIGHT OF THE TREE*/
int BST::height(BSTNode *loc) {
    if (loc == nullptr)
        return 0;
    int leftTreeHeight = height(loc->left);
    int rightTreeHeight = height(loc->right);
    if (leftTreeHeight >= rightTreeHeight)
        return leftTreeHeight + 1;
    else
        return rightTreeHeight + 1;
}

/*INORDER TRAVERSAL OF TREE*/
void BST::inorderTraverse(BST::BSTNode *loc) {
    if (loc == nullptr)
        return;
    inorderTraverse(loc->left);
    cout<<"Key : "<<loc->getKey()<<", Data : "<<loc->getData()<<endl;
    inorderTraverse(loc->right);
}

void BST::preorderTraverse(BST::BSTNode *loc) {
    if (loc == nullptr)
        return;
    cout<<"Key : "<<loc->getKey()<<", Data : "<<loc->getData()<<endl;
    preorderTraverse(loc->left);
    preorderTraverse(loc->right);
}

void BST::postorderTraverse(BST::BSTNode *loc) {
    if (loc == nullptr)
        return;       
    postorderTraverse(loc->left);
    postorderTraverse(loc->right);
    cout<<"Key : "<<loc->getKey()<<", Data : "<<loc->getData()<<endl;

}

