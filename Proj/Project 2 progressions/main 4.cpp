/* 
 * File:   main.cpp
 * Author: Mais Salloum
 * Purpose: Project 2 version 3
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
void getPlayerMove(char board[][10], int &row, int &col);
void getCPUMove(char board[][10], int &row, int &col);
void updateShips(vector<int> &counts, int size, string player);
bool hasWinner(char board[][10]);
void printMenu();
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
	int win = 0, games = 0, numS = 0, choice = 0;
	string fName = "battleshipStats.txt";

	string topP[40];
	int topS[40];

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
		iFile >> win >> games;
		while (iFile >> topS[numS] >> topP[numS]) {
			numS++;
		}
		iFile.close();
	}

	/* While the player still wants to play, play the game. */
	do {
		printMenu();
		cout << "Enter a choice (1-4): ";
		cin >> choice;

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
					pShips[2] = cShips[2] = 6;

					/* Row,Col information from user, which direction to put the ship, and which direction to add to check for valid positions. */
					int row, col, direct, turns = 0;

					/* Check if out of range. */
					int incR[] = { -1, 1, 0, 0 };
					int incC[] = { 0, 0, 1, -1 };

					for (int i = 0; i < 5; i++) {
						getShipLocation(row, col, direct, pBoard, ships[i]);
						for (int j = 0; j < ships[i]; j++) {
							int r = row + (j * incR[direct]);
							int c = col + (j * incC[direct]);
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

							for (int j = 0; j < ships[i]; j++) {
								int r = row + (j * incR[direct]), c = col + (j * incC[direct]);
								outRnge = outRnge || (eBoard[r][c] >= '2' && eBoard[r][c] <= '5');
							}

						} while (endR < 0 || endR > 9 || endC < 0 || endC > 9 || outRnge);

						for (int j = 0; j < ships[i]; j++) {
							int r = row + (j * incR[direct]);
							int c = col + (j * incC[direct]);
							eBoard[r][c] = ships[i] + '0';
						}

						/* Print both boards to the computer. */
						printBoards(pBoard, eBoard);
					}

					/* Go 100 player turns*/
					do {
						if (turns % 2 == 0) {
							getPlayerMove(eBoard, row, col);
							cout << endl << "Player fires on: " << static_cast<char>(col + 'A') << (row + 1) << endl;
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
							getCPUMove(pBoard, row, col);
							cout << endl << "CPU fires on: " << static_cast<char>(col + 'A') << (row + 1) << endl;
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
						turns++;
					} while (!hasWinner(eBoard) && !hasWinner(pBoard));

					if (turns % 2 == 1) {
						cout << endl << "You Win!" << endl;
						cout << "You scored " << (100 - (turns / 2)) << " points." << endl;
						cout << "Enter your name for your score: ";

						string name;
						cin >> name;
						cout << endl;
						win++;
					}
					else if (turns % 2 == 0) {
						cout << endl << "You Lost, Sorry!" << endl;
					}
					games++; 
				}
				break;
			case 2: seeTop20ByName(topP, topS, numS);
				break;
			case 3: seeTop20ByScore(topP, topS, numS); 
				break;
			case 4: seeStats(games, win);
				break;
			case 5:
				break;
			default: cout << "Error: Invalid Choice." << endl;
		}
	} while (choice != 5);

	/* Use ofstream to write the wins and games to the file. */
	ofstream oFile;
	oFile.open(fName.c_str(), ios::in);

	oFile << win << " " << games;
	oFile << endl << endl;

	for (int i = 0; i < numS && i < 20; i++) {
		oFile << topS[i] << " " << topP[i] << endl;
	}

	return 0;
}

char toUpper(char ch) {
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	else
		return ch;
}

char toUpper(int ch) {
	if (ch >= 97 && ch <= 122)
		return static_cast<char>(ch - 32);
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
			cout << boardC[i][j]; // (boardC[i][j] == '*' || boardC[i][j] == ' ' ? boardC[i][j] : '?');
		}
		cout << endl;
	}
	cout << setw(14) << "Player Board" << setw(29) << "Computer Board" << endl << endl;
}

void getPlayerMove(char board[][10], int &row, int &col) {
	char cl;
	cout << "Enter a location to fire at (i.e. A8): ";
	cin >> cl >> row;
	col = toUpper(cl) - 'A';
	row--;

	while (row < 0 || row > 9 || col < 0 || col > 9 || board[row][col] == '*' || board[row][col] == ' ') {
		cout << "Error, bad or fired location try again (i.e. A8): ";
		cin >> cl >> row;
		col = toUpper(cl) - 'A';
		row--;
	}
}

void getCPUMove(char board[][10], int &row, int &col) {
	do {
		row = static_cast<int>(fmod(rand(), 10));
		col = static_cast<int>(fmod(rand(), 10));
	} while (board[row][col] == '*' || board[row][col] == ' ');
}

bool hasWinner(char board[][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] >= '2' && board[i][j] <= '5') {
				return false;
			}
		}
	}
	return true;
}

void updateShips(vector<int> &counts, int size, string player) {
	counts[size - 1]--;
	if (counts[size - 1] == 0) {
		cout << player << " sank a " << size << "-Ship!" << endl;
	}
	else if (counts[size - 1] == 3 && size == 3) {
		cout << player << " sank a " << size << "-Ship!" << endl;
	}
}

void printMenu() {
	cout << "Battleship Game" << endl;
	cout << "1. Play Game" << endl;
	cout << "2. See Top 20 Scores By Name" << endl;
	cout << "3. See Top 20 Scores By Score" << endl;
	cout << "4. See Statistics" << endl;
	cout << "5. Exit" << endl;
}

void seeStats(int games, int win) {
	/* Print number of games won and played. */
	cout << endl << "Total Games Played: " << games << endl;
	cout << "Total Games Won: " << win << endl;

	/* Print percentage of wins to the screen. */
	float percent = (games != 0 ? static_cast<float>(win) / games : 0.0f);
	cout << "Total % Of Games Won: " << fixed << showpoint << setprecision(2) << percent * 100.0f << "%" << endl;
	cout << endl;
}

void seeTop20ByName(string players[], int scores[], int size) {
	for (int i = 0; i < size; i++) {
		int best = i;
		for (int j = i + 1; j < size; j++) {
			if (players[j] < players[best]) {
				best = j;
			}
		}

		swap(players[i], players[best]);
		swap(scores[i], scores[best]);
	}

	cout << endl << "Scores by Name: " << endl;
	printArrays(players, scores, size);
}

void seeTop20ByScore(string players[], int scores[], int size) {
	bool spd;
	do {
		spd = false;
		for (int i = 1; i < size; i++) {
			if (scores[i - 1] < scores[i]) {
				swap(players[i], players[i - 1]); 
				swap(scores[i], scores[i - 1]);
				spd = true;
			}
		}
	} while (spd);

	cout << endl << "Scores by Scores: " << endl;
	printArrays(players, scores, size);
}

void swap(string &val1, string &val2)
{
	string temp = val1;
	val1 = val2;
	val2 = temp;
}

void swap(int &val1, int &val2)
{
	int temp = val1;
	val1 = val2;
	val2 = temp;
}

void printArrays(string players[], int scores[], int size) {
	for (int i = 0; i < size; i++) {
		cout << players[i] << " " << scores[i] << endl;
	}
	cout << endl;
}