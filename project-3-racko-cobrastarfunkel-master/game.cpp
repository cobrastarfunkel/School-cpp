#include "game.hpp"

#include <iostream>
#include <string>

Game::Game(std::vector<Player> players)
{
  this->players = players;
  this->numberOfPlayers = this->players.size();
  this->deck.MakeFullDeck();
  this->deck.Shuffle();
  this->discard.Discard(this->deck.Draw());
  this->discard.Discard(this->deck.Draw());

  for(unsigned int i = 0; i < players.size(); i++)
  {
    Player* tempPlayer = &this->players[i];
    this->players[i] = MakeHand(tempPlayer);
  }
}

Player Game::MakeHand(Player* player)
{
  Hand tempHand;

  for(int i = 0; i < 10; i++)
  {
    tempHand.AddToHand(deck.Draw());
  }
  player->SetHand(tempHand);
  return *player;
}

void Game::DoNextTurn()
{
  for(unsigned int i = 0; i < this->players.size(); i++)
  {
      this->currentPlayerTurn = i+1;
      if(IsGameOver())
        break;

      std::cout << GetPlayer(currentPlayerTurn)->TurnPrompt() << "\n";
      std::cout << GetPlayer(currentPlayerTurn)->ShowHand() << "\n";

      std::cout << "Available Card in Discard: " << ShowTopOfDiscardPile() << "\n";
      

      if(GetPlayer(currentPlayerTurn)->IsComputer())
      {
        int discardTop = ShowTopOfDiscardPile();
        int deckPeek = this->deck.Peek();
        std::string compDecision = GetPlayer(currentPlayerTurn)->MakeChoice(ShowTopOfDiscardPile());
        char charInput = std::tolower(compDecision[0], std::locale());
        int compChooseSlot;

        std::cout << "Enter p to draw from the discard pile, d to draw from the deck: " << compDecision << "\n";

        switch(charInput)
        {
          case 'p':
            compChooseSlot = GetPlayer(currentPlayerTurn)->ComputerChooseSlot(discardTop);
            if(compChooseSlot < 1)
            {
              break;
            }
            else
            {
              Discard(GetPlayer(currentPlayerTurn)->SwapOutCard(this->discard.Draw(), compChooseSlot));
            }
            break;

          case 'd':
            compChooseSlot = GetPlayer(currentPlayerTurn)->ComputerChooseSlot(deckPeek);
            if(compChooseSlot < 1)
            {
              Discard(DrawFromDeck());
            }
            else
            {
              std::cout << "Swapping out Slot: " << compChooseSlot << " With: " << deckPeek << "\n";
              Discard(GetPlayer(currentPlayerTurn)->SwapOutCard(DrawFromDeck(), compChooseSlot));
            }
            break;
        }
      }
      else
      {
        PlayerTurn();
      }
    
    if(IsGameOver())
      break;
  }
}

void Game::PlayerTurn()
{
  bool validAnswer = false;
  char charInput;
  std::string playerInput;
  do
  {
    std::cout << "Enter 'p' to get the card from the dicard pile, or 'd' to draw from the deck or 'e' to quit: ";
    std::cin >> playerInput;
    charInput = std::tolower(playerInput[0], std::locale());

    if(charInput == 'e')
      exit(0);

    if(charInput == 'p' || charInput == 'd')
      {
        validAnswer = true;
      }
    else
      std::cout << "\n#### Invalid Entry ####\n";

   }while(!validAnswer);

  if(charInput == 'p')
  {
    POption();
  }
  else
  {
    DOption();
  }
}

void Game::DOption()
{
  int intInput;
  bool validInput = false;
  do
  {
     std::cout << "Enter the slot to replace (Less Than 1 Discards) " << this->deck.Peek() << " with: ";
     std::cin >> intInput;

     if(intInput > 0 && intInput < 11)
     {
       Discard(GetPlayer(currentPlayerTurn)->SwapOutCard(DrawFromDeck(), intInput));
       validInput = true;
     }
 
     if(intInput < 1)
     {
       Discard(DrawFromDeck());
       validInput = true;
     }
   }while(!validInput);
}

void Game::POption()
{
  int intInput;
  bool validInput = false;
  do
    {
      std::cout << "Enter the slot to replace (Less Than 1 Discards) " << ShowTopOfDiscardPile() << " with: ";
      std::cin >> intInput;

      if(intInput > 0 && intInput < 11)
      {
        Discard(GetPlayer(currentPlayerTurn)->SwapOutCard(this->discard.Draw(), intInput));
        validInput = true;
      }
      if(intInput < 1)
      {
        validInput = true;
      }
    } while(!validInput);
}

bool Game::IsGameOver()
{
  return players[this->currentPlayerTurn-1].HasRacko();
}

Player* Game::GetPlayer(int playerNumber)
{
  Player* tempPlayer = &players[playerNumber-1];
  return tempPlayer;
}

int Game::ShowTopOfDiscardPile()
{
  return this->discard.Peek();
}

Card* Game::DrawFromDeck()
{
  Card* tempCard = this->deck.Draw();
  bool cardsInDeck = true;
  if(tempCard == nullptr)
  {
    do 
    {
      Card* discardCard = discard.Draw();
      if(discardCard == nullptr)
      {
        cardsInDeck = false;
        break;
      }
      this->deck.Discard(discardCard);
    }while(cardsInDeck);

    this->deck.Shuffle();
    this->discard.Discard(this->deck.Draw());
    tempCard = this->deck.Draw();
  }
  return tempCard;
}

void Game::Discard(Card* card)
{
  this->discard.Discard(card);
}
