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

    /******************************************************************************
 
      Do the operations in linked list using input.txt file
    
    ******************************************************************************/

    cout<<endl<<endl;
    cout<<"**** File Operations Start ****"<<endl;
 
    Stack<int> * stack1 = new Stack<int>();   

    ifstream inFile;
    string line;

    if(!openInputFile(inFile)){

        return 0;
    }
   
    // Read the first line
    getline(inFile, line);

    cout<<"There will be "<<atoi(line.c_str())<<" elements in the stack"<<endl;
 
    // Read the second line and tokenize it
    getline(inFile, line);
    stringstream ss(line);
    string token;
  
    while(getline(ss, token, ' ')){
        stack1->push(atoi(token.c_str()));
    }
    cout<<endl<<endl; 

    stack1->printStack();
  
    cout<<endl<<endl;
    
    stack1->top(temp);
    cout<<"Top of Stack: "<<temp<<endl;     
    cout<<endl<<endl;

    delete stack1;

    cout<<"Print Stack after destructor"<<endl;
    stack1->printStack(); 
} 

