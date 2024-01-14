/*
 *Ship.cpp
 *
 *Created on: Dec 24, 2023
 *Author: Azaz
 */
#include <iostream>
#include <string>
#include "Ship.h"
using namespace std;

Ship::Ship(const GridPosition &bow, const GridPosition &stern):
	m_bow(bow), m_stern(stern)
	{
		isValid();
	}

bool Ship::isValid()
{
	// Validates ship placement and length based on bow and stern positions
	if (((m_bow.getRow() == m_stern.getRow()) || (m_bow.getColumn() ==
			m_stern.getColumn())) &&(length() > 2 && length() < 5))
	{
		return true;
	}
	else
	{
		return false;
	}
}

GridPosition Ship::getBow() const
{
	return m_bow;	// Retrieves the GridPosition of the ship's bow
}

GridPosition Ship::getStern() const
{
	return m_stern;	// Retrieves the GridPosition of the ship's stern
}

int Ship::length() const
{
	// Calculates and returns the length of the Ship based on its bow and stern
	if (m_bow.getRow() == m_stern.getRow())
	{
		return ((m_stern.getColumn() - m_bow.getColumn()) + 1);
	}
	else if (m_bow.getColumn() == m_stern.getColumn())
	{
		return ((m_stern.getRow() - m_bow.getRow()) + 1);
	}
	else
	{
		return 0;
	}
}

const set<GridPosition> Ship::occupiedArea() const
{
	set<GridPosition> Positionsoccupied;
	// Generates a set of positions occupied by the Ship based on its bow & stern
	if (m_bow.getRow() == m_stern.getRow())
	{
		for (int i = m_bow.getColumn(); i <= m_stern.getColumn(); i++)
		{
			Positionsoccupied.insert(m_bow.getRow() + to_string(i));
		}
	}
	else if (m_bow.getColumn() == m_stern.getColumn())
	{
		for (char i = m_bow.getRow(); i <= m_stern.getRow(); i++)
		{
			Positionsoccupied.insert(i + to_string(m_bow.getColumn()));
		}
	}

	return Positionsoccupied;
}

const set<GridPosition> Ship::blockedArea() const
{
	set<GridPosition> Positionsblocked;
	int rowOffsets[] = { -1, 0, 1, 1, -1, -1, 0, 1, 0 };

	int colOffsets[] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };

	// Generates a set of blocked positions around the Ship based occupied area
	for (auto ShipArea: occupiedArea())
	{
		for (int offset = 0; offset<= 8; offset++)
		{
			if ((ShipArea.getRow() + rowOffsets[offset]<'A') ||
				(ShipArea.getColumn() + colOffsets[offset]) < 1)
			{
				continue;
			}

			char row = ShipArea.getRow() + rowOffsets[offset];
			Positionsblocked.insert(row + to_string(ShipArea.getColumn() +
					colOffsets[offset]));
		}
	}

	return Positionsblocked;
}


char Ship::getBowRow() const
{
	return m_bow.getRow();	// Retrieves the row of the ship's bow position
}

int Ship::getBowColumn() const
{
	return m_bow.getColumn();	// Retrieves column of the ship's bow position
}

char Ship::getSternRow() const
{
	return m_stern.getRow();	// Retrieves row of the ship's stern position
}

int Ship::getSternColumn() const
{
	return m_stern.getColumn();	// Retrieves column of the ship's stern position
}

Ship::~Ship()
{
	// TODO: Clean up resources if needed
}
