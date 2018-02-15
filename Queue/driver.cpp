#include "Queue.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#define SIZE 10

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
   
   if (!inFile){
       cout << "The input File cannot be opened!!!\n";
       return false;
   }
   return true;
}

int main(){

    Queue<int> * queue = new Queue<int>();

    int counter = 0;
    int dataOut;

    while(counter < SIZE){

        ++counter;
        cout<<counter<<" is added to the queue"<<endl;
        queue->enqueue(counter);
    }

   cout<<endl<<endl;
   cout<<"Elements are added to queue:"<<endl;

   queue->printQueue();
   cout<<endl<<endl;
   
   while(queue->dequeue(dataOut)){

       cout<<dataOut<<" is removed"<<endl;
   }


   return 0;

}
