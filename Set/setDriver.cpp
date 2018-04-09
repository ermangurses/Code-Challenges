#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){

    set<int> mySet;
    // set<int>::iterator iter;
    set<int>::const_iterator cIter;

    int counter = 0;
    int key = 10;
    for (auto i = 0; i < 25; ++i){
        mySet.insert(counter++);      
    }
    
    cIter = mySet.find(key);  
     
    if(cIter == mySet.end()){

        cout<<key<<" is not in the set"<<endl; 
    } else {

        cout<<*cIter<<" is in the set"<<endl;
    }

    cout<<endl;    
    cout<<"These are the elements in the set"<<endl;
    for(auto iter = mySet.begin(); iter != mySet.end(); ++iter){
        cout<<*iter<<" ";
    }
    cout<<endl;
return 0;
}
