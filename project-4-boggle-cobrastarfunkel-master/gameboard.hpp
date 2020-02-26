#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include <string>

class GameBoard
{

  private:
    char letters[4][4];

  public:
    GameBoard(std::string letters);
    char GetLetterByRowCol(int row, int col);
    std::string ShowBoard();

};

#endif
