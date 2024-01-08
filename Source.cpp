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

bool checkQueens(bool[SIZE][SIZE]);

int main()
{


	return 0;
}

// Function: checkQueens
// Description: Checks a chessboard to make sure no queens conflict with each other
bool checkQueens(bool board[SIZE][SIZE]) {
	// Check each row
	for (int row = 0; row < SIZE; row++) {
		int queenCount = 0;
		for (int col = 0; col < SIZE; col++)
			if (board[row][col])
				queenCount++;
		if (queenCount > 1)
			return false;
	}

	// Check each column
	for (int col = 0; col < SIZE; col++) {
		int queenCount = 0;
		for (int row = 0; row < SIZE; row++)
			if (board[row][col])
				queenCount++;
		if (queenCount > 1)
			return false;
	}

	// TODO: Check diagonals (painful)
	// TODO: Maybe optimize

	return true;
}