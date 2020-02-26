#include <stdlib.h>
#include <time.h>

#include "die.hpp"

Die::Die(std::string possibleLetters)
{
  for(unsigned int i = 0; i < 6; i++)
  {
    this->possibleLetters[i] = possibleLetters[i];
  }
}

char Die::Roll()
{
  srand(time(NULL));

  unsigned int randIndex = rand() % 6;

  for(unsigned int i = 0; i < 6; i++)
  {
    if(i == randIndex)
    {
      return this->possibleLetters[i];
    }
  }
  return possibleLetters[0];
}
