#include <unordered_set>
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
LinkedList<T>::~LinkedList(){

    while(!isEmpty()){                   
    
        removeHead();

    }
}

/******************************************************************************
//
//
//  The size of the linked list
//
//
*******************************************************************************/
template<class T>
int LinkedList<T>::sizeOf(){

    return size;

}


/******************************************************************************
//
//
//  Is empty
//
//
*******************************************************************************/
template<class T>
bool LinkedList<T>::isEmpty(){

    return (size == 0);

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
        newNode->next = NULL;
        newNode->prev = NULL;

    } else {

        newNode->next = head;
        head->prev = newNode;
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


/******************************************************************************
//
//
//  Remove node from head
//
//
*******************************************************************************/
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


/******************************************************************************
//
//
//  Remove node from tail
//
//
*******************************************************************************/
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

/******************************************************************************
//
//
//  Remove node given data *** new version using previous pointer ***
//
//  1) Linkedlist is empty
//  2) Delete from head
//  3) Delete from middle
//  4) Delete from tail
//
*******************************************************************************/
template<class T>
void LinkedList<T>::remove(T dataOut){

    // 1) Empty list 
    if(!head){

        return;

    } else {

        Node *     iter = head;
        Node * iterPrev = NULL;

        while(iter != NULL){
        
            if(iter->dataIn == dataOut){

                // 2) Remove head
                if(iterPrev == NULL){
                    removeHead();  
                    iter = head;     
                } else {
                    // 3) Remove middle
                    if(iter->next != NULL){
                    
                        Node * temp =  iter;
                        iterPrev->next = iter->next;
                        iter->next->prev = iterPrev;
                        iter = iter->next;
                        delete temp;
                        --size;  
                    } else {
                    // 4) Remove tail
                 
                       removeTail();
                       iter = NULL;
                    }
                }
            } else {
                iterPrev = iter;
                iter     = iter->next;
            }
        }
    }
}

/******************************************************************************
//
//
//  Search linked list given data *** new version using previous pointer ***
//
//
*******************************************************************************/
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


/******************************************************************************
//
//
//  Remove Duplicates Using Hash Set  *** New Version ***
//  
//  Time complexity is O(N) which is linear
//
*******************************************************************************/
template <class T>
void LinkedList<T>::removeDuplicatesUsingHash(){

    if(!head){

        return;

    } else {
       
        unordered_set<T> hashSet;
        typename unordered_set<T>::const_iterator cIt;
        Node * iter = head;
        Node * iterPrev = NULL;        

        while(iter != NULL){
         
            cIt = hashSet.find(iter->dataIn);
            
            // If there is no data in the set, insert it         
            if(cIt == hashSet.end()){

                hashSet.insert(iter->dataIn);            
                iterPrev = iter;
                iter = iter->next;
            } else {

                if(iter->next != NULL){
                        
                    iterPrev->next = iter->next;
                    iter->next->prev = iterPrev;
                    delete iter;
                    iter = iterPrev->next;

                } else { 
                    
                    iterPrev->next = NULL;                    
                    delete iter; 
                    iter =  NULL;
                }
                --size;
            }
        }        
    }
}

/******************************************************************************
//
//
//  Print Linked List
//
//
*******************************************************************************/
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
