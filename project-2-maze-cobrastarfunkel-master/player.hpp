/*
 * Player class for maze game
 * 
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

class Player
{
  private:
    int row;
    int col;
    int moves;

    std::vector<std::string> items;

  public:
    Player();

    int GetRow(); // Get Players current Row
    int GetCol(); // Get players current Col
    void SetPosition(int row, int col); // Set player position
    
    void AddItem(std::string item); // Add an item
    bool HasItem(std::string item); // Check if player has an item
    void UseItem(std::string item); // Use an item

    int GetMoveCount(); // Get player turns count
    void IncrementMoves(); // Increment player moves
};

#endif
