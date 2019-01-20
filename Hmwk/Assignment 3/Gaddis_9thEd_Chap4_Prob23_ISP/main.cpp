/* 
 * Author: Mais Salloum
 * Purpose: ISP Bill
 */

//System Libraries Here
#include <iostream> //Input Output Library
#include <iomanip>  //Formatting Library
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    char package;           
    unsigned int hrs;  
    float bill;          
    
    //Input or initialize values Here
    cout << "ISP Bill" << endl;
    cout << "Input Package and Hours" << endl;   
    cin >> package >> hrs;                        
    // Do calculations here
    switch(package){                         
        case 'A':{      
                    bill += (hrs > 10 ? 9.95 + (hrs-10)*2:9.95);
                    break;
               }
        case 'B':{      
                    bill += (hrs > 20 ? 14.95 + (hrs-20)*1:14.95);
                    break;
        }
        case 'C':{      
                    bill += 19.95;
                    break;
    
    }
    }
    //Output Located Here
    cout << fixed << setprecision(2) << showpoint;
    cout << "Bill = $" << setw(6) << bill; 

    //Exit
    return 0;
}