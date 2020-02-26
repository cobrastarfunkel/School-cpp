#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "deck.hpp"
#include "player.hpp"

class Game
{

  private:
    std::vector<Player> players;
    int* whichPlayersTurn;
    int numberOfPlayers;
    int currentPlayerTurn;
    int currentRound;
    Deck deck;
    Deck discard;
    void PlayerTurn();
    void DOption();
    void POption();

  public:
    Game(std::vector<Player> players);

    Player MakeHand(Player* player);
    void DoNextTurn();
    bool IsGameOver();
    Player* GetPlayer(int playerNumber);
    int ShowTopOfDiscardPile();
    Card* DrawFromDeck();
    void Discard(Card* card);

};

#endif
