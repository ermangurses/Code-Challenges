#include <exception>
#include <unordered_set>
#include "LinkedList.h"
/*


Default Constructor


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
    head = NULL;
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
/*


--- nthToLast ---

It finds n th element to the last and returns its value

For instance:

 - 9 nodes below form a linked list below,
 - We numbered them increasing  order from head
 - if "n" is 3, we need to return 7 th element 
   from the list                       
 - if "n" is 1, we need to return the last element
   from the list

 head                k
   |                 3  2  1
   |
   1  2  3  4  5  6  7  8  9
   O--O--O--O--O--O--O--O--O            
*/

template<class DataType> 
DataType LinkedList<DataType>::nthToLast(int n){

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

/*

 *** deleteMiddleNode*** 
 
 It is a wrapper function to send pointer to the deleteNode
 

*/
template<class DataType>
bool LinkedList<DataType>::deleteMiddleNode(){
 
    if(head == NULL || head->next == NULL){

        return false;
    }
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
/*

***deleteNode***

It deletes the node that has only access to that node
so no head access in here
*/
template<class DataType>
bool LinkedList<DataType>::deleteNode(Node * node){
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
