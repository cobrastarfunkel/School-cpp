/**
 * This class is the Question Object to be used during the game
 *
 * 
 */

#ifndef QUESTION_HPP
#define QUESTION_HPP
#include <string>
#include <vector>

class Question
{

private:

	std::string text; // The question
	std::string answer; // The answer


public:

  Question(); // Default constructor
  Question(std::string text, std::string answer); // Parameteized Constructor

  std::string GetText(); // Return the Question not the answer
  bool AnswerContainsDigit(char digit);  // Check if the guess is in the answer
  std::string GetAnswerWithPlaceholders(std::vector<char> guess); // Return the answer with _ inserted
  bool AllDigitsGuessed(std::string guessed); // Check if all digits were guessed
};

#endif