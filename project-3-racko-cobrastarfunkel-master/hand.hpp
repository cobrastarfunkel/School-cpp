#ifndef HAND_HPP
#define HAND_HPP

#include <string>

#include "card.hpp"

class Hand
{

  private:
    Card* lowestCard = nullptr;

  public:
    Hand();

    void AddToHand(Card* card);
    Card* SwapOutCard(Card* card, int position);
    bool HasRacko();
    std::string ShowHand();
    Card* GetLowestCard();


};

#endif
