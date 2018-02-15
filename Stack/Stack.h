#ifndef STACK_H
#define STACK_H
#include<cstdlib>
#include<iostream>

template<class T>
class Stack{

    private:

    Node{
        T dataIn;
        Node * next;
    };
    int size;

    public:

    Stack();
   ~Stack();
    void push(T dataIn);
    void pop();
    T    top();
    bool isEmpty();
    int  sizeOf();
    void printStack();
};
#endif
