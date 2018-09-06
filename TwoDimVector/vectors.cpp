#include <iostream>
#include <vector> // for 2D vector


using namespace std;

int main(){

    vector<vector<int> > vect{ { 1, 2, 3 },
                               { 4, 5, 6 },
                               { 7, 8, 9 } };

    vect.resize(10);
    vect[9].push_back(10);

    for (int i = 0; i < vect.size(); i++) {
      for (int j = 0; j < vect[i].size(); j++)
        cout << vect[i][j] << " ";
        cout << endl;
    }

  
       
return 0;
}
