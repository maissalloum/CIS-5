/* 
 * Author: Mais Salloum
 * Date: 1/8/2019
 * Purpose: Average of 5 numbers
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
    double A, B, C, D, E, sum, ave;
    //Input or initialize values Here
    cout << "Input 5 numbers.\n";
    cin >> A >> B >> C >> D >> E;
    //Process/Calculations Here
    sum=A+B+C+D+E;
    ave= sum/5;
    //Output Located Here
    cout << "The average is " << ave;
    //Exit
    return 0;
}