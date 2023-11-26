/**
 * @file ReversiBoard.cpp
 *
 * @brief Implementation of the ReversiBoard class for the Reversi game board.
 *
 * This file contains the implementation of the ReversiBoard class, which represents the state of the Reversi game board.
 *
 * @author Azaz
 * @date November 3, 2023
 */
#include <iostream>
using namespace std;
#include "ReversiBoard.h"

ReversiBoard::ReversiBoard(int size)
{
    // Check for board if its even or not
    if ((size < DEFAULT_SIZE) || (size % 2 == 1))
    {
        cout << "Invalid Value!!!" << endl;
        exit(0);
    }
    else
    {
        m_size = size;
        // Allocate memory for the 2D array.
        m_state = new STATE *[m_size];
        for (int i = 0; i < m_size; i++)
        {
            m_state[i] = new STATE[m_size];
        }

        // Initialize the board.
        for (int i = 0; i < m_size; i++)
        {
            for (int j = 0; j < m_size; j++)
            {
                m_state[i][j] = EMPTY;
            }
        }

        // Set initial pieces in the middle and opposite to each other for any size board
        m_state[(m_size / 2) - 1][(m_size / 2) - 1] = PLAYER1;
        m_state[m_size / 2][(m_size / 2) - 1] = PLAYER2;
        m_state[(m_size / 2) - 1][m_size / 2] = PLAYER2;
        m_state[m_size / 2][m_size / 2] = PLAYER1;
    }
}

STATE ReversiBoard::SetBoard(int row, int column, STATE player)
{
    // Check if the selected position in board is empty or not
    if (m_state[row][column] == EMPTY)
    {
        // Iterate through neighboring positions to check and update the board
        for (int dx = -1; dx <= 1; dx++)
        {
            for (int dy = -1; dy <= 1; dy++)
            {
                // Skip the current position
                if (dx == 0 && dy == 0)
                {
                    continue;
                }

                // Check if the neighboring position is within bounds
                if (row + dx < 0 || row + dx >= m_size || column + dy < 0 || column + dy >= m_size)
                {
                    continue;
                }

                // Skip if the neighboring position is empty or already belongs to the same player
                if (GetBoard(row + dx, column + dy) == player || GetBoard(row + dx, column + dy) == EMPTY)
                {
                    continue;
                }

                // Iterate in the current direction to check and update the board
                for (int i = 2; i < m_size; i++)
                {
                    // Check if the next position is within bounds
                    if (row + i * dx < 0 || row + i * dx >= m_size || column + i * dy < 0 || column + i * dy >= m_size)
                    {
                        break;
                    }

                    // Break if an empty position is encountered
                    if (GetBoard(row + i * dx, column + i * dy) == EMPTY)
                    {
                        break;
                    }

                    // If a piece of the same player is found, update the board and exit the loop
                    if (GetBoard(row + i * dx, column + i * dy) == player)
                    {
                        Flip(row, column, (row + i * dx), (column + i * dy), dx, dy, player);
                        break;
                    }
                }
            }
        }
        CheckEmptyPos();
        return PlayerSwitch(row, column, player);
    }
    else
    {
        cout << "Invalid Move" << endl;
        return player;
    }
}

STATE ReversiBoard::GetBoard(int row, int column)
{
    // return the requested state of position
    return m_state[row][column];
}

void ReversiBoard::Flip(int row, int column, int rowLast, int columnLast, int dx, int dy, STATE player)
{
    while (rowLast != row || columnLast != column)
    {
        rowLast -= dx;
        columnLast -= dy;
        m_state[rowLast][columnLast] = player;
    }
}

STATE ReversiBoard::PlayerSwitch(int row, int column, STATE player)
{
    // it checks whether the player has already established a piece at the entered position
    if (GetBoard(row, column) == player)
    {
        if (player == PLAYER1)
        {
            return PLAYER2;
        }
        else if (player == PLAYER2)
        {
            return PLAYER1;
        }
        else
        {
            return player;
        }
    }

    /* Else, if the player has not been established, it's not a valid move, and
     * the same player's turn continues.
     */
    else
    {
        cout << "Invalid Move" << endl;
        return player;
    }
}

int ReversiBoard::Getsize()
{
    return m_size;
}

void ReversiBoard::CheckEmptyPos()
{
    int player1 = 0, player2 = 0;
    for (int i = 0; i < m_size; i++)
    {
        for (int j = 0; j < m_size; j++)
        {
            if (m_state[i][j] == EMPTY)
            {
                return;
            }
            else
            {
                if (m_state[i][j] == PLAYER1)
                {
                    player1++;
                }
                else if (m_state[i][j] == PLAYER2)
                {
                    player2++;
                }
                else
                {
                    // do nothing
                }
            }
        }
    }

    if (player1 > player2)
    {
        cout << "Player 1 WON!!!" << endl;
    }
    else if (player1 < player2)
    {
        cout << "Player 2 WON!!!" << endl;
    }
    else
    {
        cout << "MATCH DRAW!!!" << endl;
    }
    exit(0);
}

ReversiBoard::~ReversiBoard()
{
    // Deallocate the memory in the destructor.
    for (int i = 0; i < m_size; i++)
    {
        delete[] m_state[i];
    }

    delete[] m_state;
}
