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

// IDEA: Take ONE list 0-8 and shuffle to get queen positions, repeat until no diagonals intersect

int main()
{
	srand(time(0));
	int nums[SIZE];
	bool unplaceable[SIZE] = { false };
	int queens[SIZE] = { 0 };
	for (int row = 0; row < SIZE; row++)
	{
		for (int i = 0; i < row - 1; i++)
		{
			unplaceable;
			cout << queens[i] << " is " << row - i - 1 << " rows up from " << row << endl;
		}
		int col;
		do
		{
			col = rand() % SIZE;
		} while (unplaceable[col]);
		board[row][col] = true;
		unplaceable[col] = true;
		queens[row] = col;
	}
	printBoard(board);
	return 0;
}

// Function: printBoard
// Description: Prints the chessboard so the player can see what is happening
void printBoard(bool board[SIZE][SIZE])
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
