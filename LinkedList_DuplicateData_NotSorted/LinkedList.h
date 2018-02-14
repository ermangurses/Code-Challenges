#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

using namespace std;


template<class T>
class LinkedList{

struct Node {
       T   dataIn;
    Node * next;
};

    public:
        LinkedList();
       ~LinkedList();
         int sizeOf();
        bool isEmpty();
        void insertHead(T dataNew);
        void insertTail(T dataNew);
        void removeHead();
        void removeTail();
        void remove(T dataOut);
        void removeOld(T dataOut);
        bool search(T dataSearch);
        bool searchOld(T dataSearch);
        bool removeDuplicates();
        bool removeDuplicatesOld();
        bool removeDuplicatesUsingHash();
        bool removeDuplicatesUsingHash();
           T nthToLast(int n);
        void printLinkedList();
        bool removeMiddleNode();
    private:
        int   size;
       Node * head;
       bool   deleteNode(Node * node); 
          
};
#endif
