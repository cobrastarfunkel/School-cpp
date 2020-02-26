#include <iostream>
#include <string>

#include "dictionary.hpp"
#include "die.hpp"
#include "gameboard.hpp"
#include "word_find.hpp"
#include "game.hpp"

void StartGame()
{
  Game g = Game();
  std::string playerInput;

  std::cout << "########\n";
  std::cout << g.ShowBoard();
  std::cout << "########\n\n";

  int counter = 0; // To print out the board periodically during the game

  do
  {
    if(counter == 8)
    {
      counter = 0;
      std::cout << "########\n";
      std::cout << g.ShowBoard();
      std::cout << "########\n\n";
    }

    std::cout << "Enter a word: ";
    std::cin >> playerInput;
    
    if(playerInput != "q")
    {
      if(!g.Guess(playerInput))
        std::cout << "Not worth any points.\n\n";
      else
        std::cout << "Valid Word!\n\n";
    }
    counter++;

  } while(playerInput != "q");
  std::cout << "\nYou scored " << g.GetScore() << " points out of " << g.GetTotalPointsPossible() << "!\n";
  std::cout << "You had " << g.GetIncorrectGuesses() << " incorrct guesses.\n";
}

int main()
{
  StartGame();
}
