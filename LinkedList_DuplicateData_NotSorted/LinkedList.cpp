#include "LinkedList.h"
#include <unordered_set>

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
        
        iter = iter->next;
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
      return true;
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
        head = NULL;
      return true;
    }

    Node * iter = head;

    while(iter->next->next != NULL){
   
        iter = iter->next;
    }
    delete iter->next;
    iter->next = NULL;
  return true;
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
        return true;
    }else{
        return false;
    }
}
/*


  Search operation given data "dataSearch"



*/
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
/*


 Print the linkedList


*/
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
/*


 remove duplicates from LL
 The time complexity is O(N^2)


*/
template<class DataType>
bool LinkedList<DataType>::removeDuplicates(){

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
/*

remove Duplicates Using Hash
Time complexity is O(N) which is linear

*/
template<class DataType>
bool LinkedList<DataType>::removeDuplicatesUsingHash(){

    unordered_set<DataType> hashSet;
    typename  unordered_set<DataType>::const_iterator cIter;

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
