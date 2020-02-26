#ifndef GAME_HPP
#define GAME_HPP

#include <set>
#include <string>

#include "die.hpp"
#include "gameboard.hpp"

class Game
{

  private:
    Die dice[16] = {
      {"RIFOBX"}, {"IFEHEY"}, {"DENOWS"},
      {"HMSRAO"}, {"LUPETS"}, {"ACITOA"},
      {"YLGKUE"}, {"QBMJOA"}, {"EHISPN"},
      {"VETIGN"}, {"BALIYT"}, {"EZAVND"},
      {"RALESC"}, {"UWILRG"}, {"PACEMD"},
      {"UTOKND"}};
    GameBoard board = GameBoard("WHYC");
    std::set<std::string> correctGuesses;
    int numberOfWrongGuesses;
    std::set<std::string> fullSetOfCorrectWords;

    void initDice();
    std::string GetAllDiceValues();
    bool IsValidGuess(std::string word);
    bool NewWord(std::string word);
    int GetWordScore(std::string word);
    int GetPointsForSet(const std::set<std::string>& wordList);

  public:
    Game();
    Game(std::string diceRolls);
    std::string ShowBoard();
    bool Guess(std::string word);
    int GetScore();
    int GetIncorrectGuesses();
    int GetTotalPointsPossible();

};

#endif
