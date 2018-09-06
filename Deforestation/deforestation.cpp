#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <unistd.h>
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

/******************************************************************************
  *** void printEdges(int n, vector<vector<int>> tree) ***
  
  prints the edges given as input
                       
******************************************************************************/
void printEdges(int n, vector<vector<int>> & tree){

    for (int tree_row_itr = 0; tree_row_itr < n-1; tree_row_itr++) {

        tree[tree_row_itr].resize(2);

        for (int tree_column_itr = 0; tree_column_itr < 2; tree_column_itr++) {

           cout<<tree[tree_row_itr][tree_column_itr]<<" ";

        }
        cout<<endl;
    }
}

/******************************************************************************
  *** void getEdges(int n, vector<vector<int>> tree) ***
  
  takes the edges given as input
                       
******************************************************************************/
void getEdges(int n, vector<vector<int>> & tree, ifstream & inFile){

    string token;
    string line;
    for (int tree_row_itr = 0; tree_row_itr < n-1; tree_row_itr++) {

        tree[tree_row_itr].resize(2);

        getline(inFile,line);
        stringstream ss(line);

        for (int tree_column_itr = 0; tree_column_itr < 2; tree_column_itr++) {

            getline(ss, token, ' ');
            tree[tree_row_itr][tree_column_itr] =  atoi(token.c_str());
        }
    }
}

/******************************************************************************
  *** void getEdges(int n, vector<vector<int>> tree) ***
  
  takes the edges given as input
                       
******************************************************************************/
string deforestation(int n, vector<vector<int>> tree) {
    



    rankNodesWrapper(n,tree,ranks);
  
}

/******************************************************************************
  *** void rankNodesWrapper(int n, vector<vector<int>> tree) ***
  
  takes the edges given as input
                       
******************************************************************************/
void rankNodesWrapper(int n, vector<vector<int>> & tree,  vector<int> & ranks) {
 
    int pos = 0; 
    rankNodes(pos,n,tree,ranks);

}

/******************************************************************************
  *** void getEdges(int n, vector<vector<int>> tree) ***
  
  takes the edges given as input
                       
******************************************************************************/
int rankNodes(int pos, int n, vector<vector<int>> & tree,  vector<int> & ranks) {
    
    for(int i = 0; i < (n-1); ++i){

        if(i != pos){

            if( tree[pos][1] == tree[i][0] ){

                rankNodes(i,n,tree,ranks);

            }
        }
    }       
}

/******************************************************************************
  *** int main() ***
  
                       
******************************************************************************/
int main(){

    ifstream inFile;

    if( !openInputFile(inFile) ){
        return 0;
    }
    
    string line;
    getline(inFile, line);

    int n = atoi(line.c_str());
    vector<vector<int>> tree(n-1);

    getEdges(n,tree,inFile); 
    printEdges(n,tree);
    
    return 0;
}
