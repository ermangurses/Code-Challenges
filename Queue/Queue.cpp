# include "Queue.h"

using namespace std;

/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/
template<class T>
Queue<T>::Queue(){

    head = NULL;
    tail = NULL;
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
Queue<T>::~Queue(){

    T tempType;

    while(dequeue(tempType));


}
/******************************************************************************
//
//
//  The size of the Queue
//
//
*******************************************************************************/
template<class T>
int Queue<T>::sizeOf(){

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
bool Queue<T>::isEmpty(){

    return (size == 0);


}

/******************************************************************************
//
//
//  Enqueue
//
//
*******************************************************************************/
template<class T>
void Queue<T>::enqueue(T newData){

    Node * newNode = new Node;
    newNode->dataIn = newData;
    newNode->next = NULL; 
     
    if(!head){
    
        head = newNode;

    } else {

       tail->next = newNode;

   }
   tail = newNode;
   ++size;
}

/******************************************************************************
//
// 
// Dequeue
//
//
*******************************************************************************/
template<class T>
bool Queue<T>::dequeue(T & dataOut){

    if(!head){

        return false;  
 
    } else {
        
        Node * temp = head;
        dataOut = temp->dataIn;
        head = head->next;
        if(tail == temp){
        
            tail = NULL;
        
        }
        delete temp;
        --size;
        return true;
   }
}

/******************************************************************************
//
// 
// printQueue
//
//
*******************************************************************************/
template<class T>
void Queue<T>::printQueue(){

    Node * iter = head;

    while(iter != NULL){
 
        cout<<" "<<iter->dataIn<<endl;
        iter = iter->next;
    }
}
