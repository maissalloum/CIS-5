/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Lab Assignment 4
 */

//System Libraries Here
#include <iostream>  //I/O Library
#include <cstdlib>   //Random number function
#include <ctime>     //Time Library for random seed
#include <iomanip>   //Format Library
#include <cmath>     //Math Library
using namespace std;


int main() {
    //Declare variables
    int probNum;
    
    //Loop on Menu and problems
    do{
    
        //Menu with input of choice
        cout<<"Choose from the following Menu"<<endl;
        cout<<"Problem 1 -> Sort Names"<<endl;
        cout<<"Problem 2 -> Books"<<endl;
        cout<<"Problem 3 -> Bank Charges"<<endl;
        cout<<"Problem 4 -> Race"<<endl;
        cout<<"Problem 5 -> ISP"<<endl;
        cout<<"Problem 6 -> Rock Paper Scissors"<<endl;
        cout<<"Problem 7 -> Compatible Signs"<<endl;
        cout<<"Problem 8 -> Roman Conversion"<<endl;
        cout<<"Type 1 to 8 only"<<endl<<endl;
        cin>>probNum;
    
        //Output the results
        switch(probNum)
        {
            case 1: 
            {   string name1, name2, name3;
    
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
                 cout << "\n---------------------------------------------\n";
       
                break;
            }
       
            case 2:
            {
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
                cout << "Points earned" << setw(4) << "=" << setw(3) <<points << endl;
                cout << "---------------------------------------------\n";

                
                
                break;
            }
            case 3: 
            {
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
              cout << "New Balance $" <<setw(9) << newb <<endl;
              cout << "---------------------------------------------\n";
                
                break;
            }
            case 4: 
            {
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
                cout << name3 << "\t" << setw(3) << time3 << endl;  //use "/t" instead of setw().
                cout << name1 << "\t" << setw(3) << time1 << endl;  //turns out that we use bother here. 
                cout << name2 << "\t" << setw(3) << time2;

            }
            else{}
           cout << "\n---------------------------------------------\n";
                break;
            }
            case 5: 
            {
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
                 cout << "\n---------------------------------------------\n";
                break;
            }
            case 6: 
            {
                char Player1, Player2, ans,x;

        //setting the stage
        cout << "Rock Paper Scissors Game"<<endl; 
        cout << "Input Player 1 and Player 2 Choices" <<endl; 


            cin >> Player1;
            cin >> Player2;

            //checking if player1 wins the game
            if ((Player1 =='R' ||Player1== 'r') && (Player2 =='S' || Player2=='s'))
            {
                cout << "Rock breaks scissors.";
            }
            //checking if player2 wins the game
            else if ((Player1 =='S' ||Player1=='s') && (Player2 =='R' ||Player2=='r'))
            {
                cout << "Rock breaks scissors";
            }
            //checking if player1 wins the game
            else if ((Player1 =='P' ||Player1== 'p') && (Player2 =='R' || Player2=='r'))
            {
                cout << "Paper covers rock.";
            }
            //checking if player2 wins the game
            else if ((Player1 =='R' ||Player1=='r') && (Player2 =='P' ||Player2=='p'))
            {
                cout << "Paper covers rock.";
            }
            //checking if player1 wins the game
            else if ((Player1 == 'S' ||Player1== 's') && (Player2 =='P' ||Player2=='p'))
            {
                cout << "Scissors cuts paper.";
            }
            //checking if player2 wins the game
            else if ((Player1 =='P' || Player1=='p') && (Player2 =='S' || Player2=='s'))
            {
                cout << "Scissors cuts paper.";
            }
            //checking if game is draw
            else if ((Player1 =='R' ||Player2== 'r') ||
                (Player1 =='S' ||Player2== 's')||
                (Player1 =='S' ||Player2== 's')
                )
            {
                //print its draw
                cout << "Nobody wins.\n";
            }
            
            cout << "\n---------------------------------------------\n";   
            break;
            }
            
            case 7: 
            {
              string sign1, sign2;
 
            cout << "Horoscope Program which examines compatible signs." << endl; 
            cout << "Input 2 signs." << endl;
            cin >> sign1 >> sign2; 

            if (sign1 == "Aries" || sign1 == "Leo" || sign1 == "Sagittarius"){
                if (sign2 == "Aries" || sign2 == "Leo" || sign2 == "Sagittarius"){
                    cout << sign1 << " and " << sign2 << " are compatible Fire signs.";
                } else {
                    cout << sign1 << " and " << sign2 << " are not compatible signs.";
                }
            } 
            else if (sign1 == "Taurus" || sign1 == "Virgo" || sign1 == "Capricorn"){

                if (sign2 == "Taurus" || sign2 == "Virgo" || sign2 == "Capricorn"){
                    cout << sign1 << " and " << sign2 << " are compatible Earth signs.";
                } else {
                    cout << sign1 << " and " << sign2 << " are not compatible signs.";
                }
            } 
            else if (sign1 == "Gemini" || sign1 == "Libra" || sign1 == "Aquarius"){

                if (sign2 == "Gemini" || sign2 == "Libra" || sign2 == "Aquarius"){
                    cout << sign1 << " and " << sign2 << " are compatible Air signs.";
                } else {
                    cout << sign1 << " and " << sign2 << " are not compatible signs.";
                }
            } 
            else if (sign1 == "Cancer" || sign1 == "Scorpio" || sign1 == "Pisces"){
                if (sign2 == "Cancer" || sign2 == "Scorpio" || sign2 == "Pisces"){
                    cout << sign1 << " and " << sign2 << " are compatible Water signs.";
                } else {
                    cout << sign1 << " and " << sign2 << " are not compatible signs.";
                }
            }  
            cout << "\n---------------------------------------------\n";    
                break;
                
            }
            
            case 8: 
            {
                int acyr, n1, n10, n100, n1000;
    string rmYear, rmN, rmN10, rmN100, rmN1000;
    
    cout << "Arabic to Roman numeral conversion." << endl;
    cout << "Input the integer to convert." << endl;
    cin >> acyr;

    if(acyr >= 1000 && acyr <= 3000){
        
        n1 = acyr % 10;
        n10 = (acyr/10) % 10;
        n100 = (acyr/100) % 10;
        n1000 = (acyr/1000) % 10;
        
        switch(n1){
            case 0:
                rmN = "";
                break;
            case 1:
                rmN = "I";
                break;
            case 2:
                rmN = "II";
                break;
            case 3:
                rmN = "III";
                break;
            case 4:
                rmN = "IV";
                break;
            case 5:
                rmN = 'V';
                break;
            case 6:
                rmN = "VI";
                break;
            case 7:
                rmN = "VII";
                break;
            case 8:
                rmN = "VIII";
                break;
            case 9:
                rmN = "IX";
                break;
            default:
                rmN = "";
        }
        
        switch(n10){
            case 0:
                rmN10 = "";
                break;
            case 1:
                rmN10 = "X";
                break;
            case 2:
                rmN10 = "XX";
                break;
            case 3:
                rmN10 = "XXX";
                break;
            case 4:
                rmN10 = "XL";
                break;
            case 5:
                rmN10 = 'L';
                break;
            case 6:
                rmN10 = "LX";
                break;
            case 7:
                rmN10 = "LXX";
                break;
            case 8:
                rmN10 = "LXXX";
                break;
            case 9:
                rmN10 = "XC";
                break;
        }
        
        switch(n100){
            case 0:
                rmN100 = "";
                break;
            case 1:
                rmN100 = 'C';
                break;
            case 2:
                rmN100 = "CC";
                break;
            case 3:
                rmN100 = "CCC";
                break;
            case 4:
                rmN100 = "CD";
                break;
            case 5:
                rmN100 = 'D';
                break;
            case 6:
                rmN100 = "DC";
                break;
            case 7:
                rmN100 = "DCC";
                break;
            case 8:
                rmN100 = "DCCC";
                break;
            case 9:
                rmN100 = "CM";
                break;
        }
        
        switch(n1000){
            case 0:
                rmN1000 = "";
                break;
            case 1:
                rmN1000 = "M";
                break;
            case 2:
                rmN1000 = "MM";
                break;
            case 3:
                rmN1000 = "MMM";
                break;
        }
        cout << acyr << " is equal to " << rmN1000 + rmN100 + rmN10 + rmN;
        
    } else {
        cout << acyr << " is Out of Range!";
    }
    cout << "\n---------------------------------------------\n";
                break;
            }
     
    }
    }while(probNum>=1&&probNum<=8);
    
    //Exit
    return 0;
     }


