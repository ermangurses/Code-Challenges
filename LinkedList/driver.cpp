#include "LinkedList.cpp"
#include <iostream>
#include <iomanip>
# define SIZE 16

using namespace std;

int main(){

  LinkedList<int> * linkedList = new LinkedList<int>();
  int array[SIZE] = {6,1,2,3,5,4,5,6,7,10,8,10,11,3,4,0};
  
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
 return 0;
}
