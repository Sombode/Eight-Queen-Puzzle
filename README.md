# Eight Queens Puzzle

*Levy Le, Jaden Satheesh, Joel Underkoffler*
*CS2 Period 1*

# Function

This program solves the classic eight queens puzzle. Running the program will print a chessboard with a (random) valid solution to the puzzle.
Given a regular (8x8) chessboard, the goal is to find a configuration of eight queens on the board in which no queen can attack the other.
Queens can attack each other if they are in the same column, row, or diagonal.

# Algorithm

The chessboard is iterated through sequentially row-by-row. For each row, a random column is picked. If a queen can be placed in that spot, then it will be placed there.
If a queen cannot go in that spot, then another random column is picked until a suitable location is found. If there are no avaliable spaces, then the board is reset and
the program attempts to generate another solution. The positions of queens are stored in another array so that before each iteration,
the columns that previous queens are in are marked as blocked (unplaceable). Any spaces in the same diagonal as other queens are also marked as blocked.
