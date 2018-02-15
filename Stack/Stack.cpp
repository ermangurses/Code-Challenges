#include "Stack.h"
using namespace std;

template<class T>
Stack<T>::Stack(){

    head = NULL;
    size = 0;
}

template<class T>
Stack<T>::~Stack(){



}

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


template<class T>
void Stack<T>::pop(){

    if(!head){
        return;

    } else {
        Node * temp =  head;
        head = head->next;
        delete temp;
    }
}

template<class T>
bool Stack<T>::isEmpty(){


    return (size == 0);
}

template<class T>
int Stack<T>::sizeOf(){

    return size;

}

template<class T>
void Stack<T>::printStack(){

    if(!head){
    
        return;        

    } else {

        Node * iter = head;

        while(iter != NULL){
        
            cout<<iter->dataIn<<endl;
            iter = iter->next; 
        }
    }
}




