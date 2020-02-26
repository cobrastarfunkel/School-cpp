#ifndef DIE_HPP
#define DIE_HPP

#include <string>

class Die
{

  private:
    char possibleLetters[6];

  public:
    Die(std::string possibleLetters);
    char Roll();

};

#endif
