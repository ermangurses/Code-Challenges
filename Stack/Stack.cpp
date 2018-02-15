#include "Stack.h"
using namespace std;

/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/
template<class T>
Stack<T>::Stack(){

    head = NULL;
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
Stack<T>::~Stack(){

    T temp;
 
    while(!isEmpty()){
        pop(temp);
    }
}

/******************************************************************************
//
//
//  push
//
//
*******************************************************************************/
template<class T>
void Stack<T>::push(T dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;
    
    if(!head){
    
        head = newNode;
        newNode->next = NULL;        

    } else {

        newNode->next = head;
        head = newNode;
    }
    ++size;
}

/******************************************************************************
//
//
//  pop
//
//
*******************************************************************************/
template<class T>
void Stack<T>::pop(T & dataOut){

    if(!head){
        return;

    } else {
        Node * temp =  head;
        dataOut = temp->dataIn;
        head = head->next;
        delete temp;
        --size;
    }
}

/******************************************************************************
//
//
//  top
//
//
*******************************************************************************/
template<class T>
void Stack<T>::top(T &temp){

    if(!head){

        cout<<"Stack is empty!!!"<<endl;
        return;
    } else {

        temp =  head->dataIn;
    }
}
/******************************************************************************
//
//
//  Is empty
//
//
*******************************************************************************/
template<class T>
bool Stack<T>::isEmpty(){


    return (size == 0);
}

/******************************************************************************
//
//
//  The size of the linked list
//
//
*******************************************************************************/
template<class T>
int Stack<T>::sizeOf(){

    return size;

}

/******************************************************************************
//
//
//  Print Stack
//
//
*******************************************************************************/
template<class T>
void Stack<T>::printStack(){

    if(!head){
        
        cout<<"Stack is empty!!!"<<endl;
        return;        

    } else {

        Node * iter = head;

        while(iter != NULL){
        
            cout<<iter->dataIn<<endl;
            iter = iter->next; 
        }
    }
}




