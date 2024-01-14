#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_

#include <vector>
#include "Ship.h"
#include "Shot.h"
#include "GridPosition.h"
#include <map>

/**
 * @class OpponentGrid
 * @brief Represents the opponent's grid in the game board.
 * Stores and manages the state of the opponent's grid, including shots fired and sunken ships.
 */
class OpponentGrid {
private:
    int m_column; ///< Number of columns in the grid.
    char m_row; ///< Last row letter in the grid.
    char **m_state; ///< 2D array to store the state of the board.
    std::map<GridPosition, Impact> m_shots; ///< Map storing shot positions and their impacts.
    std::vector<Ship> sunkenShips; ///< Collection of sunken ships.

public:
    /**
     * @brief Constructor for OpponentGrid.
     * @param row Last row letter in the grid (default: 'J').
     * @param column Number of columns in the grid (default: 10).
     */
    OpponentGrid(char row = 'J', int column = 10);

    /**
     * @brief Gets the number of rows in the grid.
     * @return Number of rows.
     */
    int getRows();

    /**
     * @brief Gets the number of columns in the grid.
     * @return Number of columns.
     */
    int getColumns();

    /**
     * @brief Checks if the given position is valid within the grid.
     * @param column Column index.
     * @param row Row index.
     * @return True if the position is valid, False otherwise.
     */
    bool isValid();

    /**
     * @brief Retrieves the content of the grid cell at the specified position.
     * @param row Row index.
     * @param column Column index.
     * @return Character representing the content of the cell.
     */
    char GetOwnGrid(char row, int column);

    /**
     * @brief Records the result of a shot fired and its impact on the grid.
     * @param shot The fired shot.
     * @param impact The impact of the shot.
     */
    void shotResult(const Shot& shot, Impact impact);

    /**
     * @brief Sets a position on the grid with a specific symbol.
     * @param position The position to set.
     * @param symbol The symbol to set at the position.
     */
    void SetPosition(std::string position, char symbol);

    /**
     * @brief Updates the list of sunken ships based on a shot and its impact.
     * @param shot The fired shot.
     * @param impact The impact of the shot.
     */
    void UpdateSunkenShips(const Shot& shot, Impact impact);

    /**
     * @brief Retrieves the map of shots fired at grid positions and their impacts.
     * @return Map of shots and their impacts.
     */
    const std::map<GridPosition, Impact>& getShotsAt();

	/**
	 *@brief Retrieves the vector containing all sunken ships placed on the grid.
	 *@return Vector of Ship objects placed on the grid.
	 */
    const vector<Ship> getSunkenShips();

    /**
     * @brief Virtual destructor for OpponentGrid.
     * Cleans up resources and deallocates memory.
     */
    virtual ~OpponentGrid();
};

#endif /* OPPONENTGRID_H_ */
