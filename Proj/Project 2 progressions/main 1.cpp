/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Project 1 
 */

/* Included Files */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

/* Main Program */
int main()
{
	/* Number of wins, games, file name of txt file, and whether to repeat. */
	int win = 0, games = 0;
	string fName = "battleshipStats.txt";
	char repeat = 'y';

	/* Randomize numbers for choosing computer player's 4-boat (battleship). */
	srand(time(NULL));

	/* Open txt file (battleshipStats.txt) for reading. */
	ifstream iFile;
	iFile.open(fName.c_str(), ios::in);

	/* If file cannot open, create a file. */
	if (!iFile) {
		/* Create the file for game stats. */
		ofstream oFile;
		oFile.open(fName.c_str(), ios::out);

		/* Close new file. */
		oFile.close();
	}
	else {
		/* Read wins and number of games played from file, then close it. */
		iFile >> win >> games;
		iFile.close();
	}

	/* While the player still wants to play, play the game. */
	while (repeat == 'y' || repeat == 'Y') {
		/* 2x10 Board for the Player. */
		char space1 = '-', space2 = '-', space3 = '-', space4 = '-', space5 = '-', space6 = '-', space7 = '-', space8 = '-', space9 = '-', space10 = '-';
		char space11 = '-', space12 = '-', space13 = '-', space14 = '-', space15 = '-', space16 = '-', space17 = '-', space18 = '-', space19 = '-', space20 = '-';

		/* 2x10 Board for the Computer. */
		char enemy1 = '?', enemy2 = '?', enemy3 = '?', enemy4 = '?', enemy5 = '?', enemy6 = '?', enemy7 = '?', enemy8 = '?', enemy9 = '?', enemy10 = '?';
		char enemy11 = '?', enemy12 = '?', enemy13 = '?', enemy14 = '?', enemy15 = '?', enemy16 = '?', enemy17 = '?', enemy18 = '?', enemy19 = '?', enemy20 = '?';

		/* Print both boards to the computer. */
		cout << endl;
		cout << setw(4) << " " << "ABCDEFGHIJ" << setw(18) << " " << "ABCDEFGHIJ" << endl;
		cout << setw(4) << "1" << space1 << space2 << space3 << space4 << space5 << space6 << space7 << space8 << space9 << space10;
		cout << setw(18) << "1" << enemy1 << enemy2 << enemy3 << enemy4 << enemy5 << enemy6 << enemy7 << enemy8 << enemy9 << enemy10 << endl;
		cout << setw(4) << "2" << space11 << space12 << space13 << space14 << space15 << space16 << space17 << space18 << space19 << space20;
		cout << setw(18) << "2" << enemy11 << enemy12 << enemy13 << enemy14 << enemy15 << enemy16 << enemy17 << enemy18 << enemy19 << enemy20 << endl;
		cout << setw(14) << "Player Board" << setw(28) << "Computer Board" << endl << endl;

		/* Size of the boat to put in (battleship for now). */
		int size = 4;

		/* Row,Col information from user, which direction to put the ship, and which direction to add to check for valid positions. */
		int row, endR = 1, endC = 1, incR = 0, incC = 0;
		char col, direct;

		/* Check if out of range. */
		bool outRnge = false;

		/* Ask the user for row, column, and direction and input it in. */
		cout << "Enter start location (A2,B1,J1) and direction (N,S,E,W) of size " << size << ": ";
		cin >> col >> row >> direct;

		/* If column or direction is lowercase, make it uppercase. */
		if (col >= 'a' && col <= 'j')
			col -= 32;
		if (direct >= 'a' && direct <= 'j')
			direct -= 32;

		do
		{
			/* Is the column, row, and direction valid? (col must be A-J, row must be 1-2, and direction must be N, S, W, and E) */
			while (col < 'A' || col > 'J' || row < 1 || row > 2 || (direct != 'N' && direct != 'S' && direct != 'E' && direct != 'W') || outRnge) {
				/* Let user know it's bad and re-enter information. */
				cout << "Error: Bad location/direction, please enter another of size " << size << " (A9 N, B7 S): ";
				cin >> col >> row >> direct;

				/* If column or direction is lowercase, make it uppercase. */
				if (col >= 'a' && col <= 'j')
					col -= 32;
				if (direct >= 'a' && direct <= 'j')
					direct -= 32;

				/* Reset the fact that it is out of range. */
				endR = endC = 1;
				outRnge = false;
			}

			/* Determine which way to add (columns or rows) if given N (+row), S (-row), E (+col), or W (-col). */
			incR = incC = 0;
			switch(direct)
			{
				case 'N': incR = 1;
					break;
				case 'S': incR = -1;
					break;
				case 'E': incC = 1;
					break;
				case 'W': incC = -1;
					break;
			}

			/* Calculate the end position of the ship in that direction: (endR,endC) */
			endR = (size - 1) * incR + row;
			endC = (size - 1) * incC + (col - 'A' + 1);

			/* Determine if you are out of range.  If so, repeat the while loop. */
			outRnge = (endR < 1 || endR > 2 || endC < 1 || endC > 10);
		} while (outRnge);

		/* Put player boat into board. */
		for (int i = 0; i < size; i++) {
			/* Calculate current position (r,c). */
			int r = row + (incR * i), c = (col - 'A' + 1) + (incC * i);

			/* If in the first row. */
			if (r == 1) {
				/* Put into space1 to space10 depending on c. */
				if (c == 1)
					space1 = size + '0';
				else if (c == 2)
					space2 = size + '0';
				else if (c == 3)
					space3 = size + '0';
				else if (c == 4)
					space4 = size + '0';
				else if (c == 5)
					space5 = size + '0';
				else if (c == 6)
					space6 = size + '0';
				else if (c == 7)
					space7 = size + '0';
				else if (c == 8)
					space8 = size + '0';
				else if (c == 9)
					space9 = size + '0';
				else
					space10 = size + '0';
			}
			else {
				/* Put into space11 to space20 depending on c. */
				if (c == 1) 
					space11 = size + '0';
				else if (c == 2) 
					space12 = size + '0';
				else if (c == 3) 
					space13 = size + '0';
				else if (c == 4) 
					space14 = size + '0'; 
				else if (c == 5) 
					space15 = size + '0';
				else if (c == 6) 
					space16 = size + '0';
				else if (c == 7) 
					space17 = size + '0';
				else if (c == 8) 
					space18 = size + '0';
				else if (c == 9) 
					space19 = size + '0';
				else 
					space20 = size + '0';
			}
		}

		/* Place computer's ship onto the board as well. */
		do {
			/* Select a row and column randomly. */
			row = static_cast<int>(fmod(rand(), 2)) + 1;
			col = static_cast<char>(fmod(rand(), 10) + 1);
			incR = incC = 0;

			/* Select a direction randomly to choose N, S, E, or W. */
			switch (static_cast<int>(fmod(rand(), 4) + 1))
			{
				case 1: incR = 1;
					break;
				case 2: incR = -1;
					break;
				case 3: incC = 1;
					break;
				case 4: incC = -1;
					break;
			}

			/* Calculate the end position of the ship in that direction: (endR,endC) */
			endR = (size - 1) * incR + row;
			endC = (size - 1) * incC + col;

			/* Determine if you are out of range.  If so, repeat the while loop. */
			outRnge = (endR < 1 || endR > 2 || endC < 1 || endC > 10);
		} while (outRnge);

		/* Put computer boat into board. */
		for (int i = 0; i < size; i++) {
			/* Calculate current position (r,c). */
			int r = row + (incR * i), c = col + (incC * i);

			/* If in the first row. */
			if (r == 1) {
				/* Put into enemy space1 to space10 depending on c. */
				switch (c) {
					case 1: enemy1 = size + '0'; 
						break;
					case 2: enemy2 = size + '0'; 
						break;
					case 3: enemy3 = size + '0'; 
						break;
					case 4: enemy4 = size + '0'; 
						break;
					case 5: enemy5 = size + '0'; 
						break;
					case 6: enemy6 = size + '0'; 
						break;
					case 7: enemy7 = size + '0'; 
						break;
					case 8: enemy8 = size + '0'; 
						break;
					case 9: enemy9 = size + '0'; 
						break;
					case 10: enemy10 = size + '0'; 
						break;
				}
			}
			else {
				/* Put into enemy space11 to space20 depending on c. */
				switch (c) {
					case 1: enemy11 = size + '0'; 
						break;
					case 2: enemy12 = size + '0'; 
						break;
					case 3: enemy13 = size + '0'; 
						break;
					case 4: enemy14 = size + '0'; 
						break;
					case 5: enemy15 = size + '0'; 
						break;
					case 6: enemy16 = size + '0'; 
						break;
					case 7: enemy17 = size + '0'; 
						break;
					case 8: enemy18 = size + '0'; 
						break;
					case 9: enemy19 = size + '0'; 
						break;
					case 10: enemy20 = size + '0'; 
						break;
				}
			}
		}

		/* Print both boards to the computer. */
		cout << endl;
		cout << setw(4) << " " << "ABCDEFGHIJ" << setw(18) << " " << "ABCDEFGHIJ" << endl;
		cout << setw(4) << "1" << space1 << space2 << space3 << space4 << space5 << space6 << space7 << space8 << space9 << space10;
		cout << setw(18) << "1" << enemy1 << enemy2 << enemy3 << enemy4 << enemy5 << enemy6 << enemy7 << enemy8 << enemy9 << enemy10 << endl;
		cout << setw(4) << "2" << space11 << space12 << space13 << space14 << space15 << space16 << space17 << space18 << space19 << space20;
		cout << setw(18) << "2" << enemy11 << enemy12 << enemy13 << enemy14 << enemy15 << enemy16 << enemy17 << enemy18 << enemy19 << enemy20 << endl;
		cout << setw(14) << "Player Board" << setw(28) << "Computer Board" << endl << endl;

		/* Ask and get input from user to play again. */
		cout << "Play again (y/n)?: ";
		cin >> repeat;
	}

	/* Print number of games won and played. */
	cout << endl << "Total Games Played: " << games << endl;
	cout << "Total Games Won: " << win << endl;

	/* Print percentage of wins to the screen. */
	float percent = (games != 0 ? static_cast<float>(win) / games : 0.0f);
	cout << "Total % Of Games Won: " << fixed << showpoint << setprecision(2) << percent * 100.0f << "%" << endl;

	/* Use ofstream to write the wins and games to the file. */
	ofstream oFile;
	oFile.open(fName.c_str(), ios::in);
	oFile << win << " " << games;

	return 0;
}