#include "LinkedList.h"

using namespace std;
/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/
template<class T>
LinkedList<T>::LinkedList(){
 
  head = nullptr;

}
/******************************************************************************
//
//
//  Destructor
//
//
*******************************************************************************/
template<class T>
LinkedList<T>::~LinkedList(){

    Node * iter = head;
    Node * temp;

    while(iter->next != nullptr){
        temp = iter;
        iter = iter->next;
        delete temp;
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
void LinkedList<T>::insertHead(T dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;   

    if(!head){
        
        head = newNode;
        newNode->next = nullptr;
    
    } else {

        newNode->next = head;
        head = newNode;
    }
}
/******************************************************************************
//
//
//  Insert node to tail
//
//
*******************************************************************************/
template<class T>
void LinkedList<T>::insertTail(T dataNew){

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
void LinkedList<T>::printLinkedList(){

    if(head == nullptr){
        cout<<"LinkedList is empty!!!"<<endl;
    }
    Node * iter = head;
 
    while(iter != nullptr){
        cout<<iter->dataIn<<endl;
        iter = iter->next;
    }
}
