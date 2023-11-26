/**
 * MDCounter.cpp
 *
 * Created on: Oct 30, 2023
 * Author: Azaz
 */

#include "MDCounter.h"

#include <iostream>
using namespace std;

// Constructor for the MDCounter class
MDCounter::MDCounter(int Digits, int Max_value)
{
    // Determine the type of counter based on Max_value
    if (Max_value == 2)
    {
        cout << Digits << " digit binary counter" << endl;
    }
    else if (Max_value == 8)
    {
        cout << Digits << " digit octal counter" << endl;
    }
    else if (Max_value == 10)
    {
        cout << Digits << " digit decimal counter" << endl;
    }
    else if (Max_value == 16)
    {
        cout << Digits << " digit hexadecimal counter" << endl;
    }

    // Check if the provided parameters are valid
    if ((Digits > 0) && (Max_value == 2 || Max_value == 8 || Max_value == 10 ||
    		Max_value == 16))
    {
        numDigits = Digits;
        counter = new ModuloNCounter[Digits];
        for (int i = 0; i < Digits; i++)
        {
            counter[i].ModuloNCounter_Set(Max_value);
        }
    }
    else
    {
        cout << "Invalid Value!!! End of Test" << endl;
        exit(0);
    }
}

// Function to increment the multi-digit counter
void MDCounter::countMultipleDigit()
{
    int carry = 1;

    for (int i = numDigits - 1; i >= 0; i--)
    {
        counter[i].SetCurrentValue(counter[i].GetCurrentValue() + carry);
        carry = counter[i].GetCurrentValue() / counter[i].GetMaxCount();
        counter[i].SetCurrentValue(counter[i].GetCurrentValue() %
        		counter[i].GetMaxCount());
    }
}

// Function to print the current value of the multi-digit counter
void MDCounter::printMultiDigitCounter() const
{
    for (int i = 0; i < numDigits; i++)
    {
        if (counter[i].GetMaxCount() == 16) // If max value is hexadecimal
        {
            if (counter[i].GetCurrentValue() < 10)
            {
                cout << counter[i].GetCurrentValue();
            }
            else
            {
            	cout << static_cast<char>('A' + counter[i].GetCurrentValue()
            			- 10);
            }
        }
        else // If max value is not hexadecimal
        {
            cout << counter[i].GetCurrentValue();
        }
    }

    cout << endl;
}

// Overloaded pre-increment operator
void MDCounter::operator++()
{
	countMultipleDigit();
}

// Overloaded post-increment operator
void MDCounter::operator++(int)
{
	countMultipleDigit();
}

// Destructor for the MDCounter class
MDCounter::~MDCounter()
{
    delete[] counter;
}
