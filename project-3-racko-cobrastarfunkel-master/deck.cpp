#include <stdlib.h>
#include <time.h>

#include "deck.hpp"

#include <iostream>

Deck::Deck()
{

}
void Deck::MakeFullDeck()
{
  for(int i = 1; i <= NUMBER_OF_CARDS_IN_RACKO_DECK; i++)
  {
    Push(i);
  }
}

void Deck::Push(int value)
{
  Card* card = new Card(value);
  
  if (this->top == nullptr)
  {
    this->top = card; 
  }
  else 
  { 
    card->SetPrev(this->top);
    this->top->SetNext(card);

    this->top = card;
    this->top->SetNext(nullptr);
  }
  this->numberOfCardsInDeck++;
}

void Deck::Discard(Card* card)
{
  if (this->top == nullptr)
  {
    this->top = card;
  }
  else
  {
    card->SetPrev(top);
    this->top->SetNext(card);
    this->top = card;
    this->top->SetNext(nullptr);
  }
  this->numberOfCardsInDeck++;
}

Card* Deck::Draw()
{
  Card* cardToDraw;
  if(this->numberOfCardsInDeck == 0)
    return nullptr;

  if (this->top->GetPrev() == nullptr)
  {
    cardToDraw = this->top;

    this->top->SetNext(nullptr);
    this->top->SetPrev(nullptr);

    this->numberOfCardsInDeck = 0;

    return cardToDraw;
  }
  cardToDraw = this->top;

  this->top = cardToDraw->GetPrev();
  cardToDraw->SetPrev(nullptr);
  this->top->SetNext(nullptr);
  this->numberOfCardsInDeck--;
  return cardToDraw;
}

int Deck::Peek()
{
  if (this->top == nullptr)
  {
    return -1;
  }
  return this->top->GetValue();
}

void Deck::Shuffle()
{
  srand(time(NULL));

  Card* tempCard;
  Card* tempTop = this->top;
  int tempCardNum = this->numberOfCardsInDeck-1;

  while(tempCardNum > 0)
  {
    int randNum = rand() % tempCardNum;
    int currentPosition = 0;
    tempCard = tempTop;

    while (currentPosition <= randNum)
    {
      tempCard = tempCard->GetPrev();
      currentPosition++;
    }

    if(tempCard->GetPrev() == nullptr)
    {
      RebuildDeck(tempCard);
      tempCard->GetNext()->SetPrev(tempCard->GetPrev());
    }

    else if(tempCard->GetNext() == nullptr)
    {
      tempTop = tempCard->GetPrev();
      tempCard->GetPrev()->SetNext(nullptr);
      RebuildDeck(tempCard);
    }

    else
    {
      tempCard->GetPrev()->SetNext(tempCard->GetNext());
      tempCard->GetNext()->SetPrev(tempCard->GetPrev());
      RebuildDeck(tempCard);
    }
    tempCardNum--;
  }
}

void Deck::RebuildDeck(Card* card)
{
  if(this->top->GetPrev() == nullptr)
  {
   this->top = card;  
  }
  else
  {
    card->SetPrev(this->top);
    this->top->SetNext(card);
  }

  this->top = card;
}

void Deck::InsertAt(Card* card, int index)
{
  if(index < 0 || index > this->numberOfCardsInDeck - 1)
  {
    return;
  }
  if(index == 0)
  {
    Discard(card);
    return;
  }
  
  Card* currentCardAtIndex = this->top;
  int currentPosition = 0;
  while(currentPosition != index-1)
  {
    currentCardAtIndex = currentCardAtIndex->GetPrev();
    currentPosition++;
  }
  card->SetNext(currentCardAtIndex->GetNext());
  currentCardAtIndex->GetNext()->SetPrev(card);
  card->SetPrev(currentCardAtIndex);
  currentCardAtIndex->SetNext(card);
  this->numberOfCardsInDeck++;
}

int Deck::GetNumCardsInDeck()
{
  return this->numberOfCardsInDeck;
}




































