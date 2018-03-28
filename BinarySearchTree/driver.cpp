#include "BSTree.h"
#include <iostream>

using namespace std;

int main(){

    BSTree * bst = new BSTree();

    bst->insert(7);
    bst->insert(4);
    bst->insert(5);
    bst->insert(3);
    bst->insert(10);
    bst->insert(11);    
    bst->insert(9);
    
    cout<< "printInOrder"<<endl;
    bst->printInOrder();
    
    cout<< "printPreOrder"<<endl;
    bst->printPreOrder();
    
    cout<< "printPostOrder"<<endl;
    bst->printPostOrder();
return 0;
}
