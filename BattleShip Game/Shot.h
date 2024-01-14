#ifndef SHOT_H_
#define SHOT_H_

#include "GridPosition.h"

/**
 * @enum Impact
 * @brief Represents the impact of a shot on a ship.
 * Defines three possible impacts: NONE, HIT, and SUNKEN.
 */
enum Impact {
    NONE,    ///< Neither ship is hit nor sunk.
    HIT,     ///< Ship is hit.
    SUNKEN   ///< Ship is sunk.
};

/**
 * @class Shot
 * @brief Represents a shot made on the game grid at a specific position.
 */
class Shot {
private:
    GridPosition m_targetPosition; ///< Represents the target position of the shot.

public:
    /**
     * @brief Constructor to create a Shot object with a target position.
     * @param targetPosition The target position of the shot.
     */
    Shot(const GridPosition& targetPosition);

    /**
     * @brief Checks if the Shot object is valid.
     * @return True if the shot's target position is valid, false otherwise.
     */
    bool isValid();

    /**
     * @brief Gets the target position of the shot.
     * @return The target position of the shot.
     */
    GridPosition getTargetPosition() const;

    /**
     * @brief Virtual destructor for the Shot class.
     */
    virtual ~Shot();
};

#endif /* SHOT_H_ */
