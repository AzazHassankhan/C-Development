#include "Board.h"

Board::Board(char row, int column):
    m_ownGrid(row, column), m_opponentGrid(row, column) {
    // Constructor initializing the Board with OwnGrid and OpponentGrid based on specified dimensions.
    m_row = row;
    m_column = column;
	if (isValid())
	{

	}
	else
	{
		exit(1);	// Exits if grid size is invalid
	}
}

OwnGrid& Board::getOwnGrid() {
    // Returns a reference to the player's OwnGrid.
    return m_ownGrid;
}

// Checks if the board object represents a dimention position.
bool Board::isValid()
{
	return (m_column > 0 && m_row >= 'A' && m_row <= 'Z');
}

OpponentGrid& Board::getOpponentGrid() {
    // Returns a reference to the opponent's OpponentGrid.
    return m_opponentGrid;
}

char Board::getRows() {
    // Retrieves the number of rows in the board.
    return m_row;
}

int Board::getColumns() {
    // Retrieves the number of columns in the board.
    return m_column;
}

Board::~Board() {
    // Destructor for the Board class.
    // (Note: No explicit implementation currently.)
}
