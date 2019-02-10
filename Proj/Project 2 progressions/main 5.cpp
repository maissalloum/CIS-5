/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Project 2 version 4
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

/* Function Prototypes */
/* Function to print the menu and boards. */
void printMenu();
void printBoards(char boardP[][10], char boardC[][10]);

/* Functions that deal with placing the ships  */
/* on the screen. */
char toUpper(char ch);
int getDirection(char dir);
bool isInvalidInput(int row, int col, char direct);
void getShipLocation(int &row, int &col, int &direct, char board[][10], int size);

/* Functions that deal with Player/CPU moves */
/* and determines who the winner is. */
void getPlayerMove(char board[][10], int &row, int &col);
void getCPUMove(char board[][10], int &row, int &col);
void updateShips(vector<int> &counts, int size, string player);
bool hasWinner(char board[][10]);

/* Functions that deal with the Stats, Top 20, and Printing Tables. */
void seeStats(int games, int win);
void seeTop20ByName(string players[], int scores[], int size);
void seeTop20ByScore(string players[], int scores[], int size);
void swap(string &val1, string &val2);
void swap(int &val1, int &val2);
void printArrays(string players[], int scores[], int size);

/* Main Program */
int main()
{
	/* Number of wins, games, file name of txt file, and whether to repeat. */
	int sizes[] = { 5, 4, 3, 3, 2 };
	int win = 0, games = 0, numS = 0, choice = 0, topS[40];
	string fName = "battleshipStats.txt", topP[40];

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
		exit(0);
	}
	else {
		/* Read wins and number of games played from file, then close it. */
		/* Then read all scores that are available. */
		iFile >> win >> games;
		while (iFile >> topS[numS] >> topP[numS]) {
			numS++;
		}

		/* Close the input file. */
		iFile.close();
	}

	/* While the player still wants to play, play the game. */
	do {
		/* Print the menu of choices to do. */
		printMenu();

		/* Enter a choice to do. */
		cout << "Enter a choice (1-4): ";
		cin >> choice;

		/* Select the option. */
		switch (choice) 
		{
			case 1: {
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
					/* Put those ships from sizes into the vector. */
					vector<int> ships, pShips, cShips;
					for (int i = 0; i < 5; i++) {
						ships.push_back(sizes[i]);
						pShips.push_back(i + 1);
						cShips.push_back(i + 1);
					}

					/* 3 ships have 2 on the screen, so double it. */
					pShips[2] = cShips[2] = 6;

					/* Row,Col information from user, which direction to put the ship, and which direction to add to check for valid positions. */
					int row, col, direct, turns = 0;

					/* Used to see which direction the ship goes N, S, E, W. */
					int incR[] = { -1, 1, 0, 0 };
					int incC[] = { 0, 0, 1, -1 };

					/* Do all 5 ships. */
					for (int i = 0; i < 5; i++) {
						/* Get the ship's location from user.*/
						getShipLocation(row, col, direct, pBoard, ships[i]);

						/* Place the valid direction and position to the board. */
						for (int j = 0; j < ships[i]; j++) {
							int r = row + (j * incR[direct]), c = col + (j * incC[direct]);
							pBoard[r][c] = ships[i] + '0';
						}

						/* Place computer's ship onto the board as well. */
						int endR, endC;
						bool outRnge;
						do {
							/* Select a row and column randomly. */
							row = rand() % 10;
							col = rand() % 10;
							direct = rand() % 4;
							outRnge = false;

							/* Determine if you are out of range.  If so, repeat the while loop. */
							endR = row + (incR[direct] * (ships[i] - 1));
							endC = col + (incC[direct] * (ships[i] - 1));

							/* Determine if this choice of (row, col) and direction is valid. */
							for (int j = 0; j < ships[i]; j++) {
								int r = row + (j * incR[direct]), c = col + (j * incC[direct]);
								outRnge = outRnge || (eBoard[r][c] >= '2' && eBoard[r][c] <= '5');
							}

						} while (endR < 0 || endR > 9 || endC < 0 || endC > 9 || outRnge);

						/* Place the valid direction and position to the board. */
						for (int j = 0; j < ships[i]; j++) {
							int r = row + (j * incR[direct]), c = col + (j * incC[direct]);
							eBoard[r][c] = ships[i] + '0';
						}

						/* Print both boards to the computer. */
						printBoards(pBoard, eBoard);
					}

					/* Go 100 player turns*/
					do {
						if (turns % 2 == 0) {
							/* Make the player's move. */
							getPlayerMove(eBoard, row, col);
							cout << endl << "Player fires on: " << static_cast<char>(col + 'A') << (row + 1) << endl;

							/* See what the player hit or missed. */
							if (eBoard[row][col] >= '2' && eBoard[row][col] <= '5') {
								cout << "Hit!" << endl;
								updateShips(cShips, eBoard[row][col] - '0', "Player");
								eBoard[row][col] = '*';
							}
							else {
								cout << "Miss!" << endl;
								eBoard[row][col] = ' ';
							}
						}
						else {
							/* Make the CPU's move. */
							getCPUMove(pBoard, row, col);
							cout << endl << "CPU fires on: " << static_cast<char>(col + 'A') << (row + 1) << endl;

							/* See what the CPU hit or missed. */
							if (pBoard[row][col] >= '2' && pBoard[row][col] <= '5') {
								cout << "Hit!" << endl;
								updateShips(pShips, pBoard[row][col] - '0', "CPU");
								pBoard[row][col] = '*';
							}
							else {
								cout << "Miss!" << endl;
								pBoard[row][col] = ' ';
							}

							/* Print both boards to the computer. */
							printBoards(pBoard, eBoard);
						}
						/* One turn has gone by.*/
						turns++;

						/* End this game when either board has a winner. */
					} while (!hasWinner(eBoard) && !hasWinner(pBoard));

					/* Determine the winner by turn (odd for player, even for CPU) */
					if (turns % 2 == 1) {
						/* Description of win. */
						cout << endl << "You Win!" << endl;
						cout << "You scored " << (100 - (turns / 2)) << " points." << endl;

						/* Get the player's name. */
						cout << "Enter your name (1 word) for your score: ";
						string name;
						cin >> name;
						cout << endl;

						/* Update scores and players. */
						topP[numS] = name;
						topS[numS] = (100 - (turns / 2));
						numS++;

						/* Increase the number of wins. */
						win++;
					}
					else if (turns % 2 == 0) {
						cout << endl << "You Lost, Sorry!" << endl;
					}

					/* Increase the number of games played.*/
					games++; 
				}
				break;
			case 2: seeTop20ByName(topP, topS, numS); /* See top 20 by name. */
				break;
			case 3: seeTop20ByScore(topP, topS, numS); /* See top 20 by score. */
				break;
			case 4: seeStats(games, win); /* See stats of this file. */
				break;
			case 5: /* Quit. */
				break;
			default: cout << "Error: Invalid Choice." << endl; /* Bad input. */
		}
	} while (choice != 5);

	/* Use ofstream to write the wins and games to the file. */
	ofstream oFile;
	oFile.open(fName.c_str(), ios::in);

	/* Print wins and games played. */
	oFile << win << " " << games;
	oFile << endl << endl;

	/* Print top score, people as record. */
	for (int i = 0; i < numS && i < 20; i++) {
		oFile << topS[i] << " " << topP[i] << endl;
	}

	return 0;
}

