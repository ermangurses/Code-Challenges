#include "LinkedList.cpp"
#include <iostream>
#define SIZE 16

using namespace std;


int main(){

  LinkedList<int> * linkedList = new LinkedList<int>();
  
  //////////////////////////////////////////////////////////
  int array[SIZE] = {6,1,2,3,5,4,5,6,7,10,8,10,11,3,4,0};

  cout<<"Insert Tail"<<endl;
  for(int i = 0; i < SIZE; ++i){
      cout<<i<<": "<<array[i]<<"--->"<<linkedList->insertTail(array[i])<<endl;
  }

  cout<<endl<<"LinkedList is here!!!"<<endl<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;
 
  int counter = 0;
  while(linkedList->removeHead()){
    counter++; 
    cout<<counter<<" Node Removed"<<endl;
  }

  cout<<endl<<endl; 
  
  linkedList->printLinkedList();
  /////////////////////////////////////////////////////////
  cout<<"Insert Head"<<endl;  
  for(int i = 0; i < SIZE; ++i){
   
      cout<<i<<": "<<array[i]<<"--->"<<linkedList->insertHead(array[i])<<endl;
  }
  
  cout<<"LinkedList is here!!!"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;

  while(linkedList->removeTail()){
      
      cout<<"Tail Removed"<<endl;
      linkedList->printLinkedList();
 
      cout<<endl<<endl;             
      if(linkedList->search(8)){
          if(linkedList->remove(8)){
              cout<<"8 is removed"<<endl;
          }
      }
      cout<<endl<<endl;
        
      cout<<"Head Removed"<<endl;
      linkedList->removeHead();

      linkedList->printLinkedList();
 
      cout<<endl<<endl;
  }

  delete linkedList;
return 0;
}
