#include "Divide.h"
#include <math.h> 
#include <vector>

#define MAX 2147483648 

using namespace std;
/******************************************************************************
//
//
//  Default Costructor 
//
//
*******************************************************************************/

Divide::Divide(){}

/******************************************************************************
//
// 
// reverse_integer
//
//
*******************************************************************************/
long int Divide::divide_integer(int dividend, int divisor){


   
         bool flagDifferentSigns = false;

         if(divisor == 0)
            exit(0);

         if( (dividend < 0) ^ (divisor < 0) )
             flagDifferentSigns = true;

         if(divisor == 1)
         {
             return dividend;
         }
         else if(divisor == -1)
         {

             if(dividend == -MAX)
                 return 2147483647;
             else
                 return -dividend;

         }
         else if(divisor == -MAX)
         {
             
            if(dividend == -MAX)
            {
                return 1;
            }
            else
            {
                return 0;
            }
         }   
         
         bool flagIntNegativeMax = false;
         
         if(dividend == -MAX)
         {
             if(divisor < 0)
             {
                 dividend = dividend - divisor;
             }
             else if (divisor > 0)
             {
                 dividend = dividend + divisor;
             }
             flagIntNegativeMax = true;
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
             if(flagDifferentSigns)
             {
                 return -1;
             }
             else
             {
                 return 1;
             }
         }
         
         long int temp = divisor;
         int total = 0;
         int resudial = dividend;
         int result = 1;
         int totalResult = 0;

         while (resudial >= divisor)
         {
             temp = divisor;
             result = 1;
             while (temp <= resudial)
             {
                 temp =  temp<<1;
                 result = result<<1;
             }
             temp = temp>>1;
             total += temp;
             resudial -= temp;
             totalResult += result>>1;

         }
         
         if(flagIntNegativeMax)
         {
             totalResult++;
     
         }

         if(flagDifferentSigns)
         {
             totalResult = -totalResult; 
         }
         
         return totalResult;
}
