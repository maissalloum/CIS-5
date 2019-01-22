/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Date: 1/21/2019
 * Purpose: Pay in Pennies
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> //manipulator
#include <cmath> //Math functions
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
   int days;
   float sum = .01,
          pay = .01;
    //Initialize or input i.e. set variable values
    cin >> days; // have user input days they worked
    
    //Map inputs -> outputs
    if (days == 0)
    cout << "0 Days are not allowed."; //positive integer has to be entered
    else if (0 > days)
    cout << "Negative days are not allowed."; //positive integer has to be entered
    else {}
    
    if (days >= 1) { //loop to calculate pay
        for (int i = 0; i< days - 1; i++){
            pay *= 2;
            sum += pay;
        }
    }
    
    
    cout << "Pay = $"  << setprecision(2) << fixed << sum;
    //Display the outputs

    //Exit stage right or left!
    return 0;
}
