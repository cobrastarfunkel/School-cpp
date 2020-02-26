/**
 * This class is the Game object which drives the game
 *
 * 
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

#include "question_bank.hpp"

class Game
{
private:
  QuestionBank *questions; // Pointer to QuestionBank Object holding the Questions
  int amountWagered; // Amount wagered by the player
  int currentScore; // Players current Score

public:
  Game(); // Default Constructor
  Game(QuestionBank *qs); // Param Constructor
  ~Game(); // Destructor for QuestionBank object

  int AskQuestion(); // Drives the game
  void AdjustPoints(bool isCorrect); // Adjust points based on correct or incorrect answer
  void SetWager(int wager); // Set the players wager
  int GetWager(); // Get the players wager
  int GetCurrentScore(); // Get the players Current Score
};

#endif
