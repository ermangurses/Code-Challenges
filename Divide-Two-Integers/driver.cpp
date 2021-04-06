#include "Divide.h"
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){

   int dividend = -2147483648;
   int divisor = -3;

   Divide divide;

   cout<<"Result:  "<<divide.divide_integer(dividend,divisor)<<endl;


   return 0;

}
