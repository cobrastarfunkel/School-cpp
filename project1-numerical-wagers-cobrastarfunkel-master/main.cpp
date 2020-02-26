/**
 * Main class for the Numerical Wagers game
 *
 * 
 */

#include <iostream>
#include <string>
#include <vector>

#include "game.hpp"
#include "question.hpp"
#include "question_bank.hpp"

/**
 * The main Game loop.  Handles the game and whether another
 * round will be played or not.
 */
void StartGame()
{
  char yesOrNo; // string for playing again
  bool playAgain = false; // bool that handles the play again loop
  bool goodSelection = false; // bool that handles the input for play again lop

  std::string questionsFileName; // Player input for file name
  std::ifstream file_check; // Check if the file exists
  int questionsCount; // Counter for the amount of questions in the file
  std::string line; // To read in the lines of the file for counter

  do
  {
    do
    {
      // Reset the count so it doesn't carry over to a new game
      questionsCount = 0;

      std::cout << "Please enter the name of the file containing your questions or exit to quit: ";
      std::cin >> questionsFileName;

      // Quit if the player enters exit
      if (questionsFileName == "exit")
      {
        std::cout << "GoodBye!" << std::endl;
        exit(1);
      }

      // Check if the filename is valid
      file_check.open(questionsFileName);

      // Ensure a valid file name or exit is entered
    } while (!file_check);

    // Initiate a loop to get the amount of questions in the file
    while (std::getline(file_check, line))
    {
      if (!line.empty())
      {

        // Increment questions count for use in game loop
        questionsCount++;
      }
    }

    // Close the file
    file_check.close();

    // Create a game object
    Game* game = new Game(new QuestionBank(questionsFileName));

    do
    {
		if (game->GetCurrentScore() > 0)
		{
			// Start the game
			game->AskQuestion();

			// Decrement the questions count
			questionsCount--;
		}
		else
		{
			break;
		}
      // If the questions run out end the loop
    } while (questionsCount != 0);

    std::cout << "\nFinal Score: " << game->GetCurrentScore() << std::endl;

    do
    {

      // Play again loop
      std::cout << "Would you like to play again? Enter y or n: ";
      std::cin >> yesOrNo;

      if (tolower(yesOrNo) == 'y')
      {
        playAgain = true;
        goodSelection = true;
      }
      else if (tolower(yesOrNo) == 'n')
      {
        std::cout << "GoodBye!\n";
        exit(1);
      }
      else
      {
        std::cout << "Invalid Entry!\n";

        // Sometimes a bad iput will be taken as y.  Not sure what causes it
        // to flip the boolean but this fixes it.
        goodSelection = false;
      }
    } while (!goodSelection);
    delete game;
  } while (playAgain);
}

/**
 * main method, starts the game
 */
int main()
{
  std::cout << "Welcome to Numerical Wagers!" << std::endl;
  StartGame();

  return 0;
}
