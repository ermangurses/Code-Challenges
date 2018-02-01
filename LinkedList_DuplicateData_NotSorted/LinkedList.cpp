#include "LinkedList.h"



/*


Constructor


*/
template<class DataType>
LinkedList<DataType>::LinkedList(){
 
  head = NULL;

}
/*


Destructor


*/
template<class DataType>
LinkedList<DataType>::~LinkedList(){

    Node * iter = head;
    Node * temp = head;

    while(iter != NULL){
        
        iter = iter-next;
        delete temp;
        temp = iter;
    }
}
/*


Insert head


*/
template<class DataType>
bool LinkedList<DataType>::insertHead(DataType dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;

    if(head == NULL){

        head = newNode;
        newNode->next = NULL;
    }else{

       newNode->next = head;
       head = newNode;
    }

  return true;
}
/*


Insert tail


*/
template<class DataType>
bool LinkedList<DataType>::insertTail(DataType dataNew){

    Node * newNode = new Node;
    newNode->dataIn = dataNew;
    newNode->next = NULL;
    
    if(head == NULL){

      head = newNode;
    }
 
    Node * iter = head;
    while(iter->next != NULL){
        iter = iter->next;
    }

    iter->next = newNode;
  return true;   
}

/*


remove head


*/
template<class DataType>
bool LinkedList<DataType>::removeHead(){

    if(head == NULL){
        return false;
    }

    Node * temp = head;
    head = head->next;
    delete temp;
  return true;    
}

/*


Remove tail


*/
template<class DataType>
bool LinkedList<DataType>::removeTail(){

   if(head == NULL){

     return false;
   }

   if(head->next == NULL){

       delete head;
     return true;
   }

   Node * iter = head;

   while(iter->next->next != NULL){
   
       iter = iter->next;
   }

   delete iter->next;
   iter->next = NULL;
}

/*


remove


*/
template<class DataType>
bool LinkedList<DataType>::remove(DataType dataOut){

    if(head == NULL){

      return false;
    }

    Node * iter = head;
    
    if(head->dataIn == dataOut){
        head = iter->next;
        delete iter;
      return true;    
    }
  
    while(iter->next != NULL && iter->next->dataIn != dataOut){
        iter = iter-next;                        
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
        return true;
    }else{
        return false;
    }
}

template<class DataType>
bool LinkedList<DataType>::search(DataType dataSearch){

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
template<class DataType>
void LinkedList<DataType>::printLinkedList(){

    if(head == NULL){

        cout<<"LinkedList is empty!!!"<<endl;
    }

    Node * iter = head;
 
    while(iter != NULL){
 
        cout<<iter->dataIn<<endl;
        iter = iter->next;
    }
}
