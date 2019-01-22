/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Created on January 21, 2019
 * Purpose:  Menu Lab6
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib>   //Random numbe9r function
#include <ctime>     //Time Library for random seed
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes
void sum(int summ,int numb,int add);
void minmax(int n, int lrgst,int smllst, int count, bool);
void rctngl(short int num, char X);
void pat(int rws);
void payp(int days, float sum2, float pay); 

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare Variables
    char wchProb, X;//Choose which problem
    int summ, numb, add, n, lrgst, smllst, count, rws, days;
    short int num;
    float sum2, pay;
    bool repeat=true;
    //Loop Menu until exit
    do{

        //Initialize or input i.e. set variable values
        cout<<"Menu Program"<<endl;
        cout<<"Type 1 for Sum"<<endl;
        cout<<"Type 2 for Min and Max"<<endl;
        cout<<"Type 3 for Rectangle"<<endl;
        cout<<"Type 4 for Pattern"<<endl;
        cout<<"Type 5 for Pay in Pennies"<<endl;
        cout<<"Type anything else to exit"<<endl;
        cin>>wchProb;

        //Solve Problems
        switch(wchProb){
            case '1':sum(summ, numb, add);break;
            case '2':minmax(n, lrgst, smllst, count, repeat);break;
            case '3':rctngl(num, X);break;
            case '4':pat(rws);break;
            case '5':payp(days, sum2, pay);break;
            default :cout<<"Exiting Menu, no problem selected"<<endl;
        }
    
    //End of Menu/problems
    }while(wchProb>='1'&&wchProb<='5');

    //Exit stage right or left!
    return 0;
}

void sum(int summ,int numb,int add){
    summ=0;
    cout <<"Input a number\n";
    cin>>numb; //input number
    
    //Map inputs -> outputs
     if (numb<0)
            cout<<"This number could not be computed. "; //positive numbers only
        else
        {
           
            for(add=0; add<=numb; add++) //for loop
                summ+=add;
            cout<<"Sum = "<<summ <<endl;
        }
}

void minmax(int n, int lrgst,int smllst, int count, bool){
    bool repeat=true;
    cout << "Input a series of integers. Use -99 to indicate the end of the series.\n";
    do
   {
       //read the number
       cin >> n;
       
       //if -99 is entered exit the loop
       if (n == -99)
           repeat = false;
       else
       {
           //if the count is 0 (which means this is the first number) set largest and smallest as n
           if (count == 0)
           {
               lrgst = n;
               smllst = n;
               count++; //increment count
           }
           //else check the largest and smallest numbers
           else
           {
               //if n is less than smallest
               if (n < smllst)
                   smllst = n;   //set n as smallest
               //if n is greater than largest
               if (n > lrgst)  
                   lrgst = n;   //set n as largest
           }
       }

   }while (repeat);
  
   //display the largest and the smallest numbers
   cout << "Smallest number in the series is "<< smllst << endl;
   cout << "Largest  number in the series is "<< lrgst << endl;
}

void rctngl(short int num, char X){
    //Initialize or input i.e. set variable values
    cout <<"Input a number and a character to make a rectangle.\n";
    cin >> num >> X;
    
    
    //Map inputs -> outputs
    for (int i = 1; i <= num; i++) { //for loop to create the rectangles 
        for (int i = 1; i <= num; i++)
        cout << X;
        if (i < num)
        cout << endl;
    
        
    }
}

void pat(int rws){
    cout << "Input a number to create a pattern.\n";
    cin >> rws;


  
    //Initialize or input i.e. set variable values
    
    //Map inputs -> outputs
    for (int i = 0; i < rws; i++) { //loop to create top part of pattern
    if ( i > 0)
    cout << endl;
    
    for (int j = 0; j <= i; j++) {
        cout << "+";
    }
    cout << endl;
}
for (int i = 0; i < rws; i++) { //creates bottom part of pattern
    cout << endl;
    for (int j = rws; j > i; j--) {
        cout << "+";
    }
    if (i < rws-1)
    cout << endl;


}
}

void payp(int days, float sum2, float pay){
    sum2=.01;
    pay=.01;
    cout << "Input the number of days worked.\n";
    cin >> days; // have user input days they worked
    
    //Map inputs -> outputs
    if (days == 0)
    cout << "0 Days are not allowed."; //positive integer has to be entered
    else if (0 > days)
    cout << "Negative days are not allowed."; //positive integer has to be entered
    else {}
    
    if (days >= 1) { //loop to calculate pay
        for (int i = 0; i< days - 1; i++){
            pay *= 2;
            sum2 += pay;
        }
    }
    
    
    cout << "Pay = $"  << setprecision(2) << fixed << sum2 <<endl;
}