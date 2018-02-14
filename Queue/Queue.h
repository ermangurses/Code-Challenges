# ifndef QUEUE_H
# define QUEUE_H

# include<cstdlib>
# include<iostream>

template<class T>
class Queue{


    private:

    struct Node{
        T dataIn;
        Node * next;
    };

    Node * head;
    Node * tail;
    int size;

    public:

    Queue();
   ~Queue();
    void enqueue(T dataIn);
    bool dequeue(T & dataIn);
    bool isEmpty();
    int  sizeOf();
           
}
# endif
