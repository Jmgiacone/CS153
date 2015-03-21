/*
 * Name: GIACONE, JORDAN
 * Date: 5-8-14
 * Class and Section: CS153, Section C
 * This is the Board Class
 */

#ifndef BOARD_H
#define BOARD_H
#include <iostream>
class Board
{
  private:
    int rows, cols, startRow, startCol;
  public:
    char** board;
    Board(const int r, const int c);
    ~Board();
    int getStartRow(){return startRow;}
    int getStartCol(){return startCol;}
    int getRows(){return rows;}
    int getCols(){return cols;}
    bool isValid(const int x, const int y);
    bool hasClam(const int x, const int y);
    bool hasWall(const int x, const int y);
    bool isExit(const int x, const int y);
    bool pathFind(const int x, const int y);
    bool inBounds(const int x, const int y);
    bool haveVisited(const int x, const int y);
    friend std::ostream& operator << (std::ostream& out, const Board& b);
};
#endif // BOARD_H
