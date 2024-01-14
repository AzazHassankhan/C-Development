/*
 * Shot.cpp
 *
 * Created on: Dec 29, 2023
 * Author: Azaz
 */

#include "Shot.h"

/**
 * @brief Constructor to create a Shot object with a target position.
 * @param targetPosition The target position of the shot.
 */
Shot::Shot(const GridPosition& targetPosition):
    m_targetPosition(targetPosition) {
}

/**
 * @brief Checks if the Shot object is valid.
 * @return True if the shot's target position is within valid grid coordinates,
   false otherwise.
 */
bool Shot::isValid() {
    return (m_targetPosition.getColumn() > 0 && m_targetPosition.getRow() >= 'A'
    		&& m_targetPosition.getRow() <= 'Z');
}

/**
 * @brief Gets the target position of the shot.
 * @return The target position of the shot.
 */
GridPosition Shot::getTargetPosition() const {
    return m_targetPosition;
}

/**
 * @brief Virtual destructor for the Shot class.
 * Currently empty as no specific cleanup operations are required.
 */
Shot::~Shot() {
    // TODO: Clean up resources if needed
}
