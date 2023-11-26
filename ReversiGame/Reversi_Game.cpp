//============================================================================
// Name        : Reversi_Game.cpp
// Author      : Azaz Hassan Khan
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Reversi Game in C++, Ansi-style
//============================================================================
#include <iostream>
using namespace std;
#include "ReversiBoard.h"
#include "ReversiConsoleView.h"

int main()
{
    int row, column;

    // Create a ReversiBoard object with a size of 4x4.
    ReversiBoard c1(4);

    // Create a ReversiConsoleView object and pass the ReversiBoard object to it.
    ReversiConsoleView c2(&c1);

    // Initialize the player to start with PLAYER1.
    STATE player = PLAYER1;

    // Print the initial game board.
    c2.PrintBoard(player);

    while (1)
    {
        cout << "Enter position of row:" << endl;
        cin  >> row;
        cout << "Enter position of column:" << endl;
        cin  >> column;

        // Update the player's turn and set the board.
        player = c1.SetBoard(row, column, player);

        // Print the updated game board.
        c2.PrintBoard(player);
    }

    return 0;
}
