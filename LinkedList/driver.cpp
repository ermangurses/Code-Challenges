#include "LinkedList.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

# define SIZE 16

using namespace std;
/******************************************************************************

  *** bool openInputFile(ifstream & inFile) ***
  
  opens data.txt file 
  
  returns true if the file is opened succesfully
  
  return false if it fails
                       
******************************************************************************/
bool openInputFile(ifstream & inFile) 
{
   inFile.open("data.txt");
   
   if (!inFile)
   {
      cout << "The input File cannot be opened!!!\n";

      return false;
   }
   return true;
}

int main(){

  LinkedList<int> * linkedList = new LinkedList<int>();

  int array[SIZE] = {6,1,2,3,5,4,5,6,7,10,8,10,11,3,4,0};

  /******************************************************************************

    Testing the functions in LinkedList Class

  ******************************************************************************/ 

  for(int i = 0; i < SIZE; i++){
 
      cout<<i<<": "<<array[i]<<"--->"<<linkedList->insertInOrder(array[i])<<endl;
  }
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Remove 6: "<<linkedList->remove(6)<<endl;
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Remove 0: "<<linkedList->remove(0)<<endl;
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Remove 11: "<<linkedList->remove(11)<<endl;
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Remove 1: "<<linkedList->remove(1)<<endl;
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Remove 200: "<<linkedList->remove(200)<<endl;
  cout<<endl<<endl;
  cout<<"Size of "<<linkedList->sizeOf()<<endl;
  cout<<endl<<endl;
  linkedList->printLinkedList();
  
  cout<<"Search  of 6 "<<linkedList->search(6)<<endl;
  cout<<"Search  of 2 "<<linkedList->search(2)<<endl;
  cout<<"Search  of 4 "<<linkedList->search(4)<<endl;
  cout<<"Search  of 10 "<<linkedList->search(10)<<endl;
  cout<<"Search  of 200 "<<linkedList->search(200)<<endl;

  delete linkedList;
  
  cout<<"Is Empty: "<<linkedList->isEmpty()<<endl;
  cout<<"Size: "<<linkedList->sizeOf()<<endl;
  linkedList->printLinkedList();


  /******************************************************************************

    Do the operations in linked list using input.txt file
   
  ******************************************************************************/
  cout<<"**** File Operations Start ****"<<endl;
  LinkedList<int> * linkedList1 = new LinkedList<int>();

  
  ifstream inFile;
  string line;
  
  if(!openInputFile(inFile)){
      return 0;   
  }  

  getline(inFile, line);
  
  cout<<"There will be "<<atoi(line.c_str())<<" elements in the linked list"<<endl;

  getline(inFile, line);
  stringstream ss(line);
  string token;
  
  while(getline(ss, token, ' ')){
      linkedList1->insertInOrder(atoi(token.c_str()));
  }
  linkedList->printLinkedList();
   

  
 return 0;
}
