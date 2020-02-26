#include <sstream>
#include <iostream>

#include "hand.hpp"

Hand::Hand()
{
  
}

void Hand::AddToHand(Card* card)
{
  if(this->lowestCard == nullptr)
  {
    this->lowestCard = card;
    return;
  }
  
  this->lowestCard->SetPrev(card);
  card->SetNext(lowestCard);
  card->SetPrev(nullptr);
  this->lowestCard = card;
}

Card* Hand::SwapOutCard(Card* card, int position)
{
  Card* currentCardAtPos = this->lowestCard;

  if(position < 1 || position > 10)
  {
    return nullptr;
  }

  if(position == 1)
  {
    card->SetNext(this->lowestCard->GetNext());
    card->SetPrev(nullptr);

    this->lowestCard->GetNext()->SetPrev(card);
    this->lowestCard = card;

    currentCardAtPos->SetNext(nullptr);
    currentCardAtPos->SetPrev(nullptr);
    return currentCardAtPos;
  }

  int index = 0;
  while(index != position-1)
  {
    currentCardAtPos = currentCardAtPos->GetNext();
    index++;
  }
  
  if(position == 10)
  {
    card->SetNext(nullptr);
    card->SetPrev(currentCardAtPos->GetPrev());
    currentCardAtPos->GetPrev()->SetNext(card);

    currentCardAtPos->SetNext(nullptr);
    currentCardAtPos->SetPrev(nullptr);

    return currentCardAtPos;
  }

  currentCardAtPos->GetNext()->SetPrev(card);
  currentCardAtPos->GetPrev()->SetNext(card);

  card->SetPrev(currentCardAtPos->GetPrev());
  card->SetNext(currentCardAtPos->GetNext());
  currentCardAtPos->SetNext(nullptr);
  currentCardAtPos->SetPrev(nullptr);

  return currentCardAtPos;
}

bool Hand::HasRacko()
{
  Card* currentCard = this->lowestCard;
  Card* nextCard = this->lowestCard->GetNext();

  while(nextCard->GetNext() != nullptr)
  {

    if(currentCard->GetValue() > nextCard->GetValue())
    {
      return false;
    }
    currentCard = currentCard->GetNext();
    nextCard = nextCard->GetNext();
  }
  
  return true;
}

std::string Hand::ShowHand()
{
  std::stringstream stream;
  std::string retString;

  int spaces = 0;
  Card* indexCard = this->lowestCard;
  int counter = 1;
  for(int i = 0; i < 10; i++) 
  {
      spaces = indexCard->GetValue();
      stream << counter++ << ':';

      for(int i = 0; i < spaces; i++)
      {
        stream << ' ';
      }

      stream << spaces << "\n";
      indexCard = indexCard->GetNext();
  }

  retString = stream.str();
  return retString;
}

Card* Hand::GetLowestCard()
{
  return this->lowestCard;
}














