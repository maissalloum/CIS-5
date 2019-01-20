/* 
 * Author: Mais Salloum
 * Date: 1/8/2019
 * Purpose: Acres
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
    float x, acres;
    //Input or initialize values Here
    cout << "Input the number of square feet.\n";
    cin >> x;
    //Process/Calculations Here
    acres=x/43560;
    //Output Located Here
    cout << "The number of acres is " << acres;
    //Exit
    return 0;
}