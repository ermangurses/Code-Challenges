#include "Divide.h"
#include <math.h> 
#include <vector>

using namespace std;


/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/

Divide::Divide(){

}

/******************************************************************************
//
// 
// reverse_integer
//
//
*******************************************************************************/
long int Divide::divide_integer(int dividend, int divisor){
         
        bool flag = false;

         if(divisor == 0)
            exit(0);

         if( (dividend < 0) ^ (divisor < 0) )
             flag = true;

         if(divisor == 1)
         {
             return dividend;
         }
         else if(divisor == -1)
         {

             if(dividend == -2147483648)
                 return 2147483647;
             else
                 return -1*dividend;

         }
         
         int specialCase = 0;
         if(dividend == -2147483648)
         {
             
             if(divisor < 0)
             {
                 
                 dividend = dividend - divisor;
                 
             }
             else if (divisor > 0)
             {
                 dividend = dividend + divisor;
                 
             }
             flag1 = true;
         }
         
         
         if(dividend < 0)
         {
             dividend = -dividend;
         }
         
         if(divisor < 0)
         {
             divisor = -divisor;
         }
         
         if (divisor == dividend)
         {
             if(flag)
             {
                 return -1;
             }
             else
             {
                 return 1;
             }
         }
         
         long long int temp = divisor;
         int total = 0;
         int resudial = dividend;
         int result = 1;
         int totalResult = 0;
        
         cout << "\nTotal before: "<< total<<endl;
         cout << "Divisor before: "<< divisor<<endl;
         cout << "Resudial before: "<< resudial<<endl;
         cout << "Temp before: "<< temp <<endl;         
         
         while (resudial >= divisor)
         {
             temp = divisor;
             result = 1;
             while (temp <= resudial)
             {
                 
                 cout << "\nTotal in: "<< total<<endl;
                 cout << "Divisor in: "<< divisor<<endl;
                 cout << "Resudial in: "<< resudial<<endl;
                 cout << "Temp in: "<< temp <<endl;                 

                 temp =  temp<<1;
                 result = result<<1;

             }

             temp = temp>>1;
             total += temp;
             resudial -= temp;
             totalResult += result>>1;

         }

         cout << "\nTotal out: "<< total<<endl;
         cout << "Divisor out: "<< divisor<<endl;
         cout << "Resudial out: "<< resudial<<endl;
         cout << "Temp out: "<< temp <<endl;
         
	 cout <<"flag1 "<< flag1 << endl;
	 cout<< "flag  "<< flag  << endl;


         if(flag1)
         {
             if(flag) //pos
             {
                totalResult++;
		//
		//

		cout<<"I am here!!"<< endl;
             }
             else //neg
             {
               totalResult--;
	       //
	       //

	       cout<<"I am here!!!"<<endl;
             }
             
             
         }

         if(flag)
         {
             
             totalResult = -totalResult;
             
         }
         
         return totalResult;
    
         
    

}
