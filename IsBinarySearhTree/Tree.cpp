#include <iostream>
#include "Tree.h"

using namespace std;

/**************************************************


    Default Constructor


**************************************************/
Tree::Tree(vector<int> data){

    largest = 0;    
    flag = true;

    root = new Node;   
    root->key   = data.at(0);

    root->left = new Node;
    root->left->key   = data.at(1);
    
    root->right = new Node;
    root->right->key   = data.at(2);

    root->left->left = new Node;
    root->left->left->key   = data.at(3);

    root->left->right = new Node; 
    root->left->right->key   = data.at(4);

/*    root->right->left = new Node;
    root->right->left->key   = data[5];

    root->right->right = new Node;
    root->right->right->key   = data[6];
*/
    root->left->left->left = NULL;
    root->left->left->right  = NULL;
    root->left->right->left  = NULL;
    root->left->right->right   = NULL;
    
    root->right->right  = NULL;
    root->right->left   = NULL;
    
 /* root->right->right->left   = NULL;
    root->right->right->right    = NULL */;
}
/**************************************************


    Destructor


***************************************************/
Tree::~Tree(){

    destroy_Tree();

}
/***************************************************


Node * search(DataType keySearch);


***************************************************/
Node * Tree::search(int keySearch){

    return searchKey(keySearch, root);

}

/***************************************************
 
 
 Node * search(DataType keySearch, Node * leaf);
 
 
***************************************************/
Node * Tree::searchKey(int keySearch, Node * leaf){
 
     if(leaf != NULL){

         if(keySearch == leaf->key){
            
             return leaf;
         }
         if(keySearch < leaf->key){
         
             return searchKey(keySearch,leaf->left);             

         }else{

             return searchKey(keySearch,leaf->right);
         }
     }else{

         return NULL;    
     }    
 
}

/***************************************************


void destroyTree();


***************************************************/
void Tree::destroy_Tree(){

    destroyTree(root);
}

/***************************************************
 
 
void destroy_tree(Node * leaf);
 
 
***************************************************/ 
void Tree::destroyTree(Node * leaf){
      if(leaf != NULL){
 
         destroyTree(leaf->left);
         destroyTree(leaf->right);
         delete leaf;
     } 
 }

/***************************************************
 
 
 void printInOrder(Node * leaf);
 
 
***************************************************/
void Tree::printInOrder(){
 
     printInOrder(root);
     
}

/***************************************************


void printInOrder(Node * leaf);


***************************************************/
void Tree::printInOrder(Node * leaf){

    if(leaf == NULL){
        return;
    }

    printInOrder(leaf->left);
    cout<<leaf->key<<" ";
    printInOrder(leaf->right);
}
/***************************************************
 
 
 void printPreOrder(Node * leaf);
 
 
***************************************************/
void Tree::printPreOrder(){
 
     printPreOrder(root);
     
}
/***************************************************


void printPreOrder(Node * leaf);


***************************************************/
void Tree::printPreOrder(Node * leaf){

    if(leaf == NULL){
        return;
    }

    cout<<leaf->key<<" ";
    printPreOrder(leaf->left);
    printPreOrder(leaf->right);
}
/***************************************************
 
 
 void printPostOrder(Node * leaf);
 
 
***************************************************/
void Tree::printPostOrder(){
 
     printPostOrder(root);
     
}
/***************************************************


void printPostOrder(Node * leaf);


***************************************************/
void Tree::printPostOrder(Node * leaf){

    if(leaf == NULL){
        return;
    }

    printPostOrder(leaf->left);
    printPostOrder(leaf->right);
    cout<<leaf->key<<" ";
}

/***************************************************
 

 void isBST();
 
 
***************************************************/

bool Tree::isBST(){

  isBST(root);
  
  return flag;
  
}

/***************************************************


void isBST(Node * leaf);


***************************************************/
void Tree::isBST(Node * leaf){

    if( leaf == NULL || !flag){
        return;
    }

    isBST(leaf->left);

    if(leaf->key <= largest){ 
        flag = false;
    }else{
        largest = leaf->key;
    }
    isBST(leaf->right);
}

