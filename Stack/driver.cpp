#include "Stack.cpp"
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

    Stack<int> * stack = new Stack<int>();
 
    int counter = 0;

    while(counter < SIZE){

        stack->push(counter);
        cout<<"stack->push("<<counter<<");"<<endl;
        ++counter;
    }

    cout<<endl<<endl;
    cout<< "Print Stack:"<<endl;
    stack->printStack();
    cout<<endl<<endl;
       
    int temp;
    
    cout<< "Pop Stack:"<<endl; 
 
    while(!stack->isEmpty()){

        stack->pop(temp);
        cout<<"stack->pop() returns ---> "<<temp<<endl;

    }
    cout<<endl<<endl;
    cout<< "Print Stack:"<<endl;
    stack->printStack();
    cout<<endl<<endl; 
} 

