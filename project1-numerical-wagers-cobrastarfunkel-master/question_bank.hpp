/**
 * This class holds the Questions that will be used in the game
 *
 * 
 */

#ifndef QUESTION_BANK_HPP
#define QUESTION_BANK_HPP

#include <string>
#include <fstream>
#include <vector>

#include "question.hpp"

class QuestionBank
{

private:
  static int counter; // Counter to track questions index
  std::vector<Question> questions; // vector of the Questions
  std::ifstream questionsFile; // File full of questions

  void LoadQuestions(); // Load Questions into the questions vector

public:
  QuestionBank(); // Default Constructor
  QuestionBank(std::string questionsFileName); // Parameterized Constructor
  
  Question GetNextQuestion(); // Retrieve next Question
};

#endif
