/*
 * Name: GIACONE, JORDAN
 * Date: 5-8-14
 * Class and Section: CS153, Section C
 * This runs the pathfinder
 */

#include <iostream>
#include "Board.h"
using namespace std;
void path(int rows, int cols);
bool pathFind(Board* &board, const int x, const int y);

int main()
{
    int rows, cols, count = 0;

    cin >> cols;
    cin >> rows;
    cin.ignore();
    do
    {
      cout << "Map: " << count << endl;
      path(rows, cols);
      cin >> cols;
      cin >> rows;
      cin.ignore();
      count++;
    }while(rows != 0 && cols != 0);

    return 0;
}

void path(int rows, int cols)
{
  Board* board = new Board(rows, cols);

  pathFind(board, board->getStartRow(), board->getStartCol());
  cout << (*board) << endl;
  /*for(int i = 0; i < board->getRows(); i++)
  {
    for(int j = 0; j < board->getCols(); j++)
    {
      std::cout << board->board[i][j];
    }
    std::cout << std::endl;
  }*/

  delete board;
}

bool pathFind(Board* &board, const int x, const int y)
{
  board->board[x][y] = (board->board[x][y] == 'Z' ? 'Z' : '*');
  cout << (*board) << endl;
  bool success = false;
  int modRow = 0;
  int modCol = 0;
  for(int i = 0; i < 4 && !success; i++)
  {
    switch(i)
    {
      case 0://North
        modRow = -1;
        break;
      case 1://South
        modRow = 1;
        break;
      case 2://West
        modCol = -1;
        break;
      case 3://East
        modCol = 1;
        break;
    }

    if(board->isValid(x + modRow, y + modCol))
    {
      board->board[x][y] = (board->board[x][y] == 'Z' ? 'Z' : '.');
      //cout << (*board) << endl;
      if(board->board[x + modRow][y + modCol] == 'E')
      {
        return true;
      }
      else
      {
        success = pathFind(board, x + modRow, y + modCol);
        if(success)
        {
          return true;
        }
        else
        {
          board->board[x][y] = ' ';
          cout << (*board) << endl;
        }
      }
    }
    modRow = 0;
    modCol = 0;
  }
  board->board[x][y] = ' ';
  return false;
}


