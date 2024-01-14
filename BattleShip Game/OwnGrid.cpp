/*
 *OwnGrid.cpp
 *
 *Created on: Dec 25, 2023
 *Author: Azaz
 */
#include "OwnGrid.h"

// Constructor initializing OwnGrid with row and column values.
OwnGrid::OwnGrid(char row, int column)
{
	m_column = column;
	m_row = row;
	// Validates the grid size and initializes the board if valid
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

// Checks if the OwnGrid object represents a valid grid position.
bool OwnGrid::isValid()
{
	return (m_column > 0 && m_row >= 'A' && m_row <= 'Z');
}

// Gets the number of rows in the grid.
char OwnGrid::getRows()
{
	return m_row;
}

// Gets the number of columns in the grid.
int OwnGrid::getColumns()
{
	return m_column;
}

// Places a ship on the OwnGrid.
bool OwnGrid::placeShip(const Ship &ship)
{
	/*check whether the ship is of valid length and valid range*/
	if (ship.getBowRow() <= m_row && ship.getBowColumn() <= m_column &&
		ship.getSternRow() <= m_row && ship.getSternColumn() <= m_column &&
		getTypeShips(ship.length()))
	{
		/*check whether the occupied area of current ship intersect
		 with the already placed ship or not*/
		for (auto block: m_Positionsblocked)
		{
			for (auto ShipArea: ship.occupiedArea())
			{
				if (ShipArea == block)  //if intersect than not place ship
				{
					return 0; //ShipPlacement Unsuccessfull because intersection
				}
			}
		}
	}
	else /*Ship Placement Unsuccessfull because of invalid length or range*/
	{
		return 0;
	}

	/*store occupied area of current ship with in data member*/
	for (auto ShipArea: ship.occupiedArea())
	{
		SetPosition(ShipArea, '#');
		m_PositionsOccupied.insert(ShipArea);
	}

	/*store blocked area of current ship with in data member*/
	for (auto ShipArea: ship.blockedArea())
	{
		m_Positionsblocked.insert(ShipArea);
	}

	/*store ship range in data member*/
	m_ships.push_back(Ship{{ship.getBow()},{ship.getStern()}});

	return 1;  //ShipPlacement Successfull

}

// Sets a position on the grid with a specified symbol.
void OwnGrid::SetPosition(string position, char symbol)
{
	if (position.size() >= 2)
	{
		char row = position[0];
		int column = std::stoi(position.substr(1));
		m_state[row][column] = symbol;
	}
}

// Retrieves the symbol at a specific position on the grid.
char OwnGrid::GetOwnGrid(char row, int column)
{
	return m_state[row][column];
}

// Checks the availability of a ship type based on its length.
bool OwnGrid::getTypeShips(int length)
{
	int temp = m_typeships[length];
	if (m_typeships[length] >= 1)
	{
		temp--;
		m_typeships[length] = temp;
		return 1;
	}
	else
	{
		return 0;
	}
}

// Processes a shot taken on the OwnGrid and updates the grid status.
Impact OwnGrid::takeBlow(const Shot &shot)
{

	/*If the current Shot is in range or not Inrange */
	if (shot.getTargetPosition().getRow() <= m_row &&
		shot.getTargetPosition().getColumn() <= m_column)
	{
		/*Check whether the current shot is already present*/
		for (auto shotAt: m_shotAt)

		{
			if (shot.getTargetPosition() == shotAt) return NONE;
		}

		/*Check Current occupied positions*/
		for (auto ShipArea: m_PositionsOccupied)

		{	int CompareVariable = 0;
			/*Check if the current target hit the occupied position*/
			if (shot.getTargetPosition() == ShipArea)
			{
				SetPosition(shot.getTargetPosition(), 'O'); //set position hit

				m_shotAt.insert(shot.getTargetPosition()); //store in data membr

				/*Check if the current hit sunk any ship or not*/
				for (auto NoOfShip = m_ships.begin(); NoOfShip != m_ships.end();
					++NoOfShip)
				{
					CompareVariable = 0;  //reset the

					/*Check ship occupied area */
					for (auto Area: NoOfShip->occupiedArea())
					{
						/*Compare Ship Area with the Shots*/
						for (auto shot: m_shotAt)
						{

							if (shot == Area)
							{
								CompareVariable++;  //increment if

								/*If Ship Area is Equal to the number
								  of shots than sunk the ship*/
							if (CompareVariable == NoOfShip->occupiedArea().size())
							{

							/*Convert already HIT Symbol oF the ship to sunk*/
								for (auto sArea: NoOfShip->occupiedArea())
								{
									SetPosition(sArea, 'x');
								}

								// Remove the ship from m_ships
								m_ships.erase(NoOfShip);

								return SUNKEN;
							}
						}
					}
				}
			}

				return HIT;
			}
		}

		SetPosition(shot.getTargetPosition(), '^');
		return NONE;
	}
	return NONE;

}

// Retrieves the vector containing all ships placed on the OwnGrid.
const vector<Ship> OwnGrid::getShips()
{
	return m_ships;
}

// Retrieves the set containing positions where shots have been taken on OwnGrid.
const set<GridPosition> OwnGrid::getShotAt()
{
	return m_shotAt;
}

OwnGrid::~OwnGrid()
{
	delete[] m_state;// TODO Auto-generated destructor stub
}
