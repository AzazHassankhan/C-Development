/**
 *@file ReversiBoard.h
 *
 *@brief Declaration of the ReversiBoard class, which represents the state of a Reversi board.
 *
 *@author Azaz
 *@date November 3, 2023
 */

#ifndef REVERSIBOARD_H_
#define REVERSIBOARD_H_
#define DEFAULT_SIZE 4

/**
 *@enum STATE
 *@brief Enumeration representing the state of the board.
 */
enum STATE
{
	EMPTY,	///< Represents an empty field.
	PLAYER1,	///< Represents a field occupied by Player 1.
	PLAYER2	///< Represents a field occupied by Player 2.
};

/**
 *@class ReversiBoard
 *@brief Class representing the state of a Reversi board.
 */
class ReversiBoard
{
private:
	STATE **m_state;	///< 2D array to store the state of the board.
	int m_size;	///< The size of the Reversi board.

	/**
	 *@brief Helper function to flip markers and update the board.
	 *
	 *@param row Row of the piece being placed.
	 *@param column Column of the piece being placed.
	 *@param rowLast Row of the last piece placed.
	 *@param columnLast Column of the last piece placed.
	 *@param player The player whose piece is being placed.
	 */
	void Flip(int row, int column, int rowLast, int columnLast, int dx, int dy, STATE player);

	/**
	 *@brief Function to change players if the move is valid
	 *
	 *@param row Row of the piece being placed.
	 *@param column Column of the piece being placed.
	 *@param player The player whose piece is being placed.
	 */
	STATE PlayerSwitch(int row, int column, STATE player);

public:
	/**
	 *@brief Constructor for the ReversiBoard class.
	 *
	 *@param size Size of the Reversi board (default is 8x8).
	 */
	ReversiBoard(int size = DEFAULT_SIZE);

	/**
	 *@brief Sets the state of a specific field on the board.
	 *
	 *@param row Row of the field.
	 *@param column Column of the field.
	 *@param player The player's state to set in the field.
	 */
	STATE SetBoard(int row, int column, STATE player);

	/**
	 *@brief Gets the state of a specific field on the board.
	 *
	 *@param row Row of the field.
	 *@param column Column of the field.
	 *@return The state of the field (EMPTY, PLAYER1, or PLAYER2).
	 */
	STATE GetBoard(int row, int column);

	/**
	 *@brief Gets size of the board.
	 *
	 *@return size of the board.
	 */
	int Getsize();

	/**
	 *@brief Checks empty postion and counter the marker of each player.
	 *
	 *@return Game is finished or not.
	 */
	void CheckEmptyPos();

	/**
	 *@brief Destructor for the ReversiBoard class.
	 */
	virtual~ReversiBoard();
};


#endif /*REVERSIBOARD_H_ */
