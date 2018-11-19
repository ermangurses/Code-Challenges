/******************************************************************************
// -- Singly LinkedList
// -- Sorted LinkedList
// -- Does not allow duplicate data
*****************************************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
#include <cstdlib>
#include <iostream>


template <class T>
class LinkedList{

    private:
        struct Node{
            T      dataIn;
            Node * next;
        };
        Node * head;
        int    size;
    public:
        LinkedList(); // Default Contructor
       ~LinkedList(); // Destructor
        
         int   sizeOf();
        bool   isEmpty();
        void   insertInOrderOld(T dataIn);           // Insert data in order
        void   insertInOrder(T dataIn);              // Insert data in order
        void   printLinkedList();                    // Print the entire LinkedList
        void   printLinkedListRecursively();         // Print the entire LinkedList recursively
        void   printRecursively(Node * head);        // Helper function of printLinkedListReqursively
        void   printLinkedListRecursivelyReverse();  // Print the entire LinkedList recursively in reverse order
        void   printRecursivelyReverse(Node * head); // Helper function of printLinkedListReqursivelyReverse
        void   removeOld(T dataOut);                 // Remove specific data
        void   remove(T dataOut);                    // Remove specific data
        bool   searchOld(T dataSearch);              // Search linkedList
        bool   search(T dataSearch);                 // Search linkedList
};
#endif
