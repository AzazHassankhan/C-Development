#ifndef SHIP_H_
#define SHIP_H_

#include "GridPosition.h"
#include <set>

/**
 * @class Ship
 * @brief Represents a ship on a grid using GridPosition objects for the bow and
 * stern positions.
 */
class Ship {
private:
    GridPosition m_bow;    ///< GridPosition representing the back of the ship.
    GridPosition m_stern;  ///< GridPosition representing the front of the ship.

public:
    /**
     * @brief Constructor to initialize the Ship object with default bow
     * and stern positions.
     * @param bow The GridPosition of the ship's back (default: {"B2"}).
     * @param stern The GridPosition of the ship's front (default: {"D2"}).
     */
    Ship(const GridPosition& bow = {"B2"}, const GridPosition& stern = {"D2"});

    /**
     * @brief Checks if the Ship object is valid.
     * @return True if the Ship is valid (length > 0), false otherwise.
     */
    bool isValid();

    /**
     * @brief Gets the GridPosition of the ship's back.
     * @return The GridPosition of the ship's back.
     */
    GridPosition getBow() const;

    /**
     * @brief Gets the row of the ship's back position.
     * @return The row of the ship's back.
     */
    char getBowRow() const;

    /**
     * @brief Gets the column of the ship's back position.
     * @return The column of the ship's back.
     */
    int getBowColumn() const;

    /**
     * @brief Gets the GridPosition of the ship's front.
     * @return The GridPosition of the ship's front.
     */
    GridPosition getStern() const;

    /**
     * @brief Gets the row of the ship's front position.
     * @return The row of the ship's front.
     */
    char getSternRow() const;

    /**
     * @brief Gets the column of the ship's front position.
     * @return The column of the ship's front.
     */
    int getSternColumn() const;

    /**
     * @brief Calculates and returns the length of the Ship.
     * @return The length of the Ship.
     */
    int length() const;

    /**
     * @brief Retrieves the set of positions occupied by the Ship.
     * @return The set of occupied GridPositions.
     */
    const std::set<GridPosition> occupiedArea() const;

    /**
     * @brief Retrieves the set of blocked positions of the Ship.
     * @return The set of blocked GridPositions due to ship's placement.
     */
    const std::set<GridPosition> blockedArea() const;

    /**
     * @brief Virtual destructor for the Ship class.
     */
    virtual ~Ship();
};

#endif /* SHIP_H_ */
