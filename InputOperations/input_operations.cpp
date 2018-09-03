#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;

int main() {

    string line;
    string token;

    while(getline(cin,line)){
         
        stringstream ss(line);

        while(getline(ss, token, ' ')){
        
            cout<<"Token: "<< token<<endl;
        } 
    }

    return 0;
}