/* Print menu of choices. */
void printMenu() {
	cout << "Battleship Game" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. See Top 20 Scores By Name" << endl;
	cout << "3. See Top 20 Scores By Score" << endl;
	cout << "4. See Statistics" << endl;
	cout << "5. Exit" << endl;
}

/* Converts lowercase letters to uppercase. */
char toUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return ch;
}

/* Get direction to go (N = 0, S = 1, E = 2, and W = 3) for valid directions. */
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

/* Determine if this is a valid (row, col) and direction. */
bool isInvalidInput(int row, int col, char direct) {
	return (col < 0 || col > 9 || row < 0 || row > 9 || (direct != 'N' && direct != 'S' && direct != 'E' && direct != 'W'));
}

/* Get the proper (row, col) and direction that is valid. */
void getShipLocation(int &row, int &col, int &direct, char board[][10], int size) {
	/* Directions of N, S, E, W. */
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

		/* Determine if this is a valid position that does not intercept with another ship. */
		for (int i = 0; i < size; i++) {
			int r = row + (i * incR[direct]), c = col + (i * incC[direct]);
			outRnge = outRnge || (board[r][c] >= '2' && board[r][c] <= '5');
		}

		/* Determine if you are out of range.  If so, repeat the while loop. */
		outRnge = (outRnge || endR < 0 || endR > 9 || endC < 0 || endC > 9);
	} while (isInvalidInput(row, col, dir) || outRnge);
}

/* Print the boards. */
void printBoards(char boardP[][10], char boardC[][10]) {
	/* Print the entire board, one line at a time. */
	cout << endl << setw(4) << " " << "ABCDEFGHIJ" << setw(18) << " " << "ABCDEFGHIJ" << endl;
	for (int i = 0; i < 10; i++) {
		/* Print one line of the player board. */
		cout << setw(4) << (i + 1);
		for (int j = 0; j < 10; j++) {
			cout << boardP[i][j];
		}

		/* Print one line of the computer board. */
		cout << setw(18) << (i + 1);
		for (int j = 0; j < 10; j++) {
			cout << (boardC[i][j] == '*' || boardC[i][j] == ' ' ? boardC[i][j] : '?');
		}
		cout << endl;
	}
	cout << setw(14) << "Player Board" << setw(29) << "Computer Board" << endl << endl;
}

