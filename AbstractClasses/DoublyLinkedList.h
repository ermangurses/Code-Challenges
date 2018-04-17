#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>


template<class T>
class DoublyLinkedList : public List{

struct Node {
       T   dataIn;
    Node * next;
};

    public:
        DoublyLinkedList();
       ~DoublyLinkedList();
        void insertHead(T dataNew);
        void insertTail(T dataNew);
        void printLinkedList();
    private:
       Node * head;
          
};
#endif
