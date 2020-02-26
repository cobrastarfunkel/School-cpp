/*
 * Game class, Main driving class for the maze game
 * 
 */

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>

#include "maze.hpp"
#include "player.hpp"
#include "room.hpp"
#include "passage.hpp"

class Game
{
  private:
    Maze* maze;
    Player* player;
    Room* currentRoom;
    std::vector<std::string> currentItems;

    std::string GetPassageDescription(Passage* passage);

  public:
    Game(Maze* maze, Player* player);

    void DisplayItems(); // Display Items and drive the game
    void DisplayPassages(); // Display the available Passages
    std::string GetCurrentRoomName(); // Get the Room name
    void LootRoom(); // Loot the current Room
    bool ValidDirection(std::string direction); // Check if player input is a valid direction
    void MoveDirection(std::string direction); // Move the player
    bool ExitFound(); // Check if the player found an exit

};

#endif
