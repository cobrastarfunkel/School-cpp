#include <iostream>
#include <limits>
#include <vector>
#include <stdlib.h>

#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

//int NumPlayersLoop();

//Player CreatePlayer();

int NumPlayersLoop()
{
  int numPlayers;
  do
  {
    std::cout << "Let's play Racko!\n";
    std::cout << "How many Players (including Computers, max 4): ";
    std::cin >> numPlayers;
    if(std::cin.fail())
    {
      std::cout << "Please enter an integer between 1 and 4.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  } while (numPlayers < 1 || numPlayers > 4);
  return numPlayers;
}

Player CreatePlayer(int playerNum)
{
  std::string name;
  int isCompInt;
  bool isComp;
  Hand hand;

  std::cout << "Enter player " << playerNum << "'s Name: ";
  std::cin >> name;

  do
  {
    std::cout << "Is this player a Computer?(1 for yes, 0 for no): ";
    std::cin >> isCompInt;
    if(std::cin.fail())
    {
      std::cout << "Please enter a 1 or 0.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      // Needed to enforce valid input from player
      isCompInt = 2;
    }
  } while(isCompInt < 0 || isCompInt > 1);

  if(isCompInt == 0)
    isComp = false;
  else
    isComp = true;
  
  return Player(name, hand, isComp);
}

void PlayGame(std::vector<Player> players)
{
  Game game(players);
  int roundNumber = 0;
  do
  {
    std::cout << "##########################################\n" << "Round: " << roundNumber << "\n\n";
    game.DoNextTurn();
    roundNumber++;
  } while(!game.IsGameOver());
}

int main()
{
  std::vector<Player> players;
  int numPlayers = NumPlayersLoop();
  
  for(int i = 0; i < numPlayers; i++)
  {
    players.push_back(CreatePlayer(i+1));
  }

  PlayGame(players);

  return 0;
}
