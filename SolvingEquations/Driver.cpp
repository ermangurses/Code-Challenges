#include "Variable.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>
using namespace std;
//******************************************************************************
//
// Function Prototypes
//
//******************************************************************************
bool openInputFile (ifstream & inFile, char *argv[]);
void readInputFile (ifstream & inFile, map<string,Variable> & variableSet);
void constructSet (map<string,Variable> & variableSet, string line);
unsigned int solve (map<string,Variable>::iterator var, map<string,Variable> & variableSet);

//******************************************************************************
//
// main function
//
//******************************************************************************
int main(int argc, char *argv[]){

   ifstream inFile;
   if(!openInputFile(inFile, argv)){   
       return 0;
   } 
   map<string,Variable> variableSet;
   readInputFile(inFile,variableSet);
   string str;

   for(auto it = variableSet.begin(); it != variableSet.end(); ++it){
       cout<< it->first<<"  "<<it->second.getTotalValue()<<endl;
       cout<< it->first<<"  "<<it->second.getTheNumberOfDependencies()<<endl<<endl;
   }
    
   for(auto it = variableSet.begin(); it != variableSet.end(); ++it){

       while ( !(it->second.isDependencySetEmpty()) ){
           solve(it,variableSet);
       }
   } 
   cout<<endl<<endl;
   for(auto it = variableSet.begin(); it != variableSet.end(); ++it){
      cout<< it->first<<"  "<<it->second.getTotalValue()<<endl;
      cout<< it->first<<"  "<<it->second.getTheNumberOfDependencies()<<endl<<endl;
   }  
 return 0;
}

unsigned int solve (map<string,Variable>::iterator variable, map<string,Variable> & variableSet){

    string dependency_name;
    variable->second.getDependency(dependency_name);
    std::map<string,Variable>::iterator  dependency_iterator = variableSet.find(dependency_name);     
    
    if( dependency_iterator->second.isDependencySetEmpty() ){

        variable->second.addValue(dependency_iterator->second.getTotalValue());
     } else {

        variable->second.addValue(solve(dependency_iterator,variableSet));
     }
     return variable->second.getTotalValue();
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
void readInputFile(ifstream & inFile,  map<string, Variable> & variableSet){

    string line;

    while(getline(inFile, line)){
        constructSet(variableSet,line);
    }
}

//******************************************************************************
// constructSet Function
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

void constructSet(map<string, Variable>  & variableSet, string line){
 
    Variable  variable;
    variable.getLine(line);
    variableSet.insert(make_pair(variable.getVariableName(),variable)); 
 
}

