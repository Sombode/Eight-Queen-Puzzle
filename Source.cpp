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

int main()
{
	printBoard(board);
	return 0;
}
// change

// another change

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