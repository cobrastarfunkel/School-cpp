#include "word_find.hpp"

WordFind::WordFind(){}

bool WordFind::LegalBounds(int x, int y)
{
  if(x < 0 || x > 3)
    return false;
  if(y < 0 || y > 3)
    return false;

  return true;
}

void WordFind::AppendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell)
{
  int x = currentCell/4;
  int y = currentCell%4;

  if(!LegalBounds(x, y))
    return;

  alreadyChosen[currentCell] = true;
  stringPrefix += g.GetLetterByRowCol(x, y);

  if(dictionary.IsWord(stringPrefix))
  {
    foundWords.insert(stringPrefix);
  }

  // DOWN and RIGHT
      if(x+1 > 3 && !alreadyChosen[y]) // Down > 3 end of board
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, y);
      }

      if(x < 4 && !alreadyChosen[4*(x+1)+y]) // DOWN
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*(x+1)+y));
      }

      if(y+1 > 3 && !alreadyChosen[4*x])  // Right > 3 end of board
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*x));
      }

      if(y+1 < 4 && !alreadyChosen[4*x+(y+1)]) // RIGHT
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*x+(y+1)));
      }
  // LEFT AND UP
      if(x-1 < 0 && !alreadyChosen[(4*3)+y]) // DOWN < 0 End of Board
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, ((4*3)+y));
      }

      if(x-1 > -1 && !alreadyChosen[4*(x-1)+y]) // DOWN
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*(x-1)+y));
      }
      if(y-1 < 0 && !alreadyChosen[(4*x)+3]) // LEFT < 0 End of Board
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*x+(3)));
      }

      if(y-1 > -1 && !alreadyChosen[4*x+(y-1)]) // LEFT
      {
        AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, (4*x+(y-1)));
      }
  stringPrefix.erase(stringPrefix.length()-1);
  alreadyChosen[currentCell] = false;
}

void WordFind::ClearOutFoundArray(bool* alreadyChosen)
{
  for(int i = 0; i < 16; i++)
    alreadyChosen[i] = false;
}

std::set<std::string> WordFind::GetAllWords(GameBoard g)
{
  std::string stringPrefix;
  std::set<std::string> foundWords;
  bool alreadyChosen[16];
  int currentCell = 0;

  while(currentCell < 16)
  {
    ClearOutFoundArray(alreadyChosen);
    AppendDFSWords(g, stringPrefix, foundWords, alreadyChosen, currentCell);
    currentCell++;
  }

  return foundWords;
}
