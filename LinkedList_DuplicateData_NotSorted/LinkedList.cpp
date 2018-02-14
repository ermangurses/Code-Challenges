#include <exception>
#include <unordered_set>
#include "LinkedList.h"
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

    Node * iter = head;
    Node * temp = head;

    while(iter != NULL){
        
        iter = iter->next;
        delete temp;
        temp = iter;

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
void LinkedList<T>::insertTail(T dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;
    newNode->next = NULL;
    
    if(!head){

        head = newNode;

    } else {
 
        Node * iter = head;
        while(iter->next != NULL){
            iter = iter->next;
        }
        iter->next = newNode;
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
    
        Node * temp = head;
        head = head->next;
        delete temp;
        --size;
    }
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

            Node * iter = head;
            Node * previous = NULL;

            while(iter->next != NULL){
                previous = iter;
                iter = iter->next;
            }
            delete iter;
            previous->next = NULL;

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

    // 1) Linkedlist is empty
    if(!head){

        return;
    } else {
        
        Node * iter = head;
        Node * prev = NULL;
        
        while(iter != NULL && iter->dataIn != dataOut){
            
            prev = iter;
            iter = iter->next;
        }

        if(iter != NULL && iter->dataIn == dataOut){
        
            // 2) Delete from head
            if(prev == NULL){

              head = iter->next;
              delete iter;
          
            } else {
                  
                // 3) Delete from middle
                if(iter->next != NULL){
                
                  prev->next = iter->next;
                  delete iter;

                } else {  
                // 4) Delete from tail  
                
                   delete iter;
                   prev->next = NULL;
                }
            }
            --size;
        }
    }
}
/******************************************************************************
//
//
//  Remove node given data  *** old version ***
//
//
*******************************************************************************/
template<class T>
void LinkedList<T>::removeOld(T dataOut){

    if(!head){
    
        return;
    
    } else {

        Node * iter = head;
    
        if(head->dataIn == dataOut){
            head = iter->next;
            delete iter;
        }
  
        while(iter->next != NULL && iter->next->dataIn != dataOut){
            iter = iter->next;                        
        }

        if(iter->next != NULL && iter->next->dataIn == dataOut){
        
            if(iter->next->next != NULL){
   
                Node * temp  = iter->next->next;
                delete iter->next;
                iter->next = temp;
            }else{
                delete iter->next;
                iter->next = NULL;
            }        
        }
        --size;
    }
}

/******************************************************************************
//
//
//  Search linked list given data *** new version using previous pointer ***
//
//
*******************************************************************************/
template<class T>
bool LinkedList<T>::search(T dataSearch){

    if(!head){

        return false;
    } else {
    
        Node * iter = head;
        Node * prev = NULL;
        while(iter != NULL && iter->dataIn != dataSearch){

             prev = iter;
             iter = iter->next;
        }

        if(iter != NULL  && iter->dataIn == dataSearch){

             return true;
        }
    }
    return false;
}
/******************************************************************************
//
//
//  Search linked list given data  *** old version ***
//
//
*******************************************************************************/
template<class T>
bool LinkedList<T>::searchOld(T dataSearch){

    if(head == NULL){

        return false;
    }
    Node * iter =  head;
   
    while(iter != NULL && iter->dataIn != dataSearch){
 
        iter = iter->next;
    }
    
    if(iter != NULL){

        if(iter->dataIn == dataSearch){
            return true;
        }else{
            return false;
        }
    }else{
           return false;
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

    if(head == NULL){

        cout<<"LinkedList is empty!!!"<<endl;
    }

    Node * iter = head;
 
    while(iter != NULL){
 
        cout<<iter->dataIn<<endl;
        iter = iter->next;
    }
}


/******************************************************************************
//
//  Remove duplicates from linked list
//  
//  The time complexity is O(N^2)
//
//
*******************************************************************************/
template<class T>
bool LinkedList<T>::removeDuplicates(){

    if(head == NULL || head->next == NULL){

      return false;
    }
    
    Node * iter1 = head;
    Node * iter2 = head;
    int count = 0;   
    while(iter1->next != NULL){
        
        while(iter2->next != NULL){
           
            if(iter2->next->dataIn == iter1->dataIn){
 
                Node * temp = iter2->next;
                iter2->next = iter2->next->next;
                delete temp;
                temp = NULL;
            }else{
                iter2 = iter2->next;
            }           
        }
        iter1 = iter1->next;
        if(iter1 == NULL){
            break;
        }
        iter2 = iter1;
    }
    return true;
}

/******************************************************************************
//
//
//  Remove Duplicates Using Hash Set
//  
//  Time complexity is O(N) which is linear
//
*******************************************************************************/

template<class T>
bool LinkedList<T>::removeDuplicatesUsingHash(){

    unordered_set<T> hashSet;
    typename  unordered_set<T>::const_iterator cIter;

    // Check wheter LL is empty or not
    if (head == NULL){
        return false; 
    }
    Node * iter = head;
     
    // Insert the first element of the 
    hashSet.insert(head->dataIn);
   
    while(iter->next != NULL){
         
        cIter = hashSet.find(iter->next->dataIn);
        
        // If there is no data in the set, insert it
        if(cIter == hashSet.end()){

            hashSet.insert(iter->next->dataIn); 
            iter = iter->next;    

        }else{
            // If there is data, which means duplicate data
            
            Node * temp = iter->next;
            iter->next = iter->next->next;
            delete temp;
        }
    }
    return true;
}


/******************************************************************************


--- nthToLast ---

It finds n th element to the last and returns its value

For instance:

 - 9 nodes below form a linked list below,
 - We numbered them increasing  order from head
 - if "n" is 3, we need to return 7 th element 
   from the list                       
 - if "n" is 1, we need to return the last element
   from the list

 head                n
   |                 3  2  1
   |
   1  2  3  4  5  6  7  8  9
   O--O--O--O--O--O--O--O--O            
*******************************************************************************/
template<class T> 
T LinkedList<T>::nthToLast(int n){

    if(head == NULL){
        //non-existent element so we terminate
        cout<<"Empty linkedlist"<<endl;
        terminate();
    }
    Node * iter1 = head;
    Node * iter2 = head;
    
    int counter = 1;
     
    while(counter < n){
        
        if(iter2->next == NULL){
        
            cout<<n<<" is larger than the size of linkedlist"<<endl;
            terminate();
        }
        counter++;
        iter2 = iter2->next;
    }

    while(iter2->next != NULL){

        iter1 = iter1->next;
        iter2 = iter2->next;
    }
    return iter1->dataIn;
}

/******************************************************************************

 *** deleteMiddleNode*** 
 
 It reache
 It is a wrapper function to send pointer to the deleteNode
 

*******************************************************************************/
template<class T>
bool LinkedList<T>::removeMiddleNode(){
 
    if(head == NULL || head->next == NULL){

        return false;
    }
  //  if(size )   

    Node * iter = head;
        
    const int middle = 5;
    int counter = 1;

    while(counter < middle){ 
  
       // Check if the middle number larger than size of linked list
       if(iter->next == NULL){
             cout<<middle<<" is larger than the size of linkedlist"<<endl;
             return false;
       }
  
       counter++;
       iter = iter->next;
    }
    bool result = deleteNode(iter);    
    return result;
} 
/******************************************************************************

*** deleteNode ***

It deletes the node that has only access to that node so no head access in here
*******************************************************************************/


template<class T>
bool LinkedList<T>::deleteNode(Node * node){
    Node * iter = node;

    // Copy the element to its previous neighbor
    while(iter->next->next != NULL){
       iter->dataIn = iter->next->dataIn;
       iter = iter->next;
    }
    
    // do the last copy from tail to tail-1
    iter->dataIn = iter->next->dataIn;   
   
    // delete the tail
    delete iter->next;
    iter->next = NULL;
  return true;
}
