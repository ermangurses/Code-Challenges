#include "Queue.cpp"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

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
   
   if (!inFile)
   {
      cout << "The input File cannot be opened!!!\n";

      return false;
   }
   return true;
}

int main(){

   Queue<int> * queue = new Queue<int>();



   return 0;

}
