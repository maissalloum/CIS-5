/* 
 * Author: Mais Salloum
 * Date: 1/8/2019
 * Purpose: MPG
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
    float G, M, MPG;
    //Input or initialize values Here
    cout << "Input number of gallons and distance traveled.\n";
    cin >> G;
    cin >> M;
    //Process/Calculations Here
    MPG= M/G;
    //Output Located Here
    cout << "Your MPG is " << MPG;
    //Exit
    return 0;
}