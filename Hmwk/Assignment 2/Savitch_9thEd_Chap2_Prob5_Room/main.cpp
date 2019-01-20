/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Room
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
    int room, people, more, less;
    //Initialize or input i.e. set variable values
    cout << "Input the maximum room capacity and the number of people\n";
    cin >> room >> people;
    
    
    //Map inputs -> outputs
    more=room-people;
    less=people-room;
    if (people<=room)
    { cout << "Meeting can be held.\n" << "Increase number of people by " << more << " will be allowed without violation."; }
    else 
    { cout << "Meeting cannot be held.\n" << "Reduce number of people by " << less << " to avoid fire violation."; }
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

