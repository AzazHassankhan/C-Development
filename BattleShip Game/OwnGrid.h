#ifndef OWNGRID_H_
#define OWNGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <algorithm>
#include <set>
#include <vector>
#include <map>

/**
 *@class OwnGrid
 *@brief Represents the grid of the player's own ships.
 */
class OwnGrid
{
private:
	int m_column;	///< Number of columns in the grid.
	char m_row;	    ///< Number of rows in the grid.
	char **m_state;	///< 2D array to store the state of the board.

	map<int, int> m_typeships = { // @suppress("Invalid arguments")
		{ 5, 1 },
		{ 4, 2 },
		{ 3, 3 },
		{ 2, 4 }
	}; 	///< Map of ship types with available count.

	set<GridPosition> m_Positionsblocked;	///< Set of positions blocked
	set<GridPosition> m_PositionsOccupied;	///< Set of positions occupied ships
	set<GridPosition> m_shotAt;	///< Set of positions where shots have been fired.
	vector<Ship> m_ships;	///< Vector containing placed ships.

public:
		/**
		 *@brief Constructor to initialize OwnGrid with specified dimensions.
		 *@param row The number of rows in the grid.
		 *@param column The number of columns in the grid.
		 */
		OwnGrid(char row = 'J', int column = 10);

	/**
	 *@brief Checks if the grid is valid based on its dimensions.
	 *@return True if the grid is valid, false otherwise.
	 */
	bool isValid();

	/**
	 *@brief Gets the number of rows in the grid.
	 *@return The number of rows in the grid.
	 */
	char getRows();

	/**
	 *@brief Gets the number of columns in the grid.
	 *@return The number of columns in the grid.
	 */
	int getColumns();

	/**
	 *@brief Places a ship on the grid if valid, updating positions and ship lists.
	 *@param ship The Ship object to be placed on the grid.
	 *@return True if the ship was successfully placed, false otherwise.
	 */
	bool placeShip(const Ship &ship);

	/**
	 *@brief Retrieves the symbol at a specific position on the grid.
	 *@param row The row of the position.
	 *@param column The column of the position.
	 *@return The symbol at the specified position on the grid.
	 */
	char GetOwnGrid(char row, int column);

	/**
	 *@brief Processes a shot taken on the grid and updates the grid status.
	 *@param shot The Shot object representing the shot taken.
	 *@return The impact of the shot on the grid.
	 */
	Impact takeBlow(const Shot &shot);

	/**
	 *@brief Retrieves the set of positions where shots have been taken on the grid.
	 *@return Set of GridPositions where shots have been fired.
	 */
	const set<GridPosition> getShotAt();

	/**
	 *@brief Checks the availability of a ship type based on its length.
	 *@param length The length of the ship.
	 *@return True if the ship of the specified length is available, false otherwise.
	 */
	bool getTypeShips(int length);

	/**
	 *@brief Retrieves the vector containing all ships placed on the grid.
	 *@return Vector of Ship objects placed on the grid.
	 */
	const vector<Ship> getShips();

	/**
	 *@brief Sets a position on the grid with a specified symbol.
	 *@param position The position on the grid.
	 *@param symbol The symbol to set at the position.
	 */
	void SetPosition(string position, char symbol);

	/**
	 *@brief Virtual destructor for the OwnGrid class.
	 */
	virtual~OwnGrid();
};


#endif /*OWNGRID_H_ */
