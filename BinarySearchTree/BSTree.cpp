#include <iostream>
#include "BSTree.h"

using namespace std;

/**************************************************


    Default Constructor


**************************************************/
BSTree::BSTree(){

    root  = nullptr;
}
/**************************************************


    Destructor


***************************************************/
BSTree::~BSTree(){

    destroy_Tree();
}

/***************************************************

 
bool insert(DataType keyIn);


***************************************************/
void BSTree::insert(int keyIn){

    if (root != nullptr) {
        insert(keyIn,root);
    } else {
        root = new Node;
        root->key = keyIn;
        root->left = nullptr;
        root->right = nullptr;
    }
}

/***************************************************
 
  
 void insert(DataType keyIn, Node * leaf);
 

***************************************************/
void BSTree::insert(int keyIn, Node * leaf){

    if (keyIn < leaf->key) {
     
        if (leaf->left != nullptr) {

            insert(keyIn,leaf->left);
        } else {
           
            leaf->left = new Node;
            leaf->left->key = keyIn;
            leaf->left->left = nullptr; 
            leaf->left->right  = nullptr;
        }     
    } else if (keyIn >= leaf->key) {
          
        if (leaf->right != nullptr) {

            insert(keyIn,leaf->right);
        } else {

            leaf->right = new Node;
            leaf->right->key = keyIn;
            leaf->right->left = nullptr;
            leaf->right->right= nullptr;
        }
    }
}

/***************************************************


Node * remove(DataType keyOut);
 

***************************************************/
Node * BSTree::remove(int keyOut){
 
    return nullptr;
}

/***************************************************


Node * search(DataType keySearch);


***************************************************/
Node * BSTree::search(int keySearch){

    return searchKey(keySearch, root);
}

/***************************************************
 
 
 Node * search(DataType keySearch, Node * leaf);
 
 
***************************************************/
Node * BSTree::searchKey(int keySearch, Node * leaf){
 
     if (leaf != nullptr) {

         if (keySearch == leaf->key) {
            
             return leaf;
         }
         if (keySearch < leaf->key) {
         
             return searchKey(keySearch,leaf->left);             

         } else {

             return searchKey(keySearch,leaf->right);
         }
     } else {

         return nullptr;    
     }     
}

/***************************************************


void destroyTree();


***************************************************/
void BSTree::destroy_Tree(){

    destroyTree(root);
}

/***************************************************
 
 
 void printInOrder(Node * leaf);
 
 
***************************************************/
void BSTree::printInOrder(){
 
     printInOrder(root);
}

/***************************************************


void printInOrder(Node * leaf);


***************************************************/
void BSTree::printInOrder(Node * leaf){

    if (leaf == nullptr) {
        return;
    }

    printInOrder(leaf->left);
    cout<<leaf->key<<endl;
    printInOrder(leaf->right);
}
/***************************************************
 
 
 void printPreOrder(Node * leaf);
 
 
***************************************************/
void BSTree::printPreOrder(){
 
     printPreOrder(root);
}

/***************************************************


void printPreOrder(Node * leaf);


***************************************************/
void BSTree::printPreOrder(Node * leaf){

    if (leaf == nullptr) {
        return;
    }
    cout<<leaf->key<<endl;
    printPreOrder(leaf->left);
    printPreOrder(leaf->right);
}

/***************************************************
 
 
 void printPostOrder(Node * leaf);
 
 
***************************************************/
void BSTree::printPostOrder(){

     printPostOrder(root);
}

/***************************************************


void printPostOrder(Node * leaf);


***************************************************/
void BSTree::printPostOrder(Node * leaf){

    if (leaf == nullptr) {
        return;
    }
    printPostOrder(leaf->left);
    printPostOrder(leaf->right);
    cout<<leaf->key<<endl;
}

/***************************************************


void destroy_tree(Node * leaf);


***************************************************/
void BSTree::destroyTree(Node * leaf){   
    if (leaf != nullptr) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}
