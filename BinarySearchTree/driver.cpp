#include "BSTree.h"
#include <iostream>

using namespace std;

int main(){

    BSTree * bst = new BSTree();


    bst->insert(1);
    bst->insert(2);
    bst->insert(3);
    bst->insert(4);
    bst->insert(5);
    

    bst->printTree();

return 0;
}
