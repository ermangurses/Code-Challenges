#include "Variable.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//******************************************************************************
//
// Function Prototypes
//
//******************************************************************************
bool openInputFile(ifstream & inFile, char *argv[]);
void readInputFile(ifstream & inFile, Variable * variable);


//******************************************************************************
//
// main function
//
//******************************************************************************
int main(int argc, char *argv[]){

   Variable * variable = new Variable();
   ifstream inFile;
   if(!openInputFile(inFile, argv)){   
       return 0;
   } 
   readInputFile(inFile,variable);

 return 0;
}

//******************************************************************************
// openInputFile Function
//
// This function belongs to cons thread it prints vowel words
//
// Return Value
// ------------
// void                         Return true 
//                                     If file is opened
//                              Return false 
//                                     If file is not opened
// Value Parameters
// ----------------
//                              No Value Parameters 
// 
// Reference Parameters
// --------------------
// infile       ifstream        The address of the ifstream object          
// *argv[]      char            Pointer to the argv[] array
// 
// Local Variables
// ---------------            
//
//******************************************************************************
bool openInputFile(ifstream & inFile, char *argv[]){
    inFile.open(argv[1]);
    if (!inFile){
        cout <<"The input File cannot been opened!!!\n";
        return false;
     }
  return true;
}

//******************************************************************************
// readInputFile Function
//
// This function belongs to cons thread it prints vowel words
//
// Return Value
// ------------
// void                     No return value
//
// Value Parameters
// ----------------
//                          No Value Parameters 
// 
//
// Reference Parameters
// --------------------
// t            char        Visual ID of thread.           
//
// Local Variables
// ---------------
// vowTemp      char        Keeps current word
//
//******************************************************************************
void readInputFile(ifstream & inFile, Variable * variable){

    string line;
    while(getline(inFile, line)){
        variable->getLine(line);
    }
}

