/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Race
 */

//System Libraries
#include <iostream> 
#include <iomanip>
#include <string>
//Input/Output Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    
    int time1, time2, time3;
    string name1, name2, name3;
    
    cout << "Race Ranking Program" << endl;
    cout << "Input 3 Runners" << endl;
    cout << "Their names, then their times" << endl;
    
   cin >> name1 >> time1 >> name2 >> time2 >> name3 >> time3;

    if (time1 < time2 && time1 < time3 && time2 < time3){
        cout << name1 << "\t" << setw(8) << time1 << endl;
        cout << "\t" << name2 << setw(8) << time2 << endl;
        cout << name3 << "\t" << setw(8) << time3;
    }else{}
    
     if (time1 < time2 && time1 < time3 && time3 < time2){
        cout << name1 << "\t" << setw(3) << time1 << endl;
        cout << name3 << "\t" << setw(3) << time3 << endl;
        cout << name2 << "\t" << setw(3) << time2;
    }
    else{}
    
    if (time2 < time3 && time2 < time1 && time3 < time1){
        cout << name2 << "\t" << setw(3) << time2 << endl;
        cout << name3 << "\t" << setw(3) << time3 << endl;
        cout << name1 << "\t" << setw(3) <<time1;
    }
    else{}
    
     if (time2 < time3 && time2 < time1 && time1 < time3){
        cout << name2 << "\t" << setw(3) << time2 << endl;
        cout << name1 << "\t" << setw(3) << time1 << endl;
        cout << name3 << "\t" << setw(3) << time3;
    }
    else{}
    
    if (time3 < time1 && time3 < time2 && time2 < time1){
        cout << name3 << "\t" << setw(3) << time3 << endl;
        cout << name2 << "\t" << setw(3) << time2 << endl;
        cout << name1 << "\t" << setw(3) << time1;
        
    }
    else{}
    
    if (time3 < time1 && time3 < time2 && time1 < time2){
        cout << name3 << "\t" << setw(3) << time3 << endl;  
        cout << name1 << "\t" << setw(3) << time1 << endl;   
        cout << name2 << "\t" << setw(3) << time2;
        
    }
    else{}
    
    return 0;
}
