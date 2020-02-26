#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "question.hpp"

/**
 * Default Constructor
 */
Question::Question()
{
  text = "I'm Empty";
  answer = "Me Too";
}

/**
 * Param Constructor
 * 
 * Takes in 2 strings to create a Question Object.
 * 
 * test: The question in the file
 * answer: The answer to the question in the file.
 */
Question::Question(std::string text, std::string answer)
{
  this->text = text;
  this->answer = answer;
}

/**
 * Return a question
 */
std::string Question::GetText()
{
  return text;
}

/**
 * Check to see if a players guess contains a digit
 * that is part of the answer.
 * 
 * char digit:  The players guess
 */
bool Question::AnswerContainsDigit(char digit)
{
  // Loop through the answer
  for (unsigned i = 0; i < answer.length(); i++)
  {

    // If the players guess is in the answer
    if (digit == answer[i])
    {

      // Return true
      return true;
    }
  }

  // If not found return false
  return false;
}

/**
 * Creates a String that represents the digits guessed so far.
 * If a guess is a miss it is replaced with a '_'
 * 
 * vector<char> guess: The players guesses in a vector
 */
std::string Question::GetAnswerWithPlaceholders(std::vector<char> guess)
{
  std::string retString = answer;

  // Loop through the answer to assign '_' to the return string
  for (unsigned i = 0; i < answer.length(); i++)
  {
    retString[i] = '_';
  }

  // Loop through the guess
  for (char i : guess)
  {

    // If the guess is in the answer
    if (Question::AnswerContainsDigit(i))
    {

      //Loop through the answer so we can compare the two
      for (unsigned j = 0; j < answer.length(); j++)
      {

        // If the guess matches the answer
        if (i == answer[j])
        {
          // Assign the value to the '_'
          retString[j] = i;
        }
      }
    }
  }

  return retString;
}

/**
 * Check to see if all digits have been guessed
 */
bool Question::AllDigitsGuessed(std::string guesses)
{

  // Compare the guesses to the answer.  If it is the same return true
  if (guesses.compare(answer) == 0)
  {
    return true;
  }
  return false;
}
