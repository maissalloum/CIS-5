/* 
 * Author: Mais Salloum
 * Date: 1/7/2019
 * Purpose: Convert to cents
 */

//System Libraries Here
#include <iostream>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int Quarters, Dimes, Nickels, cents;
    //Input or initialize values Here
    cout << "Enter the number of Quarters, Dimes and Nickels\n" <<endl;
    cin >> Quarters;
    cin >> Dimes;
    cin >> Nickels;
    //Process/Calculations Here
    cents = (25*Quarters) + (10*Dimes) + (5*Nickels);
    //Output Located Here
 
cout <<Quarters << " Quarters + " <<Dimes << " Dimes + " << Nickels << " Nickels = " << cents << " cents!";
    //Exit
    return 0;
}

