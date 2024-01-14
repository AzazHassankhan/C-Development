#ifndef CONSOLEVIEW_H_
#define CONSOLEVIEW_H_

#include "Board.h"

/**
 * @class ConsoleView
 * @brief Handles printing the Reversi game board to the console.
 */
class ConsoleView {
private:
    Board *m_board; ///< Pointer to the Reversi board.

public:
    /**
     * @brief Constructor for ConsoleView.
     * @param board Pointer to the Reversi board.
     */
    ConsoleView(Board *board);

    /**
     * @brief Prints the Reversi game board to the console.
     * Iterates through the board's own and opponent grids, displaying their
     *  content.
     */
    void print();

    /**
     * @brief Virtual destructor for ConsoleView.
     * Cleans up resources and deallocates memory.
     */
    virtual ~ConsoleView();
};

#endif /* CONSOLEVIEW_H_ */
