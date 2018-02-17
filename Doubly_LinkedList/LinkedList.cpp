#include "LinkedList.h"


template<class T>
LinkedList<T>::LinkedList(){

    head = NULL;
    size = 0;
}


template<class T>
LinkedList<T>::~LinkedList(){



}

template<class T>
int LinkedList<T>::sizeOf(){

    return size;

}


template<class T>
bool LinkedList<T>::isEmpty(){

    return (size == 0);

}

template<class T>
void LinkedList<T>::insertHead(T dataNew){


    Node * newNode;
    newNode->dataIn = dataNew;

    if(!head){
 
        head = newNode;
        newNode->next = NULL;
        newNode->prev = NULL;

    } else {

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    } 
}


