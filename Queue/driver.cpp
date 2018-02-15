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

   /******************************************************************************
 
     Do the operations in linked list using input.txt file
    
   ******************************************************************************/

   cout<<endl<<endl;
   cout<<"**** File Operations Start ****"<<endl;
   Queue<int> * queue1 = new Queue<int>();

   ifstream inFile;
   string line;

   if(!openInputFile(inFile)){

       return 0;
   }
   
   // Read the first line
   getline(inFile, line);

   cout<<"There will be "<<atoi(line.c_str())<<" elements in the queue"<<endl;
 
   // Read the second line and tokenize it
   getline(inFile, line);
   stringstream ss(line);
   string token;
  
   while(getline(ss, token, ' ')){
       queue1->enqueue(atoi(token.c_str()));
   }
   cout<<endl<<endl; 

   queue1->printQueue();

   delete queue1;
   
   return 0;

}
