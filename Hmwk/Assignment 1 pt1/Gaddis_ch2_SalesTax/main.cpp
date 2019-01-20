/* 
 * Author: Mais Salloum
 * Date: 1/8/2019
 * Purpose: Total tax
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
    int price;
    double tax;
    //Input or initialize values Here
    cout << "Input price of purchase\n";
    cin >> price;
    //Process/Calculations Here
    tax= (0.04*price)+(0.02*price);
    //Output Located Here
    cout << "The total sales tax is " << tax;
    //Exit
    return 0;
}