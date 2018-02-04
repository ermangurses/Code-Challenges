#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;


template<class DataType>
class LinkedList{

struct Node {
    DataType dataIn;
    Node * next;
};

    public:
        LinkedList();
       ~LinkedList();
        bool insertHead(DataType dataNew);
        bool insertTail(DataType dataNew);
        bool removeHead();
        bool removeTail();
        bool remove(DataType dataOut);
        bool removeDuplicates();
        bool removeDuplicatesUsingHash();
        bool search(DataType dataSearch);
        DataType nthToLast(int n);
        void printLinkedList();
        bool deleteMiddleNode();
    private:
       Node * head;
       bool deleteNode(Node * node); 
          
};
#endif
