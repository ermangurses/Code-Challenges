#ifndef BST
#define BST

#include<cstdlib>

struct Node{
 
    int key;
    Node * right;
    Node * left;
};
class BSTree{

     public:
         BSTree();
        ~BSTree();

         void insert(int keyIn);
         Node * remove(int keyOut);
         Node * search(int keySearch);
         void destroy_Tree();
         void printInOrder();
         void printPreOrder();
         void printPostOrder();
     private:
         void destroyTree(Node * leaf);
         void insert(int keyIn, Node * leaf);
         Node * searchKey(int keySearch, Node * leaf);
         void printInOrder(Node * leaf); 
         void printPreOrder(Node * leaf);
         void printPostOrder(Node * leaf);
         Node * root;
}; 
#endif
