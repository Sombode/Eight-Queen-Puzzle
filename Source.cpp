// Jaden Satheesh, Levy Le, Joel Underkoffler
// Period 1
// January 8th, 2023
// Eight of Queens

#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

const int SIZE = 8;
// Initialize the chessboard with all spaces empty (true = queen)
bool board[SIZE][SIZE] = { false };

void printBoard(bool board[SIZE][SIZE]);
bool checkQueens(bool board[SIZE][SIZE]);

// IDEA: Take two lists 0-8 (one for columns and one for rows) and shuffle to get queen positions, repeat until no diagonals intersect

int main()
{
	printBoard(board);
	return 0;
}

// Function: checkQueens
// Description: Checks a chessboard to make sure no queens conflict with each other
bool checkQueens(bool board[SIZE][SIZE])
{
	// Check each row
	for (int row = 0; row < SIZE; row++)
	{
		int queenCount = 0;
		for (int col = 0; col < SIZE; col++)
			if (board[row][col])
				queenCount++;
		if (queenCount != 1)
			return false;
	}

	// Check each column
	for (int col = 0; col < SIZE; col++)
	{
		int queenCount = 0;
		for (int row = 0; row < SIZE; row++)
			if (board[row][col])
				queenCount++;
		if (queenCount != 1)
			return false;
	}

}

	// TODO: Check diagonals (painful)
	// TODO: Maybe optimize

// joel change

void printBoard(bool board[SIZE][SIZE])
{
	for (int r = 0; r < SIZE; r++)
	{
		for (int c = 0; c < SIZE; c++)
		{
			if (board[r][c] == false)
			{
				cout << "0 ";
			}
			else
			{
				cout << "Q ";
			}
		}
		cout << "\n";
	}
}