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

// IDEA: Take ONE list 0-8 and shuffle to get queen positions, repeat until no diagonals intersect

int main()
{
	srand(time(0));
	do {} while (!generateQueens());
	printBoard();
	return 0;
}

// Function: printBoard
// Description: Prints the chessboard so the player can see what is happening
void printBoard()
{
	cout << "    a   b   c   d   e   f   g   h\n";
	cout << "  +---+---+---+---+---+---+---+---+\n";
	for (int r = 0; r < SIZE; r++)
	{
		cout << r+1 << " ";
		for (int c = 0; c < SIZE; c++)
		{
			if (board[r][c] == false)
			{
				cout << "|   ";
			}
			else
			{
				cout << "| Q ";
			}
		}
		cout << "| " << r + 1;
		cout << "\n  +---+---+---+---+---+---+---+---+\n";
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
	bool unplaceable[SIZE] = { false };
	int queens[SIZE] = { 0 };
	for (int row = 0; row < SIZE; row++)
	{
		bool unplaceableDiagonal[SIZE] = { false };
		for (int i = 0; i < row; i++)
		{
			if (queens[i] + (row - i) < SIZE)
				unplaceableDiagonal[queens[i] + row - i] = true;
			if (queens[i] - (row - i) >= 0)
				unplaceableDiagonal[queens[i] - (row - i)] = true;
		}
		int total = 0;
		for (int i = 0; i < SIZE; i++)
			total += (unplaceable[i] || unplaceableDiagonal[i]);
		if (total == SIZE)
		{
			// give up and retry
			return false;
		}
		int col;
		do
		{
			col = rand() % SIZE;
		} while (unplaceable[col] || unplaceableDiagonal[col]);
		board[row][col] = true;
		unplaceable[col] = true;
		queens[row] = col;
		queens[row] = col;
	}
	return true;
}