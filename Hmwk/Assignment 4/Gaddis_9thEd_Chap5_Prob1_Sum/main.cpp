/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Sum
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
    int sum=0, 
        num, 
        add;
    
    //Initialize or input i.e. set variable values
    cin>>num;
    
    //Map inputs -> outputs
     if (num<0)
            cout<<"This number could not be computed. ";
        else
        {
           
            for(add=0; add<=num; add++)
                sum+=add;
            cout<<"Sum = "<<sum;
        }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}