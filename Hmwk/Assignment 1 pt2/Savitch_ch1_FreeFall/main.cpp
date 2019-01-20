/* 
 * Author: Mais Salloum
 * Date: 1/8/2019
 * Purpose: Calculate distance
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
    int sec, dist;
    //Input or initialize values Here
    cout << "Input the time in free-fall\n";
    cin >> sec;
    //Process/Calculations Here
    dist=0.5*32*sec*sec;
    //Output Located Here
cout << "\nThe distance = " << dist << " feet";
    //Exit
    return 0;
}