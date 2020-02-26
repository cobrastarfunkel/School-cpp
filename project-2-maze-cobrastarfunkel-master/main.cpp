/*
 * Main class for maze game
 * 
 */

#include <iostream>
#include <fstream>

#include "room.hpp"
#include "maze.hpp"
#include "game.hpp"
#include "player.hpp"

void DeleteMaze(Game* game)
{
  delete game;
}

void GameLoop(Game* game)
{
  std::string playerInput;
  do
  {
    game->DisplayItems();
    
    std::cout << "\nWhich Direction would you like to move? ";
    std::cin >> playerInput;

    game->MoveDirection(playerInput);

  } while(!game->ExitFound());

}

void StartMaze()
{
  std::string mazeFile;
  std::ifstream file_check;
  std::cout << "Welcome To the Maze.\n";

  do
  {
    std::cout << "Please enter the filename of your maze or exit to quit: ";
    std::cin >> mazeFile;

    if(mazeFile == "exit")
    {
      std::cout << "Goodbye!\n";
      exit(1);
    }
  
    file_check.open(mazeFile);
  
    } while(!file_check);

  file_check.close();

  Maze* maze = new Maze(mazeFile);
  Player* player = new Player();
  Game* game = new Game(maze, player);
  
  GameLoop(game);
  DeleteMaze(game);
}


int main()
{
  StartMaze();
  return 0;
}
