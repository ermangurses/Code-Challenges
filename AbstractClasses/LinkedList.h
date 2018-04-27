#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <iostream>

#include "List.h"

template<class T>
class LinkedList : public List{

struct Node {
       T   dataIn;
    Node * next;
};

    public:
        LinkedList();
       ~LinkedList();
        void insertHead(T dataNew);
        void insertTail(T dataNew);
        void printLinkedList();
    private:
       Node * head;
          
};
#endif
