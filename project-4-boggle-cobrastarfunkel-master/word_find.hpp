#ifndef WORD_FIND_HPP
#define WORD_FIND_HPP

#include <string>
#include <set>

#include "dictionary.hpp"
#include "gameboard.hpp"

class WordFind
{

  private:
    Dictionary dictionary;
    void AppendDFSWords(GameBoard g, std::string stringPrefix, std::set<std::string>& foundWords, bool alreadyChosen[16], int currentCell);
    bool LegalBounds(int x, int y);
    void ClearOutFoundArray(bool* alreadyChosen);

  public:
    WordFind();
    std::set<std::string> GetAllWords(GameBoard g);

};

#endif
