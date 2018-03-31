#include "Tree.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <unistd.h>
#include <vector>

using namespace std;
/******************************************************************************

  *** bool openInputFile(ifstream & inFile) ***
  
  opens data.txt file 
  
  returns true if the file is opened succesfully
  
  return false if it fails
                       
******************************************************************************/
bool openInputFile(ifstream & inFile){

    inFile.open("data.txt");
   
    if (!inFile)
    {
       cout << "The input File cannot be opened!!!\n";

       return false;
    }
    return true;
}

int main(){

  /******************************************************************************

    Do the operations in linked list using input.txt file
   
  ******************************************************************************/
//int data[] = {1,2,3,4,5}; 
//    int data[] = {4,2,5,1,3};
   
    Tree * tree;
    vector<int> data;
    cout<<endl<<endl;
    cout<<"**** File Operations Start ****"<<endl;
  
    ifstream inFile;
    string line;
  
    if(!openInputFile(inFile)){
        return 0;   
    }  

    string token;

    while(getline(inFile, line)){        
        stringstream ss(line);
        while(getline(ss, token, ' ')){
         
            data.push_back(atoi(token.c_str())); 
            cout<<"Added: "<<token.c_str()<<" "<<endl;       
        }
           
        cout<<"The data is:";
        for(int i = 0; i < data.size(); i++){

            cout<<" "<<data.at(i);
        }       
        cout<<endl;       
  
        tree = new Tree(data);
        
        cout<<"isBST: "<<tree->isBST()<<endl;

        cout<< "printInOrder: ";
        tree->printInOrder();
        cout<<endl;
  
        cout<< "printPreOrder: ";
        tree->printPreOrder();
        cout<<endl;
  
        cout<< "printPostOrder: ";
        tree->printPostOrder();
        cout<<endl;
        
        delete tree;   
        data.clear();   
    }   
return 0;
}
