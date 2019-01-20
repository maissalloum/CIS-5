/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose:  Rectangles
 */

//System Libraries
#include <iostream>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    short int num; // number that the user will enter
           char X; //letters that will output
    //Initialize or input i.e. set variable values
    cin >> num >> X;
    for (int i = 1; i <= num; i++) {
        for (int i = 1; i <= num; i++)
        cout << X;
        if (i < num)
        cout << endl;
    
        
    }
    
    //Map inputs -> outputs
    
    //Display the outputs

    //Exit stage right or left!
    return 0;
}