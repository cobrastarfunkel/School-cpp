#include <iostream>

#include "card.hpp"

Card::Card(int value, Card* prev, Card* next)
{
  this->value = value;
  SetPrev(prev);
  SetNext(next);
}

void Card::SetNext(Card* next)
{
  this->next = next;
}

void Card::SetPrev(Card* prev)
{
  this->prev = prev;
}

void Card::SetValue(int value)
{
  this->value = value;
}

Card* Card::GetNext()
{
  return next;
}

Card* Card::GetPrev()
{
  return prev;
}

int Card::GetValue()
{
  if(value == 0)
  {
    return -1;
  }
  return this->value;
}
