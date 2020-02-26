#include "gameboard.hpp"

GameBoard::GameBoard(std::string letters)
{
  int counter = 0;
  for(int i = 0; i < 4; i++)
  {
    for(int j = 0; j < 4; j++)
    {
      this->letters[i][j] = letters[counter];
      counter++;
    }
  }
}

char GameBoard::GetLetterByRowCol(int row, int col)
{
  return this->letters[row][col];
}

std::string GameBoard::ShowBoard()
{
  std::string returnString;
  for(int i = 0; i < 4; i++)
  {
    int counter = 0;
    for(int j = 0; j < 4; j++)
    {
      returnString += this->letters[i][j];
      if(counter == 3)
      {
        returnString += "\n";
      }
      else
      {
        returnString += " ";
      }
      counter++;
    }
  }
  return returnString;
}
