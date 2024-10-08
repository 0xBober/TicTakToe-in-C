Tic-Tac-Toe Game in C
Description

This C program implements a simple Tic-Tac-Toe game that allows two players to play a configurable number of rounds. The game is played on a 3x3 board, with Player 1 using 'X' and Player 2 using 'O'. Players take turns placing their marks on the board by inputting the coordinates of their desired positions. The game checks for a winner after each move, and if no player wins, it checks for a draw.
How It Works

    The program first prompts the user for the number of rounds they would like to play.
    For each round, the game initializes an empty 3x3 board.
    Players take turns placing their marks ('X' or 'O') on the board by entering the row and column number.
    After each move, the program checks if a player has won or if the game has ended in a draw.
    The game clears the console after each move to display the updated board.
    If a player wins or the game ends in a draw, the round ends, and the game moves on to the next round.

Features

    Board Initialization: The board is represented as a 3x3 grid filled with spaces (' ') to denote empty cells.
    Player Move Insertion: Players input the coordinates where they want to place their mark. If a move is invalid (i.e., the cell is already occupied), the player is prompted to choose another position.
    Win/Draw Validation:
        The program checks rows, columns, and diagonals to determine if a player has won.
        If all cells are filled and no player has won, it declares a draw.
    Multiple Rounds: The game continues for the number of rounds specified at the beginning, with each round resetting the board.
    Clear Screen Functionality: The program clears the console after each move for a cleaner visual representation using the system("cls") function (specific to Windows).

Game Functions
1. initializeTable(char table[SIZE][SIZE])

    Initializes the 3x3 table with empty cells (' ').

2. displayTable(char table[SIZE][SIZE])

    Displays the current state of the 3x3 table in a grid format.

3. applyInsertionOfCharIntoTable(char table[SIZE][SIZE], int x, int y, char MainPlayer)

    Inserts the player's mark ('X' or 'O') at the specified coordinates (x, y) on the table. If the cell is already occupied, it prompts the player to choose another location.

4. ValidateWhoWon(char table[SIZE][SIZE])

    Checks the table to determine if there is a winner:
        Verifies all rows, columns, and diagonals for three consecutive identical marks.
        If a winner is found, it returns the winning player's mark ('X' or 'O').
        If the board is full and no one has won, it returns 'D' (for draw).
        If the game is ongoing, it returns 'F' (for "further play").

How to Run

    Compile the program using a C compiler (such as gcc):

    bash

gcc -o tictactoe tictactoe.c

Run the program:

bash

    ./tictactoe

    Enter the number of rounds you want to play when prompted.

    For each round, input the row and column coordinates (both between 0 and 2) where you want to place your mark (e.g., 0 0 for the top-left corner).

    The game will display the board after each move, and declare the winner or if it's a draw.

Example Input/Output

sql

How many rounds you wanna play?
2

Where would Player X like to place their letter?
   |   |  
---+---+---
   |   |  
---+---+---
   |   |  
0 0

Where would Player O like to place their letter?
 X |   |  
---+---+---
  |   |  
---+---+---
  |   |  
1 1

Where would Player X like to place their letter?
 X |   |  
---+---+---
  | O |  
---+---+---
  |   |  
...
X is the winner
Press any key to play again or exit

Requirements

    A C compiler (like GCC or Clang)
    The program is designed to work on Windows, where system("cls") is used to clear the console. If you're using Linux or macOS, replace system("cls") with system("clear").

Future Improvements

    Support for Linux/macOS by handling terminal clearing commands cross-platform.
    Add user input validation to ensure that coordinates are within the 3x3 range.
    Add a scoring system to track wins across multiple rounds.
