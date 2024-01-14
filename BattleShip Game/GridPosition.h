/*
 * GridPosition.h
 *
 *  Created on: Dec 24, 2023
 *      Author: Azaz
 */

#ifndef GRIDPOSITION_H_
#define GRIDPOSITION_H_

#include <iostream>
using namespace std;

/**
 * @brief Represents a grid position with a row and column on the board.
 */
class GridPosition {
private:
    char m_row;         ///< Represents the row of the grid position.
    int m_column;       ///< Represents the column of the grid position.

public:
    /**
     * @brief Constructor that initializes the GridPosition with specified row
     and column.
     * @param row The row of the grid position ('A' to 'Z').
     * @param column The column of the grid position (must be greater than 0).
     */
    GridPosition(char row='J', int column=10);

    /**
     * @brief Constructor that initializes the GridPosition from a string
     representation.
     * @param position A string representation of the grid position (e.g., "B10").
     */
    GridPosition(string position="J10");

    /**
     * @brief Checks if the grid position is valid.
     * @return True if the grid position is valid, otherwise false.
     */
    bool isValid();

    /**
     * @brief Retrieves the row of the grid position.
     * @return The row of the grid position.
     */
    char getRow() const;

    /**
     * @brief Retrieves the column of the grid position.
     * @return The column of the grid position.
     */
    int getColumn() const;

    /**
     * @brief Overloaded cast to string operator.
     * @return A string concatenation of row and column (e.g., "B10").
     */
    operator string();

    /**
     * @brief Overloaded equality operator.
     * @param other Another GridPosition to compare with.
     * @return True if both positions are equal, otherwise false.
     */
    bool operator ==(const GridPosition& other)const ;

    /**
     * @brief Overloaded less than operator.
     * @param other Another GridPosition to compare with.
     * @return True if this position is less than the other, otherwise false.
     *
     * This operator assumes ordering from top left to bottom right
     (e.g., A1 ... Z10).
     */
    bool operator <(const GridPosition& other)const ;

    /**
     * @brief Destructor for the GridPosition class.
     */
    ~GridPosition();
};

#endif /* GRIDPOSITION_H_ */
