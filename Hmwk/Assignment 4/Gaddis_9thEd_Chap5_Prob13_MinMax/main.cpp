/* Author : Mais Salloum
* Purpose : Max and Min
*/


#include<iostream>
using namespace std;

int main()
{
   int n;
   int lrgst, // largest number
      smllst, // smallest number
       count = 0; // count
   bool repeat = true; // true of false statement
   //prompt the user to enter a series of numbers
  
   do
   {
       //read the number
       cin >> n;
       
       //if -99 is enteres exit the loop
       if (n == -99)
           repeat = false;
       else
       {
           //if the count is 0 (which means this is the first number) set largest and smallest as n
           if (count == 0)
           {
               lrgst = n;
               smllst = n;
               count++; //increment count
           }
           //else check the largest and smallest numbers
           else
           {
               //if n is less than smallest
               if (n < smllst)
                   smllst = n;   //set n as smallest
               //if n is greater than largest
               if (n > lrgst)  
                   lrgst = n;   //set n as largest
           }
       }

   }while (repeat);
  
   //display the largest and the smallest numbers
   cout << "Smallest number in the series is "<< smllst << endl;
   cout << "Largest  number in the series is "<< lrgst ;
  

  
   return 0;
}