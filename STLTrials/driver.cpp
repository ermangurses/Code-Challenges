#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>

#define SIZE 16
using namespace std;

int main(){

///////////////////////////////////////////////////////////////////////////////
// Vector Operations
///////////////////////////////////////////////////////////////////////////////

    cout<<"Vector Operations"<<endl;
    
    vector<int> vec;
    vector<int>::iterator it;
 
    // Adding items into vector
    for(int i = 0; i < SIZE; i++){
        vec.push_back(i+100);
    }
    
    // Adding an element at the beginning
    it = vec.begin();
    vec.insert(it,11);

    // Erasing 111
    vec.erase(vec.begin()+12);

    // Removing items from back
    while(!vec.empty()){ 
        
        cout<<"This item is removed: "<<vec.back()<<endl;
        vec.pop_back();
    }
///////////////////////////////////////////////////////////////////////////////
// List Operations
///////////////////////////////////////////////////////////////////////////////
 



  return 0;
}
