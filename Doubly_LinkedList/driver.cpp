#include "LinkedList.cpp"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unistd.h>

#define SIZE 16
#define SIZE1 9
using namespace std;

/******************************************************************************
  
  *** bool openInputFile(ifstream & inFile) ***
    
  opens data.txt file 
    
  returns true if the file is opened succesfully
    
  return false if it fails                        
******************************************************************************/

bool openInputFile(ifstream & inFile){

    inFile.open("data.txt");

    if(!inFile){
        
        cout<< "The input file cannot be opened!!!\n";

        return false;
    }
    return true;
}

int main(){

    LinkedList<int> * linkedList = new LinkedList<int>();

  //////////////////////////////////////////////////////////
  int array[SIZE] = {6,1,2,3,5,4,5,6,7,10,8,10,11,3,4,0};

  cout<<"*** Insert Tail:"<<endl;
  for(int i = 0; i < SIZE; ++i){
      cout<<i+1<<": Inserted ----> "<<array[i]<<endl;
      linkedList->insertTail(array[i]);
  }

  cout<<endl<<"*** Now the LinkedList is:"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;
 
  int counter = 1;
  while(!linkedList->isEmpty()){
    linkedList->removeHead();
    cout<<counter++<<" Node Removed from head"<<endl;
  }
  cout<<endl<<endl; 
  
  cout<<"*** LinkedList is here:"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;
 
  /////////////////////////////////////////////////////////
  cout<<"*** Insert Head:"<<endl;  
  for(int i = 0; i < SIZE; ++i){
      cout<<i+1<<": Inserted ----> "<<array[i]<<endl;
      linkedList->insertHead(array[i]);
  }
  
  cout<<"*** LinkedList is here:"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;

  while(!linkedList->isEmpty()){

      linkedList->removeTail();
      cout<<"*** Tail Removed:"<<endl;
      linkedList->printLinkedList();

      cout<<endl<<endl;             
      if(linkedList->search(0)){
          linkedList->remove(0);
          cout<<"0 is removed"<<endl;
          
      }
      cout<<endl<<endl;
      
      cout<<endl<<endl;
      if(linkedList->search(8)){
          linkedList->remove(8);
          cout<<"8 is removed"<<endl;
 
      }
      cout<<endl<<endl;

      cout<<endl<<endl;
      if(linkedList->search(1)){
          linkedList->remove(1);
           cout<<"1 is removed"<<endl;
 
      }
      cout<<endl<<endl;
  
      linkedList->removeHead();
      cout<<"*** Head Removed: "<<endl;
      linkedList->printLinkedList();
      cout<<endl<<endl;
  }  
  ///////////////////////////////////////////////////////
 
  /*int array1[SIZE] = {1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8};
  int array2[SIZE] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
  int array3[SIZE] = {1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2};
  int array4[SIZE] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16}; 
  int array5[SIZE1] = {1,1,2,2,3,3,4,4,5};
  int array6[SIZE1] = {1,2,2,3,3,4,4,5,5}; */
  int array7[SIZE1] = {1,1,2,2,3,4,4,5,5};
  cout<<"***Insert Tail***"<<endl;
  
  for(int i = 0; i < SIZE1; ++i){
      cout<<i<<": "<<array7[i]<<"---> is inserted"<<endl;
      linkedList->insertTail(array7[i]);
  } 
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;
 
  linkedList->removeDuplicatesUsingHash();
 
  linkedList->insertTail(6);
  linkedList->insertTail(7);
  linkedList->insertTail(8);
  linkedList->insertTail(9);
 
  cout<<"*** Removed duplicates and added 6, 7, 8, 9:"<<endl;
  
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList->printLinkedList();
  cout<<endl<<endl;

 
  delete linkedList;
  cout<<"*** LinkedList is deleted:"<<endl;
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList->printLinkedList();

  /******************************************************************************
 
     Do the operations in linked list using input.txt file
    
  ******************************************************************************/
  cout<<endl<<endl;
  cout<<"**** File Operations Start ***"<<endl;  
  LinkedList<int> * linkedList1 = new LinkedList<int>();

  ifstream inFile;
  string line;  

  if(!openInputFile(inFile)){
      return 0;
  }

  getline(inFile, line);
  cout<<"There will be "<<atoi(line.c_str())*2<<" elements in the linked list"<<endl;
  
  getline(inFile, line);
  stringstream ss(line); 
  string token;


  while(getline(ss, token, ' ')){

      cout<<token<<" ***Inserted to Tail***"<<endl<<endl;
      linkedList1->insertTail(atoi(token.c_str()));
      linkedList1->printLinkedList();
      cout<<endl<<endl;
   
      usleep(1000);

      cout<<token<<" ***Inserted to Head***"<<endl<<endl;
      linkedList1->insertHead(atoi(token.c_str()));
      linkedList1->printLinkedList();
      cout<<endl<<endl;
   
      usleep(1000);
  }
 
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  cout<<"10 is removed"<<endl;
  linkedList1->remove(10);  
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  cout<<"22 is removed"<<endl;
  linkedList1->remove(22);
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  cout<<"44 is removed"<<endl;
  linkedList1->remove(44);
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  cout<<"334 is removed"<<endl;
  linkedList1->remove(334);
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  cout<<"122 is removed"<<endl;
  linkedList1->remove(122);
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  cout<<endl<<endl;

  delete linkedList1;
  cout<<"*** LinkedList is deleted:"<<endl;
  cout<<"*** Now the LinkedList is:"<<endl;
  linkedList1->printLinkedList();
  


return 0;
}
