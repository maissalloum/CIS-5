/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Lab 1
 * Author: Mais Salloum
 * Professor: Dr. Lehr
 * Created on January 8, 2019, 9:47 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float milBdgt, fedBdgt, mlPrcnt;
    milBdgt=7.0e11f;    //Military Budget = 700 Billion   
    fedBdgt=4.1e12f;    //Federal Budget  = 4.1 Trillion
    mlPrcnt= (milBdgt/fedBdgt) * 100;
    cout<<"The military budget as a percentage of the federal budget is ";
    cout<< mlPrcnt << "%";
    return 0;
}

