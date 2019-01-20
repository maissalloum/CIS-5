/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Rock Paper Scissors 
 */
 
#include <iostream>
using namespace std;
int main()
{
   // Variable declaration
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



   return 0;


}
