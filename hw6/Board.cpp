/*
 * Name: GIACONE, JORDAN
 * Date: 5-8-14
 * Class and Section: CS153, Section C
 * This is the function definitions file
 */

#include "Board.h"
#include <iostream>

Board::Board(const int r, const int c)
{
  rows = r;
  cols = c;

  board = new char*[rows];
  for(int i = 0; i < rows; i++)
  {
    board[i] = new char[cols];
  }

  char dummy;
  for(int i = 0; i < rows; i++)
  {
    for(int j = 0; j < cols; j++)
    {
      std::cin.get(board[i][j]);

      if(board[i][j] == 'Z')//Found Zoidberg's start point
      {
        startRow = i;
        startCol = j;
      }
    }

    std::cin.get(dummy);   // read end-of-line
  }
}
bool Board::haveVisited(const int x, const int y)
{
  return inBounds(x, y) && board[x][y] == '.';
}
bool Board::isValid(const int x, const int y)
{
  return inBounds(x, y) && !hasClam(x, y) && !hasWall(x, y) && !haveVisited(x, y);
}
bool Board::inBounds(const int x, const int y)
{
  return (x >= 0 && x < rows) && (y >= 0 && y < cols);
}

bool Board::hasClam(const int x, const int y)
{
  return inBounds(x, y) && board[x][y] == 'C';
}

bool Board::hasWall(const int x, const int y)
{
  return inBounds(x, y) && board[x][y] == '#';
}

bool Board::isExit(const int x, const int y)
{
    return inBounds(x, y) && board[x][y] == 'E';
}

Board::~Board()
{
  for(int i = 0; i < rows; i++)
  {
    delete [] board[i];
  }
  delete [] board;
}

std::ostream& operator << (std::ostream& out, const Board& b)
{
    for(int i = 0; i < b.rows; i++)
    {
      for(int j = 0; j < b.cols; j++)
      {
        out << b.board[i][j];
      }
      out << std::endl;
    }

    return out;
}
