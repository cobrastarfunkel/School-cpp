#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "hand.hpp"

class Player
{

  private:
    std::string playerName = "Racko Champ";
    Hand hand;
    bool isComputer = false;
    bool slotOne = false;
    bool slotTwo = false;
    bool slotThree = false;
    bool slotFour = false;
    bool slotFive = false;
    bool slotSix = false;
    bool slotSeven = false;
    bool slotEight = false;
    bool slotNine = false;
    bool slotTen = false;


  public:
    Player();
    Player(std::string name, Hand hand, bool isComputer = false);
    static int counter;

    void SetName(std::string name);
    Hand MakeHand();
    void SetHand(Hand hand);
    void SetIsComputer(bool isComputer);
    std::string TurnPrompt();
    std::string ShowHand();
    Card* SwapOutCard(Card* card, int position);
    bool HasRacko();
    std::string GetName();
    bool IsComputer();
    std::string MakeChoice(int discardOption);
    int ComputerChooseSlot(int cardValue);
};

#endif
