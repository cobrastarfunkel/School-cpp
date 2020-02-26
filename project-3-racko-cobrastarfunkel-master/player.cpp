#include "player.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

int Player::counter = 0;

Player::Player()
{
  SetName(this->playerName);
  SetIsComputer(this->isComputer);
  Player::counter = 0;
}

Player::Player(std::string name, Hand hand, bool isComputer)
{
  SetName(name);
  SetHand(hand);
  SetIsComputer(isComputer);
  Player::counter = 0;
}

void Player::SetName(std::string name)
{
  this->playerName = name;
}

void Player::SetHand(Hand hand)
{
  this->hand = hand;
}

void Player::SetIsComputer(bool isComputer)
{
  this->isComputer = isComputer;
}

std::string Player::TurnPrompt()
{
  return this->playerName + "'s turn";
}

std::string Player::ShowHand()
{
  return this->hand.ShowHand(); 
}

Card* Player::SwapOutCard(Card* card, int position)
{
  return this->hand.SwapOutCard(card, position);
}

bool Player::HasRacko()
{
  if(this->hand.HasRacko())
  {
    std::cout << "RACKO!!!! " << this->playerName << " wins!\n";
    return true;
  }
  return false;
}

std::string Player::GetName()
{
  return this->playerName;
}

bool Player::IsComputer()
{
  return this->isComputer;
}

std::string Player::MakeChoice(int discardOption)
{
  std::string compDecision = "p";
  if(this->counter > 2)
  {
    this->counter = 0;
    return "d";
  }
  if(discardOption == 1)
    compDecision = "p";

  else if(discardOption < 20)
    compDecision = "d";
  return compDecision;
}

int Player::ComputerChooseSlot(int cardValue)
{
  if(cardValue >=1 && cardValue <= 6 && !slotOne)
  {
    slotOne = true;
    return 1;
  }
  if(cardValue >=7 && cardValue <= 12 && !slotTwo)
  {
    slotTwo = true;
    return 2;
  }
  if(cardValue >=13 && cardValue <= 18 && !slotThree)
  {
    slotThree = true;
    return 3;
  }
  if(cardValue >=14 && cardValue <= 24 && !slotFour)
  {
    slotFour = true;
    return 4;
  }
  if(cardValue >=25 && cardValue <= 31 && !slotFive)
  {
    slotFive = true;
    return 5;
  }
  if(cardValue >=32 && cardValue <= 38 && !slotSix)
  {
    slotSix = true;
    return 6;
  }
  if(cardValue >=39 && cardValue <= 44 && !slotSeven)
  {
    slotSeven = true;
    return 7;
  }
  if(cardValue >=45 && cardValue <= 50 && !slotEight)
  {
    slotEight = true;
    return 8;
  }
  if(cardValue >=51 && cardValue <= 55 && !slotNine)
  {
    slotNine = true;
    return 9;
  }
  if(cardValue >=56 && !slotTen)
  {
    slotTen = true;
    return 10;
  }
  this->counter++;
  return -1;
}










































