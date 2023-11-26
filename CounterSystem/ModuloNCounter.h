#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

/**
 * @enum Print_Value
 * An enumeration to specify what to print: Counter_Name or Current_Value.
 */
enum Print_Value {
    Counter_Name, ///< Specifies to print the counter's name.
    Current_Value, ///< Specifies to print the counter's current value.
};

/**
 * @class ModuloNCounter
 * @brief A class for representing a Single-Digit Counter.
 */
class ModuloNCounter {

private:
    int m_Countmax; ///< Maximum value of the counter.
    int m_CurrentCount; ///< Current count value.

public:
    /**
     * @brief Constructor for ModuloNCounter.
     *
     * Initializes the counter with the maximum value.
     *
     * @param Max_Value The maximum value for the counter.
     */
    ModuloNCounter(int Max_Value = 1);

    /**
     * @brief Increase the current count value of the counter by 1 or reset it
       to 0 in case of overflow.
     *
     * @return 1 if an overflow occurred, otherwise 0.
     */
    int count();

    /**
     * @brief Set the maximum value for the counter.
     *
     * @param Max_Value The maximum value for the counter.
     */
    void ModuloNCounter_Set(int Max_Value);

    /**
     * @brief Print the value of the counter.
     *
     * @param value Specifies what to print: Counter_Name or Current_Value.
     */
    void printCounter(Print_Value value) const;

    /**
     * @brief Set the current count value.
     *
     * @param value The value to set as the current count.
     */
    void SetCurrentValue(int value);

    /**
     * @brief Get the current count value.
     *
     * @return The current count value.
     */
    int GetCurrentValue() const;

    /**
     * @brief Set the maximum value for the counter.
     *
     * @param value The value to set as the maximum count.
     */
    void SetMaxCount(int value);

    /**
     * @brief Get the maximum value for the counter.
     *
     * @return The maximum count value.
     */
    int GetMaxCount() const;

    /**
     * @brief Destructor for ModuloNCounter.
     */
    ~ModuloNCounter();
};

#endif /* MODULONCOUNTER_H_ */
