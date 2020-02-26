#include <algorithm>

#include "game.hpp"
#include "word_find.hpp"

Game::Game()
{
  initDice();

  WordFind words;
  this->fullSetOfCorrectWords = WordFind().GetAllWords(this->board);
  this->numberOfWrongGuesses = 0;
}

Game::Game(std::string diceRolls)
{
  this->board = GameBoard(diceRolls);

  WordFind words;
  this->fullSetOfCorrectWords = WordFind().GetAllWords(this->board);
  this->numberOfWrongGuesses = 0;
}

void Game::initDice()
{
  std::string diceRolls = GetAllDiceValues();

  std::random_shuffle(diceRolls.begin(), diceRolls.end());

  this->board = GameBoard(diceRolls);
}

std::string Game::GetAllDiceValues()
{
  std::string diceRolls;

  for(Die die : dice)
    diceRolls += die.Roll();

  return diceRolls;
}

bool Game::IsValidGuess(std::string word)
{
  std::set<std::string>::const_iterator foundWord = fullSetOfCorrectWords.find(word);

  if(foundWord != fullSetOfCorrectWords.end())
    return true;
  
  return false;
}

bool Game::NewWord(std::string word)
{
  std::set<std::string>::const_iterator alreadyFoundWord = correctGuesses.find(word);
  
  if(alreadyFoundWord != correctGuesses.end())
    return false;

  return true;
}

int Game::GetWordScore(std::string word)
{
  int wordLength = word.length();

  switch(wordLength)
  {
    case 1:
    case 2:
      return 0;

    case 3:
    case 4:
      return 1; 

    case 5:
      return 2;

    case 6:
      return 3;

    case 7:
      return 4;

    default:
      return 11;
  }

}

int Game::GetPointsForSet(const std::set<std::string>& wordList)
{
  int totalPoints = 0;

  for(std::string word : wordList)
  {
    totalPoints += GetWordScore(word);
  }

  return totalPoints;
}

std::string Game::ShowBoard()
{
  return this->board.ShowBoard();
}

bool Game::Guess(std::string word)
{
  if(IsValidGuess(word) && NewWord(word))
  {
    this->correctGuesses.insert(word);
    return true;
  }

  else if(IsValidGuess(word) && !NewWord(word))
    return false;

  this->numberOfWrongGuesses++;
  return false;
}

int Game::GetScore()
{
  return GetPointsForSet(this->correctGuesses);
}

int Game::GetIncorrectGuesses()
{
  return this->numberOfWrongGuesses;
}

int Game::GetTotalPointsPossible()
{
  return GetPointsForSet(this->fullSetOfCorrectWords);
}




















