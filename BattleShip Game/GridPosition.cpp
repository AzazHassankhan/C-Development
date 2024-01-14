#include "GridPosition.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor initializing GridPosition with row and column values.
GridPosition::GridPosition(char row, int column) {
    m_row = row;
    m_column = column;
}

// Constructor initializing GridPosition with a string position.
// Expects at least 2 characters in the format 'RowColumn'.
GridPosition::GridPosition(string position) {
    if (position.size() >= 2) {
        m_row = position[0];
        m_column = std::stoi(position.substr(1));
    } else {
        cout << "Invalid Arguments passed!!! Program Exit" << endl;
        exit(1);
    }
}

// Checks if the GridPosition object represents a valid position on the grid.
bool GridPosition::isValid() {
    return (m_column > 0 && m_row >= 'A' && m_row <= 'Z');
}

// Gets the row character of the GridPosition.
char GridPosition::getRow() const {
    return m_row;
}

// Gets the column integer of the GridPosition.
int GridPosition::getColumn() const {
    return m_column;
}

// Conversion operator to convert GridPosition to a string representation.
 GridPosition::operator string() {
    return m_row + to_string(m_column);
}

// Checks if two GridPosition objects are equal.
bool GridPosition::operator==(const GridPosition &other) const {
    return (m_row == other.m_row && m_column == other.m_column);
}

// Compares two GridPosition objects for less-than relation.
bool GridPosition::operator<(const GridPosition &other) const {
    if (m_row != other.m_row) {
        return m_row < other.m_row;
    } else {
        // If rows are equal, compare columns
        return m_column < other.m_column;
    }
}

// Destructor for the GridPosition class.
GridPosition::~GridPosition() {
    // No specific cleanup operations required.
}
