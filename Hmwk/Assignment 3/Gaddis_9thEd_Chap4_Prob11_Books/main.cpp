/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Books
 */

//System Libraries
#include <iostream>//Input/Output Library
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
    int books, points;
    //Initialize or input i.e. set variable values
    cout << "Book Worm Points\n" 
    << "Input the number of books purchased this month.\n";
    cin >> books;
    //Map inputs -> outputs
    if (books==0)
    { points=0; }
    else if (books==1)
    { points=5; }
    else if (books==2)
    {points = 15; }
    else if (books==3)
    { points=30; }
    else if (books>=4)
    {points=60;}
    //Display the outputs
cout << "Books purchased =" << setw(3) << books << endl;
cout << "Points earned" << setw(4) << "=" << setw(3) <<points;
    //Exit stage right or left!
    return 0;
}

