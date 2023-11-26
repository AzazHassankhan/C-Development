/**
 * @file ReversiConsoleView.h
 *
 * @brief Declaration of the ReversiConsoleView class for printing the Reversi board on the console.
 *
 * This file contains the declaration of the ReversiConsoleView class, which is responsible for
 * printing the current state of the Reversi board on the console.
 *
 * @author Azaz
 * @date November 4, 2023
 */

#ifndef REVERSICONSOLEVIEW_H_
#define REVERSICONSOLEVIEW_H_
#include "ReversiBoard.h"

/**
 * @class ReversiConsoleView
 * @brief Class for printing the Reversi board on the console.
 *
 * The ReversiConsoleView class allows printing the current state of the Reversi board on the console.
 * It receives a pointer to a ReversiBoard instance and provides a method to display the board.
 */
class ReversiConsoleView {
private:
    ReversiBoard* m_board; ///< Pointer to the Reversi board.

public:
    /**
     * @brief Constructor for the ReversiConsoleView class.
     *
     * @param board Pointer to an instance of ReversiBoard.
     */
    ReversiConsoleView(ReversiBoard* board);

    /**
     * @brief Prints the current state of the Reversi board on the console.
     *
     * This method iterates through the Reversi board and prints the current state of each field on the console.
     * It uses 'X' for PLAYER1, 'O' for PLAYER2, and a space for an EMPTY field. Rows are separated by newline characters.
     */
    void PrintBoard(STATE player);

    /**
     * @brief Destructor for the ReversiConsoleView class.
     */
    virtual ~ReversiConsoleView();
};

#endif /* REVERSICONSOLEVIEW_H_ */
