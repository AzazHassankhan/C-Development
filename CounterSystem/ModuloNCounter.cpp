#include <iostream>
using namespace std;
#include "ModuloNCounter.h"

// Constructor for ModuloNCounter.
ModuloNCounter::ModuloNCounter(int Max_Value)
{
    // Check if Max_Value is greater than 0
    if (Max_Value > 0)
    {
        m_Countmax = Max_Value;
        m_CurrentCount = 0;
    }
    else
    {
        // Display an error message and exit if Max_Value is not valid
        cout << "Invalid Value!!! End of Test" << endl;
        exit(0);
    }
}

// Set the ModuloNCounter parameters.
void ModuloNCounter::ModuloNCounter_Set(int Max_Value)
{
    // Check if Max_Value is greater than 0
    if (Max_Value > 0)
    {
        m_Countmax = Max_Value;
        m_CurrentCount = 0;
    }
    else
    {
        // Display an error message and set Max_Value to 1 if it's not valid
        cout << "Invalid Max Value!!! Max Value is set to 1" << endl;
        m_Countmax = 1;
        m_CurrentCount = 0;
    }
}

// Increment the counter and reset if it overflows.
int ModuloNCounter::count()
{
    // Check for overflow
    if (m_CurrentCount < (m_Countmax) - 1)
    {
        m_CurrentCount += 1;
        return 0; // No overflow
    }
    else
    {
        m_CurrentCount = 0;
        return 1; // Overflow occurred
    }
}

/**
 * @brief Print the counter's name or its current value.
 * @param value Specifies what to print: Counter_Name or Current_Value.
 */
void ModuloNCounter::printCounter(Print_Value value) const
{
    if (value == Counter_Name)
    {
        cout << "Modulo " << m_Countmax << " Counter" << endl;
    }
    else if (value == Current_Value)
    {
        cout << "Counter Current Value " << m_CurrentCount << endl;
    }
}

// Set the current value of the counter.
void ModuloNCounter::SetCurrentValue(int value)
{
    m_CurrentCount = value;
}

// Get the current value of the counter.
int ModuloNCounter::GetCurrentValue() const
{
    return m_CurrentCount;
}

// Set the maximum count value for the counter.
void ModuloNCounter::SetMaxCount(int value)
{
    m_Countmax = value;
}

// Get the maximum count value for the counter.
int ModuloNCounter::GetMaxCount() const
{
    return m_Countmax;
}

// Destructor for ModuloNCounter.
ModuloNCounter::~ModuloNCounter()
{
    cout << "Destroyed Object at " << this << endl;
}
