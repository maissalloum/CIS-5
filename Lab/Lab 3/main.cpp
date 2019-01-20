/* 
 * File:   Oil Taxes
 * Author: Mais Salloum
 *
 * Created on January 16, 2019, 8:20 PM
 */

#include <iostream>
#include <iomanip>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float cost, excise, sales, feetax, federal, totalt, prcntT, range;
    cout << "Input cost per gallon:\n";
    cin >> cost;
    
    excise = 0.39;
    sales = .08*cost;
    feetax = .10;
    federal = .184;
    totalt = excise+sales+feetax+federal;
    prcntT = (totalt/cost)*100;
    range = prcntT-6.5;
    
    if (prcntT > 6.5)
        cout << "Tax% per gallon is greater than profit% per gallon by " << range << "%\n";
    
    
    return 0;
}

