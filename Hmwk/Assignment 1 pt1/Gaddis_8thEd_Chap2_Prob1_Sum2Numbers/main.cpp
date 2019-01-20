/* 
 * Author: Mais Salloum
 * Date: 1/7/2019
 * Purpose: Sum of 2 numbers
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
    int x, y, total;
    //Input or initialize values Here
    cout << "Input 2 integer numbers\n";
    cin >> x;
    cin >> y;
    //Process/Calculations Here
    total=x+y;
    //Output Located Here
 cout << "The sum of " << x << "+" << y << "=" << total;
    //Exit
    return 0;
}

