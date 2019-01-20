/* 
 * File:   
 * Author: Mais Salloum
 * Purpose:  Paycheck
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float rate, hours, over, pay;
    //Initialize or input i.e. set variable values
    cout << "This program calculates the gross paycheck.\n";
    cout << "Input the pay rate in $'s/hr and the number of hours.\n";
    cin >> rate >> hours;
    //Map inputs -> outputs
    if (hours>40)
    { over= hours-40;
     pay = (rate*40)+(2*rate*over);}
    else
    { over = 0;
    pay = rate*hours;}
    
    //Display the outputs
    cout << setprecision(2) << fixed;
    cout << "Paycheck = $ " << pay;
    //Exit stage right or left!
    return 0;
}

