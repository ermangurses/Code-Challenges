#include "DoubleLinkedList.h"

using namespace std;
/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/
template<class T>
DoubleLinkedList<T>::DoubleLinkedList(){
 
  head = nullptr;
  size = 0;

}
/******************************************************************************
//
//
//  Destructor
//
//
*******************************************************************************/
template<class T>
DoubleLinkedList<T>::~DoubleLinkedList(){

    Node * iter = head;
    Node * temp = head;

    while(iter != nullptr){
        
        iter = iter->next;
        delete temp;
        temp = iter;

    }
    head = nullptr;
}

/******************************************************************************
//
//
//  Insert node to head
//
//
*******************************************************************************/
template<class T>
void DoubleLinkedList<T>::insertHead(T dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;

    if(!head){

        head = newNode;
        newNode->next = nullptr;

    } else {

       newNode->next = head;
       head = newNode;
    }
    ++size;
}


/******************************************************************************
//
//
//  Insert node to tail
//
//
*******************************************************************************/
template<class T>
void DoubleLinkedList<T>::insertTail(T dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;
    newNode->next = nullptr;
    
    if(!head){

        head = newNode;

    } else {
 
        Node * iter = head;
        while(iter->next != nullptr){
            iter = iter->next;
        }
        iter->next = newNode;
   }
}

/******************************************************************************
//
//
//  Print Linked List
//
//
*******************************************************************************/
template<class T>
void DoubleLinkedList<T>::printLinkedList(){

    if(head == nullptr){
        cout<<"LinkedList is empty!!!"<<endl;
    }
    Node * iter = head;
 
    while(iter != nullptr){
        cout<<iter->dataIn<<endl;
        iter = iter->next;
    }
}
