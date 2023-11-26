//============================================================================
// Name        : Source_Code.cpp
// Author      : Azaz Hassan Khan
// Version     : 1.0
// Description : This program demonstrates the use of the MDCounter class
//============================================================================

#include <iostream>
using namespace std;
#include "MDCounter.h"
#include "math.h"

int main(void)
{
    int Digits, Max_value;

    // Prompt the user to enter parameters for the counter
    cout << "Please enter the parameters of your counter" << endl;

    // Input the number of digits
    cout << "Number of digits:" << endl;
    cin >> Digits;

    // Input the type (2/8/10/16)
    cout << "Type (2/8/10/16):" << endl;
    cin >> Max_value;

    // Create an instance of the MDCounter class
    MDCounter c1(Digits, Max_value);

    // Loop to count and print the counter's values
    for (int i = 0; i < pow(Max_value, Digits) + 1; i++)
    {
        // Print the current value of the multi-digit counter
        c1.printMultiDigitCounter();

        // Increment the counter
        c1.countMultipleDigit();
    }

    return 0;
}
