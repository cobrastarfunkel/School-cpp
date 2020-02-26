/*
 * passage class for maze game
 * 
 */

#ifndef PASSAGE_HPP
#define PASSAGE_HPP

#include <string>

class Passage
{
  private:
    bool isOpen;
    std::string key ;

  public:
    Passage(); // Constructor for a solid wall
    Passage(bool isOpen); // Constructor for an open passage
    Passage(bool isOpen, std::string key); // Constructor for a passage that requires a key

    bool IsOpen(); // Check if open
    bool RequiresKey(); // Check if it requires a key
    std::string GetRequiredKey(); // Get the key it requires
    void Open(); // Open the passage
};

#endif
