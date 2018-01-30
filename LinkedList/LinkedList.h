#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

template <class DataType>
class LinkedList{

    struct Node{
        DataType  dataIn;
        Node     *next;
    }; 

    public:
        LinkedList(); // Default Contructor
       ~LinkedList(); // Destructor
        

        int      sizeOf();
        bool     isEmpty();
        bool     insertInOrder(DataType dataIn); // Insert data in order
        void     printLinkedList(); // Print the entire LinkedList
        bool     remove(DataType dataOut); // Remove specific data
        bool     search(DataType dataIn); // Search linkedList
    private:
        Node * head;
        int size;
        void copyLinkedList(const LinkedList & otherList); // Copy linkedList 
};
#endif
