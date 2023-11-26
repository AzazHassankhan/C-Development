/*
 * MDCounter.h
 *
 * Created on: Oct 30, 2023
 * Author: Azaz
 */

#ifndef MDCOUNTER_H_
#define MDCOUNTER_H_
#include "ModuloNCounter.h"

/**
 * @class MDCounter
 * @brief A class for representing a Multi-Digit Counter.
 */
class MDCounter {

private:
    ModuloNCounter *counter; ///< A pointer to a ModuloNCounter object.
    int numDigits; ///< The number of digits in the multi-digit counter.

public:
    /**
     * @brief Constructor for MDCounter.
     * @param Digits The number of digits in the counter (default is 1).
     * @param Max_value The maximum value for each digit (default is 2).
     */
    MDCounter(int Digits = 1, int Max_value = 2);

    /**
     * @brief Increment the value of the multi-digit counter.
     */
    void countMultipleDigit();

    /**
     * @brief Print the value of the multi-digit counter.
     */
    void printMultiDigitCounter() const;

    /**
     * @brief Overload the postfix increment operator (++).
     * This operator increments the counter value.
     * @param Dummy A dummy integer to differentiate between postfix and prefix
       operators.
     */
    void operator++(int);

    /**
     * @brief Overload the prefix increment operator (++).
     * This operator increments the counter value.
     */
    void operator++();

    /**
     * @brief Destructor for MDCounter.
     */
    ~MDCounter();
};

#endif /* MDCOUNTER_H_ */
