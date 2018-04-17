#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <iostream>


template<class T>
class List{

struct Node {
       T   dataIn;
    Node * next;
};

    public:
        List(void);
       ~List(void);
        virtual void insertHead(T dataNew);
        virtual void insertTail(T dataNew);
        virtual void printList();
    private:
       Node * head;
          
};
#endif
