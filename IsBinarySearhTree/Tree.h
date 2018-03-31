#ifndef BST
#define BST

#include<cstdlib>
#include <vector>
struct Node{
    
    Node * right;
    Node * left;
    int key;
};
class Tree{

     public:
         Tree(std::vector<int> data);
        ~Tree();

         void insert(int keyIn);
         Node * remove(int keyOut);
         Node * search(int keySearch);
         void destroy_Tree();
         void printInOrder();
         void printPreOrder();
         void printPostOrder();
         bool isBST();
     private:
         void destroyTree(Node * leaf);
         void insert(int keyIn, Node * leaf);
         Node * searchKey(int keySearch, Node * leaf);
         void printInOrder(Node * leaf); 
         void printPreOrder(Node * leaf);
         void printPostOrder(Node * leaf);
         void isBST(Node * leaf);
         Node * root;
         int largest;
         bool flag;
}; 
#endif
