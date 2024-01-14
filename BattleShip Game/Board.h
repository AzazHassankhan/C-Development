#ifndef BOARD_H_
#define BOARD_H_

#include "OpponentGrid.h"
#include "OwnGrid.h"

/**
 * @class Board
 * @brief Represents the game board containing the player's own grid and the opponent's grid.
 */
class Board {
private:
    OwnGrid m_ownGrid; ///< Player's own grid.
    OpponentGrid m_opponentGrid; ///< Opponent's grid.

    int m_column; ///< Number of columns in the board.
    char m_row; ///< Number of rows in the board.

public:
    /**
     * @brief Constructor to initialize the Board with specified dimensions.
     * @param row The number of rows in the board.
     * @param column The number of columns in the board.
     */
    Board(char row = 'J', int column = 10);

    /**
     * @brief Checks if the given position is valid within the grid.
     * @param column Column index.
     * @param row Row index.
     * @return True if the position is valid, False otherwise.
     */
    bool isValid();

    /**
     * @brief Gets the number of rows in the board.
     * @return The number of rows in the board.
     */
    char getRows();

    /**
     * @brief Gets the number of columns in the board.
     * @return The number of columns in the board.
     */
    int getColumns();

    /**
     * @brief Retrieves the reference to the player's own grid.
     * @return Reference to the OwnGrid object representing the player's grid.
     */
    OwnGrid& getOwnGrid();

    /**
     * @brief Retrieves the reference to the opponent's grid.
     * @return Reference to the OpponentGrid object representing the opponent's grid.
     */
    OpponentGrid& getOpponentGrid();

    /**
     * @brief Virtual destructor for the Board class.
     */
    virtual ~Board();
};

#endif /* BOARD_H_ */
