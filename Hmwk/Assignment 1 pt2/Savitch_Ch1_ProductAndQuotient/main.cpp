/* 
 * Author: Mais Salloum
 * Date: 1/7/2019
 * Purpose: product and quotient of 2 numbers
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
    int x, y, product, quotient;
    //Input or initialize values Here
    cout << "Input 2 integer numbers.\n";
    cin>>x;
    cin>>y;
    //Process/Calculations Here
    product=x*y;
    quotient=y/x;
    //Output Located Here
    cout << "\n" << "The product of " << x << "*" << y << " = " << product <<endl
    << "\nThe quotient of " << y << "/" << x << " = " << quotient;
    //Exit
    return 0;
}

