#include "LinkedList.h"

using namespace std;

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


    Node * newNode = new Node;
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
    ++size;
}

template<class T>
void LinkedList<T>::insertTail(T dataNew){

    Node * newNode  = new Node;
    newNode->dataIn = dataNew;

    newNode->next = NULL;
    newNode->prev = NULL;

    if(!head){

        head = newNode;

    } else {

        Node * iter = head;
        
        while(iter->next != NULL){

            iter = iter->next;
        }
        iter->next = newNode; 
        newNode->prev = iter;   
    }
    ++size;
}

template<class T>
void LinkedList<T>::removeHead(){


    if(!head){

        return;

    } else {

        if(head->next == NULL){
  
           delete head;
           head = NULL;
        } else {

            Node * temp = head;
            head = head->next;
            delete temp;
            head->prev = NULL;
        }
    }
    --size;
}
template<class T>
void LinkedList<T>::removeTail(){

    if(!head){

        return;
  
    } else {
        
        if(head->next == NULL){
           
            delete head;
            head = NULL;
        } else {

            Node *     iter = head;
            Node * iterPrev = NULL;
        
            while(iter->next != NULL){
   
               iterPrev = iter;
               iter = iter->next;             
            }
            delete iter;
            iterPrev->next = NULL;
        }
        --size; 
    }
}

template<class T>
void LinkedList<T>::remove(T dataOut){

    // 1) Empty list 
    if(!head){

        return;

    } else {

        Node *     iter = head;
        Node * iterPrev = NULL;

        while(iter != NULL && iter->dataIn != dataOut){

            iterPrev = iter; 
            iter     = iter->next;
        }
        if(iter != NULL && iter->dataIn == dataOut){

            // 2) Remove head
            if(iterPrev == NULL){

                removeHead();       
         
            } else {
                // 3) Remove middle
                if(iter->next != NULL){
                    
                    Node * temp =  iter;
                    iterPrev->next = iter->next;
                    iter->next->prev = iterPrev;
                    delete iter;
                    --size;  
                } else {
                // 4) Remove tail
                 
                    removeTail();
                }
            }
        }
    }
}

template <class T>
bool LinkedList<T>::search(T dataSearch){
    // 1) Empty linked list 
    if(!head){

        return false;
 
    } else {

        Node * iter = head;
        Node * iterPrev = NULL;

        while(iter != NULL && iter->dataIn != dataSearch){
        
            iterPrev = iter;
            iter = iter->next;
        }

        if(iter != NULL && iter->dataIn == dataSearch){
        
            return true;    
        }
    }
    return false;
}

template <class T>
void LinkedList<T>::printLinkedList(){

    if(!head){

        cout<<"Linked List is empty"<<endl;
        return;

    } else {

        Node * iter = head;

        while(iter != NULL){
        
            cout<<iter->dataIn<<endl;
            iter = iter->next;
        }
    }
}


