/*
 *ConsoleView.cpp
 *
 *Created on: Dec 26, 2023
 *     Author: Azaz
 */
#include "ConsoleView.h"

// Constructor taking a Board pointer
ConsoleView::ConsoleView(Board *board)
{
	m_board = board;	// Assigning the board pointer to a member variable
}

// Function to print the game board to the console
void ConsoleView::print()
{
	/*------------------------Own Grid---------------------------------------*/

	// Printing the header for the own grid
	cout << "-----------Own Grid-----------" << endl;
	cout << "   ";

	// Printing column numbers for the own grid
	for (int column = 1; column <= (m_board->getColumns()); column++)
	{
		cout << column << "  ";
	}

	cout << endl;

	// Printing the own grid content row-wise
	for (char row = 'A'; row <= (m_board->getRows()); row++)
	{
		cout << row << "  ";

		// Printing each cell of the own grid
		for (int column = 1; column <= (m_board->getColumns()); column++)
		{
			cout << m_board->getOwnGrid().GetOwnGrid(row, column) << "  ";
		}

		cout << endl;
		cout << endl;	// Extra space between rows for readability
	}

	cout << endl;

	/*------------------------Opponent Grid----------------------------------*/

	// Printing the header for the opponent grid
	cout << "-----Opponent Grid-----" << endl;
	cout << "   ";

	// Printing column numbers for the opponent grid
	for (int column = 1; column <= (m_board->getColumns()); column++)
	{
		cout << column << "  ";
	}

	cout << endl;

	// Printing the opponent grid content row-wise
	for (char row = 'A'; row <= (m_board->getRows()); row++)
	{
		cout << row << "  ";

		// Printing each cell of the opponent grid
		for (int column = 1; column <= (m_board->getColumns()); column++)
		{
			cout << m_board->getOpponentGrid().GetOwnGrid(row, column) << "  ";
		}

		cout << endl;
		cout << endl;	// Extra space between rows for readability
	}
}

// Destructor
ConsoleView::~ConsoleView()
{
	// TODO: Clean up resources if needed
}
