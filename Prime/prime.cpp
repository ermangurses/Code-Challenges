#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <queue>
using namespace std;

int main() {
 

    int n;
    int counter = 0;
    int number;
    bool flag = true;
    
    queue<int> que;
    cin>>n;
    
    while(counter < n){
        
        cin>>number;
        que.push(number);
        counter++;
    }
    
    while(!que.empty()){
        
        number = que.front();
        que.pop(); 
        
        if(number < 2){
   
            cout<<"Not Prime"<<endl;

        } else { 
        
            for(int i = 2; i <= sqrt(number); ++i){
                
                if(number % i == 0){
                    cout<<"Not Prime"<<endl;
                    flag = false;
                    break;
                }
            } 
            if(flag){
                cout<<"Prime"<<endl; 
            }
            flag = true;
        }        
    }
    return 0;
}
