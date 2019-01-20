/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose:  Bank Charges
 */

//System Libraries
#include <iostream>
#include <iomanip>  //Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare Variables
    float balance, checks, fee, charge, newb;
    //Initialize or input i.e. set variable values
    cout << "Monthly Bank Fees\n"
    << "Input Current Bank Balance and Number of Checks\n";
    cin >> balance >> checks;
    //Map inputs -> outputs
    if (checks<20)
    fee=.10*checks;
    else if (checks>=20 && checks<=39)
    fee=.08*checks;
    else if (checks>=40 && checks<=59)
    fee=.06*checks;
    else if (checks>=60)
    fee=0.04*checks;
    if (balance>0 && balance<400)
    charge=15;
    else if (balance>=400)
    charge=0;
    else if (balance<0)
    cout << "The account is overdrawn\n";
    newb=balance-(10+fee+charge);
    //Display the outputs
cout << setprecision(2)<<fixed;
cout << "Balance" << setw(6) << "$" <<setw(9) << balance << endl;
cout << "Check Fee" <<setw(4)<< "$" << setw(9) << fee << endl;
cout << "Monthly Fee $" <<setw(10)<< "10.00\n";
cout << "Low Balance $" <<setw(9) << charge << endl;
cout << "New Balance $" <<setw(9) << newb;
    //Exit stage right or left!
    return 0;
}

