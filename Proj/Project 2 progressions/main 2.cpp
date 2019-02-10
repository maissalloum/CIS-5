/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Project 2 version 1 
 */

/* Included Files */
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char toUpper(char ch);
int getDirection(char dir);
bool isInvalidInput(int row, int col, char direct);
void getShipLocation(int &row, int &col, int &direct, char board[][10], int size);
void printBoards(char boardP[][10], char boardC[][10]);

/* Main Program */
int main()
{
	/* Number of wins, games, file name of txt file, and whether to repeat. */
	int sizes[] = { 5, 4, 3, 3, 2 };
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
		/* 10x10 Board for the Player. */
		/* 10x10 Board for the Computer. */
		char pBoard[10][10], eBoard[10][10];

		/* Clear the entire player and computer boards. */
		/* Set the entire board to '-'*/
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				pBoard[i][j] = eBoard[i][j] = '-';
			}
		}

		/* Print both boards to the computer. */
		printBoards(pBoard, eBoard);

		/* Size of the boat to put in (battleship for now). */
		vector<int> myShips;
		vector<int> cmShips;
		
		for (int i = 0; i < 5; i++) {
			myShips.push_back(sizes[i]);
			cmShips.push_back(sizes[i]);
		}

		/* Row,Col information from user, which direction to put the ship, and which direction to add to check for valid positions. */
		int row, col, direct;

		/* Check if out of range. */
		int incR[] = { -1, 1, 0, 0 };
		int incC[] = { 0, 0, 1, -1 };

		for (int i = 0; i < 5; i++) {
			getShipLocation(row, col, direct, pBoard, myShips[i]);
			for (int j = 0; j < myShips[i]; j++) {
				int r = row + (j * incR[static_cast<int>(direct)]);
				int c = col + (j * incC[static_cast<int>(direct)]);
				pBoard[r][c] = myShips[i] + '0';
			}

			/* Place computer's ship onto the board as well. */
			int endR, endC;
			bool outRnge;
			do {
				/* Select a row and column randomly. */
				row = static_cast<int>(fmod(rand(), 10));
				col = static_cast<int>(fmod(rand(), 10));
				int direct = static_cast<int>(fmod(rand(), 4));
				outRnge = false;

				/* Determine if you are out of range.  If so, repeat the while loop. */
				endR = row + (incR[direct] * (cmShips[i] - 1));
				endC = col + (incC[direct] * (cmShips[i] - 1));

				for (int i = 0; i < cmShips[i]; i++) {
					int r = row + (i * incR[direct]), c = col + (i * incC[direct]);
					outRnge = outRnge || (eBoard[r][c] >= '2' && eBoard[r][c] <= '5');
				}

			} while (endR < 0 || endR > 9 || endC < 0 || endC > 9 || outRnge);

			for (int j = 0; j < cmShips[i]; j++) {
				int r = row + (j * incR[static_cast<int>(direct)]);
				int c = col + (j * incC[static_cast<int>(direct)]);
				eBoard[r][c] = cmShips[i] + '0';
			}

			/* Print both boards to the computer. */
			printBoards(pBoard, eBoard);
		}

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

char toUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return ch;
}

int getDirection(char dir) {
	switch (dir)
	{
		case 'N': return 0;
		case 'S': return 1;
		case 'E': return 2;
		case 'W': return 3;
		default: return -1;
	}
}

bool isInvalidInput(int row, int col, char direct) {
	return (col < 0 || col > 9 || row < 0 || row > 9 || (direct != 'N' && direct != 'S' && direct != 'E' && direct != 'W'));
}

void getShipLocation(int &row, int &col, int &direct, char board[][10], int size) {
	int incR[] = {-1, 1, 0, 0};
	int incC[] = {0, 0, 1, -1};
	char dir, cl;
	bool outRnge = false;

	/* Ask the user for row, column, and direction and input it in. */
	cout << "Enter start location and direction (N,S,E,W), i.e. A1 N or B10 E" << endl;
	cout << "This is for a ship of size " << size << ": ";
	cin >> cl >> row >> dir;

	/* If column or direction is lowercase, make it uppercase. */
	row--;
	col = toUpper(cl) - 'A';
	dir = toUpper(dir);

	do
	{
		/* Is the column, row, and direction valid? (col must be A-J, row must be 1-2, and direction must be N, S, W, and E) */
		while (isInvalidInput(row, col, dir) || outRnge) {
			/* Let user know it's bad and re-enter information. */
			cout << "Error: Bad location/direction, please enter another of size " << size << " (A9 N, B7 S): ";
			cin >> cl >> row >> dir;

			/* If column or direction is lowercase, make it uppercase. */
			row--;
			col = toUpper(cl) - 'A';
			dir = toUpper(dir);

			/* Reset the fact that it is out of range. */
			outRnge = false;
		}

		/* Determine which way to add (columns or rows) if given N (+row), S (-row), E (+col), or W (-col). */
		/* Calculate the end position of the ship in that direction: (endR,endC) */
		direct = getDirection(dir);
		int endR = (size - 1) * incR[direct] + row;
		int endC = (size - 1) * incC[direct] + col;

		for (int i = 0; i < size; i++) {
			int r = row + (i * incR[direct]), c = col + (i * incC[direct]);
			outRnge = outRnge || (board[r][c] >= '2' && board[r][c] <= '5');
		}

		/* Determine if you are out of range.  If so, repeat the while loop. */
		outRnge = (outRnge || endR < 0 || endR > 9 || endC < 0 || endC > 9);
	} while (isInvalidInput(row, col, dir) || outRnge);
}

void printBoards(char boardP[][10], char boardC[][10]) {
	/* Print the entire board, one line at a time. */
	cout << setw(4) << " " << "ABCDEFGHIJ" << setw(18) << " " << "ABCDEFGHIJ" << endl;
	for (int i = 0; i < 10; i++) {
		/* Print one line of the player board. */
		cout << setw(4) << (i + 1);
		for (int j = 0; j < 10; j++) {
			cout << boardP[i][j];
		}

		/* Print one line of the computer board. */
		cout << setw(18) << (i + 1);
		for (int j = 0; j < 10; j++) {
			cout << (boardC[i][j] == '-' ? '?' : boardC[i][j]);
		}
		cout << endl;
	}
	cout << setw(14) << "Player Board" << setw(29) << "Computer Board" << endl << endl;
}