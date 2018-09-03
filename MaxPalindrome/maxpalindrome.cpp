#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <stack>
#include <vector>
using namespace std;

int main() {
    
   //string str ="ssaabbbbaassss";

   string str = "ccbbaaabccbaaabbcc";
   vector<char> vec; 

   int counter = 0;
   int max = 0;
   int ii, jj; 
   counter = str.size() - 1;
   while(counter >= 0 ){

       vec.push_back(str[counter]);

       counter--;

   }

/*   counter = 0;
   while(counter < vec.size()){
       cout<<vec.at(counter)<<endl;
       counter++;
   }
*/

   counter = 0;

   for(int i = 0; i < str.size(); ++i){
   
       for(int j = 0; j < str.size(); ++j){
    
           if(str[i] == vec[j]){
           
               ii = i;
               jj = j;

               while(str[ii] == vec[jj] && ii < str.size()){
                   ii++;
                   jj++;
                   counter++;
               }

               if(counter > max){
                   max = counter;
               }
               counter = 0; 
           }
       }
   }
   if(counter > max){
       max = counter;
   }

   cout<<"The number of maximum palindrome squence is "<<max<<endl;
 return 0;
}
