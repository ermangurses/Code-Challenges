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
     private:
         void destroyTree(Node * leaf);
         void insert(int keyIn, Node * leaf);
         Node * searchKey(int keySearch, Node * leaf);
         void printInOrder(Node * leaf); 
         Node * root;
}; 
#endif
