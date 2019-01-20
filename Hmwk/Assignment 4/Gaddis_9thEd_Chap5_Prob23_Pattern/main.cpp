/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose:  Shape
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
int rws;
cin >> rws;


  
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    for (int i = 0; i < rws; i++) {
    if ( i > 0)
    cout << endl;
    
    for (int j = 0; j <= i; j++) {
        cout << "+";
    }
    cout << endl;
}
for (int i = 0; i < rws; i++) {
    cout << endl;
    for (int j = rws; j > i; j--) {
        cout << "+";
    }
    if (i < rws-1)
    cout << endl;


}
    //Display the outputs

    //Exit stage right or left!
    return 0;
}