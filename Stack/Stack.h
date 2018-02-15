#ifndef STACK_H
#define STACK_H
#include<cstdlib>
#include<iostream>

template<class T>
class Stack{

    private:

    struct  Node{
        
        T dataIn;
        Node * next;
    };
    int size;
    Node * head;

    public:

    Stack();
   ~Stack();
    void push(T dataNew);
    void pop(T & dataOut);
    void top(T & top);
    bool isEmpty();
    int  sizeOf();
    void printStack();
};
#endif
