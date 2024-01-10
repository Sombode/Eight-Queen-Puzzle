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

void printBoard();
void resetBoard();
bool generateQueens();

int main()
{
	srand(time(0));
	// Runs generateQueens until it returns true (which is only when a solution is found)
	while (!generateQueens());
	printBoard();
	return 0;
}

// Function: printBoard
// Description: Prints the chessboard so the player can see what is happening
void printBoard()
{
	cout << "    a   b   c   d   e   f   g   h" << endl;
	cout << "  +---+---+---+---+---+---+---+---+" << endl;
	for (int row = 0; row < SIZE; row++)
	{
		cout << row + 1 << " ";
		for (int col = 0; col < SIZE; col++)
		{
			if (board[row][col] == false)
				// Print blank space if there is no queen at that space
				cout << "|   ";
			else
				// Print Q if there is a queen at that space
				cout << "| Q ";
		}
		cout << "| " << row + 1;
		cout << endl << "  +---+---+---+---+---+---+---+---+" << endl;
	}
	cout << "    a   b   c   d   e   f   g   h";
}

// Function: resetBoard
// Description: Sets all values in board back to zero (empty)
void resetBoard()
{
	for (int row = 0; row < SIZE; row++)
		for (int col = 0; col < SIZE; col++)
			board[row][col] = false;
}

// Function: generateQueens
// Description: Generates a solution to the 8 queens problem
bool generateQueens()
{
	// queens stores the x-position (column) of each queen sequentially from the top row to the bottom
	int queens[SIZE] = { 0 };
	for (int row = 0; row < SIZE; row++)
	{
		bool unplaceable[SIZE] = { false };
		for (int i = 0; i < row; i++)
		{
			// Mark the columns of the previous queens as unplaceable
			unplaceable[queens[i]] = true;
			// Mark the diagonal (down and to the right) of the queen as unplaceable if it does not go outside of the board
			if (queens[i] + (row - i) < SIZE)
				unplaceable[queens[i] + row - i] = true;
			// Mark the diagonal (down and to the left) of the queen as unplaceable if it does not go outside of the board
			if (queens[i] - (row - i) >= 0)
				unplaceable[queens[i] - (row - i)] = true;
		}

		// Do a quick check to make sure there is a possible space to place a queen
		int total = 0;
		for (int i = 0; i < SIZE; i++)
			total += unplaceable[i];
		if (total == SIZE)
		{
			// If every space is blocked by other queens: give up, reset the board, and return false
			resetBoard();
			return false;
		}

		// Randomizes the location of the column of where to put the queen (until a suitable location is found)
		int col;
		do
			col = rand() % SIZE;
		while (unplaceable[col]);
		board[row][col] = true;
		queens[row] = col;
	}
	// Return true when a solution is found
	return true;
}