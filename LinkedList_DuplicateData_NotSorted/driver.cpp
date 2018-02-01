#include "LinkedList.cpp"
#include <iostream>
# define SIZE 16

using namespace std;


int main(){

  LinkedList<int> * linkedList = new LinkedList<int>();

  int array[SIZE] = {6,1,2,3,5,4,5,6,7,10,8,10,11,3,4,0};

  for(int i = 0; i < SIZE; i++){
      cout<<i<<": "<<array[i]<<"--->"<<linkedList->insertHead(array[i])<<endl;
  }

  linkedList->printLinkedList();
return 0;
}
