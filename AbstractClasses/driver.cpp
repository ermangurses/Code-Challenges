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
  
  
return 0;
}
