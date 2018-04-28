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
unsigned int solve (map<string,Variable>::iterator var, map<string,Variable> & variableSet, int count);

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
    
   int count = 0;
   for(auto it = variableSet.begin(); it != variableSet.end(); ++it){
       count++;
       if ( !(it->second.isDependencySetEmpty()) ){
           //cout<<it->second.getVariableName()<<"Main_getTheNumberOfDependencies()"<<it->second.getTheNumberOfDependencies()<<endl;
            it->second.addValue((solve(it,variableSet, count)));
           cout<<endl;
           // cout<<"Hello "<<it->first<<"  "<<it->second.getTotalValue()<<endl;
           // cout<<"solve(it->second,variableSet, count):"<< solve(it->second,variableSet, count)<<endl;
       }
   } 
   cout<<endl<<endl;
   for(auto it = variableSet.begin(); it != variableSet.end(); ++it){
      cout<< it->first<<"  "<<it->second.getTotalValue()<<endl;
      cout<< it->first<<"  "<<it->second.getTheNumberOfDependencies()<<endl<<endl;
   }  
 return 0;
}

unsigned int solve (map<string,Variable>::iterator var, map<string,Variable> & variableSet, int count){

     //cout<<"count is "<<count<<endl;

     string dependency_name;

     //cout<<var.getVariableName()<<" var.getTotalValue(): "<<var.getTotalValue()<<endl;

     var->second.getDependency(dependency_name);
     //cout<<"Dependency of "<< var.getVariableName()<<" is "<<dependency_name<<endl;
     //cout<<"getTheNumberOfDependencies()"<<var.getTheNumberOfDependencies()<<endl;
     std::map<string,Variable>::iterator  dependencyIt = variableSet.find(dependency_name);
     
     if( dependencyIt->second.isDependencySetEmpty() ){

        var->second.addValue(dependencyIt->second.getTotalValue());
        cout<<endl;
//        cout<<var->second.getVariableName()<<"  dependency.getTotalValue()  "<<dependencyIt->second.getTotalValue()<<endl;
        //cout<<var.getVariableName()<<" getTotalValue()  "<<var.getTotalValue()<<endl;     
        return var->second.getTotalValue();

     } else {
        //cout<<"Count: "<<count<<endl;  
    //    cout<<"Erman G"<<var->second.getVariableName()<<" var->second.getTotalValue(): "<<var->second.getTotalValue()<<endl;
        var->second.addValue(solve(dependencyIt,variableSet,count));
        cout<<var->second.getVariableName()<<" var->second.getTotalValue(): "<<var->second.getTotalValue()<<endl;
     }
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

