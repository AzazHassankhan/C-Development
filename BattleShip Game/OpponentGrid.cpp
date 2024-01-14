/*
 *OpponentGrid.cpp
 *
 *Created on: Dec 25, 2023
 *   Author: Azaz
 */
#include "OpponentGrid.h"

OpponentGrid::OpponentGrid(char row, int column)
{
	// Validates the grid size and initializes the board if valid
	m_column = column;
	m_row = row;
	if (isValid())
	{
		int m_size = m_row * m_column;
		m_state = new char *[m_size];
		for (char row = 'A'; row <= m_row; row++)
		{
			m_state[row] = new char[m_size];
		}

		// Initialize the board.
		for (char row = 'A'; row <= m_row; row++)
		{
			for (int column = 1; column <= m_column; column++)
			{
				m_state[row][column] = '.';
			}
		}
	}
	else
	{
		exit(1);	// Exits if grid size is invalid
	}
}

bool OpponentGrid::isValid()
{
	return (m_column > 0 && m_row >= 'A' && m_row <= 'Z');
}

void OpponentGrid::SetPosition(std::string position, char symbol)
{
	if (position.size() >= 2)
	{
		char row = position[0];
		int column = std::stoi(position.substr(1));
		m_state[row][column] = symbol;	// Sets symbol at a position on the grid
	}
}

int OpponentGrid::getRows()
{
	return m_row;	// Returns the number of rows in the grid
}

char OpponentGrid::GetOwnGrid(char row, int column)
{
	return m_state[row][column];	// Retrieves content of a cell in the grid
}

int OpponentGrid::getColumns()
{
	return m_column;	// Returns the number of columns in the grid
}

// Updates the grid based on shot result and impact
void OpponentGrid::shotResult(const Shot &shot, Impact impact)
{
	if (shot.getTargetPosition().getRow() <= m_row &&
		shot.getTargetPosition().getColumn() <= m_column)
	{
		if (impact == SUNKEN)
		{
			UpdateSunkenShips(shot, impact);	// Updates for a sunken ship
		}
		else if (impact == HIT)
		{
			SetPosition(shot.getTargetPosition(), 'O');	// Sets 'O' for a hit
		}
		else
		{
			SetPosition(shot.getTargetPosition(), '^');	// Sets '^' for a miss
		}

		m_shots[shot.getTargetPosition()] = impact;	// Records shot position &impact
	}
}

const std::map<GridPosition, Impact> &OpponentGrid::getShotsAt()
{
	return m_shots;	// Retrieves the map of shots fired and their impacts
}

void OpponentGrid::UpdateSunkenShips(const Shot &shot, Impact impact)
{
	std::set<GridPosition> ShipPosition;	// Holds positions of a sunken ship

	char row = (shot.getTargetPosition()).getRow();
	int column = (shot.getTargetPosition()).getColumn();

	/* Check whether there is already HITTED Ship on left or not*/
	for (int i = column - 1; i >= 1; i--)	//decrement the column to move left
	{
		GridPosition leftPos(row, i);
		/*find whether there is leftPos in m_shots*/
		auto it = m_shots.find(leftPos);
		if (it != m_shots.end() && it->second == HIT)
		{
			ShipPosition.insert(leftPos);
			ShipPosition.insert(shot.getTargetPosition());
		}
		else
		{
			break;
		}
	}

	/* Check whether there is already HITTED Ship on right or not*/
	for (int i = column + 1; i <= m_column; i++) //Increment column to move right
	{
		GridPosition RightPos(row, i);
		auto it = m_shots.find(RightPos);
		if (it != m_shots.end() && it->second == HIT)
		{
			ShipPosition.insert(RightPos);
			ShipPosition.insert(shot.getTargetPosition());
		}
		else
		{
			break;
		}
	}

	/* Check whether there is already HITTED Ship on Upside or not*/
	for (char i = row - 1; i >= 'A'; i--)	//Decrement row to move Up
	{
		GridPosition UpPos(i, column);
		auto it = m_shots.find(UpPos);
		if (it != m_shots.end() && it->second == HIT)
		{
			ShipPosition.insert(UpPos);
			ShipPosition.insert(shot.getTargetPosition());
		}
		else
		{
			break;
		}
	}

	/* Check whether there is already HITTED Ship on Downside or not*/
	for (char i = row + 1; i <= m_row; i++)	//Increment row to move Down
	{
		GridPosition DownPos(i, column);
		auto it = m_shots.find(DownPos);
		if (it != m_shots.end() && it->second == HIT)
		{
			ShipPosition.insert(DownPos);
			ShipPosition.insert(shot.getTargetPosition());
		}
		else
		{
			break;
		}
	}

	if (ShipPosition.size()>1)
	{	auto Bow = *(ShipPosition.begin());	    // Retrieves Bow position
		auto Stern = *(--ShipPosition.end());	// Retrieves Stern position

		sunkenShips.push_back(Ship{Bow, Stern });// Adds the sunken ship to the list
		for (auto value: ShipPosition)
		{
			SetPosition(value, 'X');	//sunken ship positions as 'X' on the grid
		}
	}
}

const vector<Ship> OpponentGrid::getSunkenShips()
{
	return sunkenShips;
}

OpponentGrid::~OpponentGrid()
{
	delete[] m_state;
}


