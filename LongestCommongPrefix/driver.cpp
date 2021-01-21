#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs);

int main(){
	
	vector<string> strs = {};
	std::cout<<longestCommonPrefix(strs)<<endl;

   return 0;

}

string longestCommonPrefix(vector<string>& strs) {
 
 	int sizeOfVector = strs.size();
        cout<<"sizeOfVector: "<< sizeOfVector<<endl;

        if(sizeOfVector == 0)
        {
            cout<<"sizeOfVector is 0"<<endl;
            return "";
        }

        int size = strs.at(0).size();
        int counter = 0;


        string longestCommonString ="";
        
        for(int i = 0; i  < strs.size(); ++i)
        {
            if ( size > strs.at(i).size() )
            {
                size = strs.at(i).size();
            } 
        }
        //cout << size << endl;
        bool flag = true;
        string temp = strs.at(0);

        for (int i = 0; i < size; ++i)
        {
            for(int j = 0; j < strs.size(); ++j)
            {
                if(temp.at(i) != strs.at(j).at(i) )
                {
                    flag = false;
                }
            }
            if(flag)
            {
               longestCommonString.insert(i,1,temp.at(i)); 
            }
            else
            {
              break;
            }
        }
        
     return longestCommonString;   
}
