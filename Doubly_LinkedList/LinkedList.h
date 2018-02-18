#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<cstdlib>
#include<iostream>

template<class T>
class LinkedList{

    private:
        struct Node {
            T dataIn;
            Node * next;
            Node * prev;
        };
        Node * head;
        int   size;
 
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
        bool search(T dataSearch);
        void removeDuplicatesUsingHash();
        void printLinkedList();
};
#endif