/* Get the player's move. */
void getPlayerMove(char board[][10], int &row, int &col) {
	/* Get choice from user. */
	char cl;
	cout << "Enter a location to fire at (i.e. A8): ";
	cin >> cl >> row;

	/* Convert from (1-10) and (A-J) to only 0-9. */
	col = toUpper(cl) - 'A';
	row--;

	/* Check if valid choice. */
	while (row < 0 || row > 9 || col < 0 || col > 9 || board[row][col] == '*' || board[row][col] == ' ') {
		/* Get choice from user. */
		cout << "Error, bad or fired location try again (i.e. A8): ";
		cin >> cl >> row;

		/* Convert from (1-10) and (A-J) to only 0-9. */
		col = toUpper(cl) - 'A';
		row--;
	}
}

/* Get the CPU's move. */
void getCPUMove(char board[][10], int &row, int &col) {
	do {
		/* Get random choice (row, col). */
		row = static_cast<int>(fmod(rand(), 10));
		col = static_cast<int>(fmod(rand(), 10));
		/* Continue choosing until it is a valid move. */
	} while (board[row][col] == '*' || board[row][col] == ' ');
}

/* Determine if there is a winner. */
/* Winner appears when there are 0 numbers on the board. */
bool hasWinner(char board[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			/* If a number appears, automatically no win. */
			if (board[i][j] >= '2' && board[i][j] <= '5') {
				return false;
			}
		}
	}

	/* No number means win! */
	return true;
}

/* Update the ships on the screen. */
/* Sees if you sank a ship. */
void updateShips(vector<int> &counts, int size, string player) {
	/* Decrease this ship's count. */
	counts[size - 1]--;

	/* If zero, it's an automatic sink. */
	/* If 3 when ship is 3, then it's a sink. */
	if (counts[size - 1] == 0) {
		cout << player << " sank a " << size << "-Ship!" << endl;
	}
	else if (counts[size - 1] == 3 && size == 3) {
		cout << player << " sank a " << size << "-Ship!" << endl;
	}
}

/* See stats of the games/wins. */
void seeStats(int games, int win) {
	/* Print number of games won and played. */
	cout << endl << "Total Games Played: " << games << endl;
	cout << "Total Games Won: " << win << endl;

	/* Print percentage of wins to the screen. */
	float percent = (games != 0 ? static_cast<float>(win) / games : 0.0f);
	cout << "Total % Of Games Won: " << fixed << showpoint << setprecision(2) << percent * 100.0f << "%" << endl;
	cout << endl;
}

/* See the Top 20 by Alphabetical Ordered Names. */
/* Uses Selection Sort. */
void seeTop20ByName(string players[], int scores[], int size) {
	for (int i = 0; i < size; i++) {
		/* Choose i as initial best name. */
		int best = i;

		for (int j = i + 1; j < size; j++) {
			/* See if it is better, if so then make best as j. */
			if (players[j] < players[best]) {
				best = j;
			}
		}

		/* Swap i and best positions. */
		swap(players[i], players[best]);
		swap(scores[i], scores[best]);
	}

	/* Print out the list of information. */
	cout << endl << "Scores by Name: " << endl;
	printArrays(players, scores, size);
}

/* See the Top 20 by Decreasing Scores. */
/* Uses Bubble Sort. */
void seeTop20ByScore(string players[], int scores[], int size) {
	bool spd;
	do {
		/* Flag for no swapped positions.*/
		spd = false;
		for (int i = 1; i < size; i++) {
			/* If an object is out of order, swap and mark spd. */
			if (scores[i - 1] < scores[i]) {
				swap(players[i], players[i - 1]); 
				swap(scores[i], scores[i - 1]);
				spd = true;
			}
		}
	} while (spd);

	/* Print out the list of information. */
	cout << endl << "Scores by Scores: " << endl;
	printArrays(players, scores, size);
}

/* Swaps two values of strings.*/
void swap(string &val1, string &val2)
{
	string temp = val1;
	val1 = val2;
	val2 = temp;
}

/* Swaps two values of integers. */
void swap(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

/* Print out arrays of information. */
void printArrays(string players[], int scores[], int size) {
	/* Go through all 20 names.*/
	for (int i = 0; i < size && i < 20; i++) {
		cout << players[i] << " " << scores[i] << endl;
	}
	cout << endl;
}