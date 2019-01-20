/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Compatible Horoscope Signs 
 */
#include <iostream>  
#include <string>
using namespace std;

int main(int argc, char** argv) {
 
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
   
    return 0;
}
