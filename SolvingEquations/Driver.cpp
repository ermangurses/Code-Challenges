#include "Solver.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

//********************************************************************
//
// Function Prototypes
//
//********************************************************************
bool openInputFile(ifstream & inFile, char *argv[]);



//********************************************************************
//
// main function
//
//********************************************************************
int main(int argc, char *argv[]){

   Solver * solver = new Solver();
 

   ifstream inFile;
   if(!openInputFile(inFile, argv)){   
       return 0;
   } 
   

 return 0;
}
//********************************************************************
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
//********************************************************************
bool openInputFile(ifstream & inFile, char *argv[]){
    inFile.open(argv[1]);
    if (!inFile){
        cout <<"The input File cannot been opened!!!\n";
        return false;
     }
  return true;
}

