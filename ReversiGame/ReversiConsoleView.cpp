/*
 *ReversiConsoleView.cpp
 *
 *Created on: Nov 4, 2023
 *     Author: Azaz
 */
#include <iostream>
using namespace std;
#include "ReversiConsoleView.h"

ReversiConsoleView::ReversiConsoleView(ReversiBoard *board)
{
	m_board = board;

}

/*This Function Print the Board*/
void ReversiConsoleView::PrintBoard(STATE player)
{
	for (int row = 0; row <(m_board->Getsize()); row++)
	{
		for (int column = 0; column < (m_board->Getsize()); column++)
		{
			switch (m_board->GetBoard(row, column))
			{
				case EMPTY:
					cout << "." << "  ";
					break;
				case PLAYER1:
					cout << "X" << "  ";
					break;
				case PLAYER2:
					cout << "O" << "  ";
					break;
				default:
					//do nothing
					break;
			}
		}

		cout << endl;
		cout << endl;
	}

	cout << "Player "<<player << " Turn>>>>" << endl;
}

ReversiConsoleView::~ReversiConsoleView()
{
	// TODO Auto-generated destructor stub
}
