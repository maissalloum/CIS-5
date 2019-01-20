/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose:  Number Conversion from Arabic to Roman
 */
 
#include <iostream> 
#include <string>
using namespace std;

int main(int argc, char** argv) {
    
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
 
    return 0;
}