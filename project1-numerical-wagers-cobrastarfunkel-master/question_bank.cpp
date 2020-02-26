#include <string>
#include <iostream>

#include "question_bank.hpp"

int QuestionBank::counter; // static int to track index of question in questions

/*
 * Default Constructor 
 */
QuestionBank::QuestionBank()
{
  counter = -1;
  questionsFile.open("questions.txt");

  if (questionsFile)
  {
    LoadQuestions();
  }
  else
  {
    std::cout << "questions.txt not Found!" << std::endl;
  }
}

/*
* Parameterized constructor
*
* questionsFileName: string Name of the file of questions
*/
QuestionBank::QuestionBank(std::string questionsFileName)
{  
  counter = -1; // Keps track of the questions index
  questionsFile.open(questionsFileName); // Attempt to open the file

  // If the file exists
  if (questionsFile)
  {
	// Load the questions
    LoadQuestions();
  }
  else
  {
    // If the file is not found
    std::cout << questionsFileName << " not Found!" << std::endl;
  }
}

/**
 * Load the Questions for thw game from a file
 */
void QuestionBank::LoadQuestions()
{
  std::string line; // String lie to read each line of the file

  // While there are lines in the file, read through them one by one
  while (std::getline(questionsFile, line))
  {
	// If the line is not empty
    if (!line.empty())
    {
	  // Assign the first character to the first space as the answer
      std::string answer = line.substr(0, line.find(" "));

	  // Assign the rest of the line as the question
      std::string aQuestion = line.substr(line.find(" "), line.length());

	  // Make a new Question Object using answer and aQuestion
      Question tempQuest(aQuestion, answer);

	  // Add the Question object to the questions vector
      questions.push_back(tempQuest);
    }

	// If there's an empty line end the loop.
	// This was necessary because any blank lines after the questions
	// was breaking the QuestionBank object
    else
    {
      break;
    }
  }
  // Close the file
  questionsFile.close();
}

/**
 * Use the counter variable to assign the next question
 */
Question QuestionBank::GetNextQuestion()
{
  // If the counter is > or = to the size of the questions vector
  // minus 1 because the index starts at 0, set the counter back to 0
  if (counter >= questions.size() - 1)
  {
    counter = 0;
  }

  // Else increment the counter by one
  else
  {
    counter++;
  }
  std::cout << "Round: " << counter + 1 << "\n";
  return questions.at(counter);
}
