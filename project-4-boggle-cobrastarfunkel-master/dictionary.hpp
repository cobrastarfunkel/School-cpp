#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <unordered_set>
#include <fstream>
#include <string>

class Dictionary
{

  private:
    std::unordered_set<std::string> dictionary;
    std::ifstream wordsFile;

  public:
    Dictionary();
    bool IsWord(std::string word);

};
#endif
