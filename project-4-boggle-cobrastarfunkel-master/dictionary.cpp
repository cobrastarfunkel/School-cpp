#include <iostream>

#include "dictionary.hpp"

Dictionary::Dictionary()
{
  this->wordsFile.open("words.txt");
  if(this->wordsFile)
  {
    std::string word;
    while(std::getline(this->wordsFile, word))
    {
      if(!word.empty())
      {
        this->dictionary.insert(word); 
      }
    }
  }
}

bool Dictionary::IsWord(std::string word)
{
  std::unordered_set<std::string>::const_iterator foundWord = dictionary.find(word);

  if(foundWord == dictionary.end())
    return false;

  return true;
}
