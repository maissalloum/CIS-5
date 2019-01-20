/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Sort names
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <string>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    
    string name1, name2, name3;
    
    //Initialize or input i.e. set variable values
    cout << "Sorting Names" << endl;
    cout << "Input 3 names" << endl;
    cin >> name1;
    cin >> name2;
    cin >> name3;
    
    
    if (name1 < name2 && name1 < name3)    
    
        cout << name1 << endl;
         else if (name2 < name1 && name2 < name3)
        cout << name2 << endl;
         else if (name3 < name1 && name3 < name2)
        cout << name3 << endl;


    if (name1 > name2 && name1 < name3)    
        cout << name1 << endl;
         else if (name1 > name3 && name1 < name2)
     cout << name1 << endl;
         else if (name2 > name3 && name2 < name1)
        cout << name2 << endl; 
         else if (name2 > name1 && name2 < name3)
        cout << name2 << endl;
         else if (name3 > name1 && name3 < name2)
     cout << name3 << endl;
         else if (name3 > name2 && name3 < name1)
     cout << name3 << endl;
    
    if (name1 > name3 && name1 > name2)    
        cout << name1;
         else if (name2 > name3 && name2 > name1)
        cout << name2;
         else if (name3 > name2 && name3 > name1)
        cout << name3;

    
    
    //Map inputs -> outputs
  
    //Display the outputs

    //Exit stage right or left!
    return 0;
}

