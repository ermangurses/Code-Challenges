#include <iostream>
#include <string>
#include <unordered_set>


using namespace std;

int main(){

    unordered_set<int> hashSet;
    unordered_set<int>::iterator iter;
    unordered_set<int>::const_iterator cIter;

    int counter = 0;

    for (int i = 0; i < 25; ++i){
        hashSet.insert(counter++);      
    }
    
    cIter = hashSet.find(10);  
     
    if(cIter == hashSet.end()){

        cout<<*cIter<<" is the new element in the set"<<endl; 
    }else{

        cout<<*cIter<<" is already exist in the set"<<endl;
    }
   
    for(iter = hashSet.begin(); iter != hashSet.end(); ++iter){
        cout<<*iter<<" ";
    }
 
///////////////////////////////////////////////////////////////

    cout<<endl<<endl<<"hashSet contains: ";
    for ( auto it = hashSet.begin(); it != hashSet.end(); ++it )
        std::cout << " " << *it;
    cout<<endl;

    cout << "hashSet buckets contain:\n";
    for ( unsigned i = 0; i < hashSet.bucket_count(); ++i) {
    cout << "bucket #" << i << " contains:";
    for ( auto local_it = hashSet.begin(i); local_it!= hashSet.end(i); ++local_it )
      std::cout << " " << *local_it;
    cout<<endl;
  }
///////////////////////////////////////////////////////////////

  unordered_set<string> myset =
  {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};

  cout << "myset contains:";
  for ( auto it = myset.begin(); it != myset.end(); ++it )
    cout << " " << *it;
  cout<<endl;

  cout << "myset's buckets contain:\n";
  for ( unsigned i = 0; i < myset.bucket_count(); ++i) {
    cout << "bucket #" << i << " contains:";
    for ( auto local_it = myset.begin(i); local_it!= myset.end(i); ++local_it )
      cout << " " << *local_it;
    cout<<endl;
  }

       
return 0;
}
