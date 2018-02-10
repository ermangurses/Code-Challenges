#include "LinkedList.h"


/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/

using namespace std;

template <class T>
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
template <class T>
LinkedList<T>::~LinkedList(){
    Node * iter = head;
    Node * temp = head;
    while(iter != NULL){
      
        iter = iter->next;
        delete temp;
        temp = iter;
        size--;
    }
    head = NULL;
}

/******************************************************************************
//
//
//  The size of the link 
//
//
*******************************************************************************/
template <class T>
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
template <class T>
bool LinkedList<T>::isEmpty(){

    return (size == 0);
}
/******************************************************************************
//
//  Insert in order  *** old version ***
//
//  There are four cases:
//  
//  1) LinkedList is empty
//  2) Insert head
//  3) Insert tail
//  4) Insert middle
//   
//  *** Does not allow duplicate data ***
//  return true if the newNode is interted
//  return false if the data of newNode is already exist in the linkedlist
*******************************************************************************/

template <class T>
void LinkedList<T>::insertInOrderOld(T newDataIn){


    // Init the key and data
    Node * newNode = new Node;
    newNode->dataIn = newDataIn;
    Node * iter = head;

    // 1) LinkedList is empty
    if(head == NULL){
        head = newNode;
        newNode->next = NULL;
        size++;
        return;
    }
    // 2) Insert newNode to head 
    // newNode becomes a head since
    // the new data is the smallest
    if(iter->dataIn > newDataIn){
        newNode->next = iter;
        head = newNode;
        size++;
        return;
    } else if(iter->dataIn == newDataIn){
    
      // duplicated data 
      delete newNode;
      return;
    }
   
    // Iterate over linkedlist
    while(iter->next != NULL && iter->next->dataIn < newDataIn){

        iter = iter->next;
    }
  
    if(iter->next != NULL && iter->next->dataIn == newDataIn){
     
      // Duplicated data
      delete newNode;
      return;
    }

    // 3) Insert newNode to tail  
    // If we reach end of the linkedlist     
    if(iter->next == NULL){

       iter->next  = newNode;
       newNode->next = NULL;
     }else{
    // 4) Insert newNode into middle
       Node * temp = iter->next;
       iter->next = newNode;
       newNode->next = temp;
     }
     size++;
     return;
}
/******************************************************************************
//
//  Insert in order ********* used previous pointer ***********
//
//  There are four cases:
//  
//  1) LinkedList is empty
//  2) Insert head
//  3) Insert tail
//  4) Insert middle
//   
//  *** Does not allow duplicate data ***
//  return true if the newNode is interted
//  return false if the data of newNode is already exist in the linkedlist
*******************************************************************************/
template<class T>
void LinkedList<T>::insertInOrder(T newDataIn){
     
     Node * iter;
     Node * previous;
     Node * newNode = new Node;
     newNode->dataIn = newDataIn;
     
    // 1) Linkedlist is empty
    if(!head){        
        head = newNode;
        newNode->next = NULL;
        size++;
    }else{
        iter = head;
        previous = NULL;
        while(iter != NULL && iter->dataIn < newDataIn){
           
            previous = iter;
            iter = iter->next;
        }

        // Duplicate Data
        if(iter != NULL && newDataIn == iter->dataIn){
            delete newNode;
            return;
        }

        // 2) Insert head       
        if(previous == NULL){
            newNode->next = head;
            head = newNode; 
            size++;
            return;   
        }

        previous->next = newNode; 
        // 3) Insert tail
        if(iter == NULL){
            newNode->next = NULL;
        } else { // Insert middle
            newNode->next = iter;
        }       
        size++; 
    }
}
/******************************************************************************
//
//
// PrintLinkedList
//
//
*******************************************************************************/
template<class T>
void LinkedList<T>::printLinkedList(){

    Node * iter;
    if(head == NULL){
    
        cout<<"LinkedList is empty!"<<endl;
        return;
    }else{
        iter = head;
        while(iter != NULL){  
            cout<<iter->dataIn<<endl;
            iter = iter->next;
        }
    }
}

/******************************************************************************
//
// Delete a node from linkedlist
// 
// return true 
//     if it is deleted
// return false 
//     if it is not deleted
// 
// 1) Linkedlist is empty
// 2) Delete from head
// 3) Delete from middle
// 4) Delete from tail
// 
*******************************************************************************/
template<class T>
void LinkedList<T>::remove(T dataOut){

    if (head == NULL){
        return;
    }
    Node * iter = head;
    // 1) Delete from head
    if(iter->dataIn == dataOut){ 
        head = iter->next;    
        delete iter;
        size--;
      return;
    }   

    // Go until the dataOut is larger than element of
    // linkedlist
    while(iter->next != NULL && iter->next->dataIn < dataOut){
        iter = iter->next;    
    }
    // 2) Delete from middle
    // 3) Delete from tail
    // if data is found
    if(iter->next != NULL && iter->next->dataIn == dataOut){
        // 2) Delete from middle
        if(iter->next->next != NULL){
            Node * temp = iter->next->next; 
            delete iter->next;
            iter->next = temp;
        }else{
            // 3) Delete from tail
            delete iter->next;
            iter->next = NULL;
        }
        size--;
    }
}
/******************************************************************************
//
//    search data in the linkedList
//
//    return true 
//	if the data is in the linkedList
//    return false 
//	if the data is not in the linkedlist
//
*******************************************************************************/
template<class T>
bool LinkedList<T>::search(T dataSearch){
  
    if (head == NULL){
        return false;
    }
    
    Node * iter  = head;
    
    if(iter->dataIn == dataSearch){
      return true;
    }
  
    while(iter->next != NULL && iter->next->dataIn < dataSearch){
        iter = iter->next;
    }
    
   if(iter->next != NULL && iter->next->dataIn == dataSearch){
       return true;
    }else{
       return false;
    }
}
