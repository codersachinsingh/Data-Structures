/**
 * Data Structures : Binary Search Tree Implementation.
 * Author : Sachin Singh
 * Filename : BinarySearchTree.h
 * 
*/

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

enum Traverse {
    INORDER,POSTORDER,PREORDER
};

class BSTException {
    char error[100];
    public:
        BSTException();
        BSTException(const char *error);
        void printError();
};
/**
 * Binary Search Tree
 * @author : Sachin Singh
*/
class BST {
    private:
        class BSTNode {
            private:
                int data;
                int key;
            public:
                BSTNode *right;
                BSTNode *left;
                BSTNode();
                BSTNode(int key , int data);
                int getKey();
                void setKey(int key);
                int getData();
                void setData(int data);
        } *root;

        BSTNode* getNewNode(int key , int data);
        BSTNode* insertNode(BSTNode* loc, int key , int data);
        int height(BSTNode* loc);
        BSTNode* getNode(BSTNode* loc , int key);
        int totalNodes(BSTNode* loc);
        int singleNodes(BSTNode* loc);
        int internalNodes(BSTNode* loc);
        int externalNodes(BSTNode* loc);
        void inorderTraverse(BSTNode* loc);
        void preorderTraverse(BSTNode* loc);
        void postorderTraverse(BSTNode* loc);
        BSTNode* smallestKeyNode(BSTNode* loc);
        BSTNode* largestKeyNode(BSTNode* loc);
        BSTNode* remove_node(BSTNode* loc , int key);
    public:
        BST();
        void insert(int key , int data);
        int get(int key);
        int remove(int key);
        int getTreeHeight();
        int getTotalNodes();  
        int getMaximumKey();
        int getMinimumKey();
        int totalInternalNode();
        int totalSingleNode();
        int totalExternalNode();
        void traverse(Traverse order = Traverse::INORDER); /*Default Inorder traverse*/
};

#endif