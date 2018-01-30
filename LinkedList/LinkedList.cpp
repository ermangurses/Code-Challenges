#include "LinkedList.h"


/*

  Default Costructor 

*/

template <class DataType>
LinkedList<DataType>::LinkedList(){

      head = NULL;
      size = 0;
}

/*

  Destructor

*/
template <class DataType>
LinkedList<DataType>::~LinkedList(){
    Node * iter = head;
    Node * temp = head;
    while(iter != NULL){
      
        iter = iter->next;
        delete temp;
        temp = iter;
        size--;
        cout<<size<<endl;
    }
    head = NULL;
}

/*

  The size of the link 

*/
template <class DataType>
int LinkedList<DataType>::sizeOf(){

    return size;
}

/*

  Is empty

*/
template <class DataType>
bool LinkedList<DataType>::isEmpty(){

    return (size == 0);
}

/*

  Insert in order

  There are four cases:
  
  1) LinkedList is empty
  2) Insert head
  3) Insert tail
  4) Insert middle
   
  *** Do not allow duplicate data ***
  return true if the newNode is interted
  return false if the data of newNode is already exist in the linkedlist
*/

template <class DataType>
bool LinkedList<DataType>::insertInOrder(DataType newDataIn){

    // Init the key and data
    Node * newNode = new Node;
    newNode->dataIn = newDataIn;
    Node * iter = head;

    // 1) LinkedList is empty
    if(head == NULL){
        head = newNode;        
        newNode->next = NULL;
        size++;
      return true;
    }
  
    // 2) Insert newNode to head 
    // newNode becomes a head since
    // the new data is the smallest
    if(iter->dataIn > newDataIn){
  
        newNode->next = iter;
        head = newNode;
        size++;
      return true;
    } else if(iter->dataIn == newDataIn){
    
      // duplicated data 
      delete newNode;
      return false;
 
    }
   
    // Iterate over linkedlist
    while(iter->next != NULL && iter->next->dataIn < newDataIn){

        iter = iter->next;
    }
  
    if(iter->next != NULL && iter->next->dataIn == newDataIn){
     
      // Duplicated data
      delete newNode;
      return false;
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
  return true;
}
/*


 PrintLinkedList


*/
template<class DataType>
void LinkedList<DataType>::printLinkedList(){
        
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

/*

 Delete a node from linkedlist
 
 return true 
     if it is deleted
 return false 
    if it is not deleted
 
 1) Linkedlist is empty
 2) Delete from head
 3) Delete from middle
 4) Delete from tail
 
*/
template<class DataType>
bool LinkedList<DataType>::remove(DataType dataOut){

    if (head == NULL){
        return false;
    }
    Node * iter = head;
    // 1) Delete from head
    if(iter->dataIn == dataOut){ 
        head = iter->next;    
        delete iter;
        size--;
      return true;
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
        return true;
    }else{
        return false;
    }
}
/*

    search data in the linkedList

    return true 
	if the data is in the linkedList
    return false 
	if the data is not in the linkedlist

*/
template<class DataType>
bool LinkedList<DataType>::search(DataType dataSearch){
  
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
