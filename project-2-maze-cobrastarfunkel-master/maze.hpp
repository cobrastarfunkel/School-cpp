/*
 * Maze class for maze game
 * 
 */

#ifndef MAZE_HPP
#define MAZE_HPP

#include <fstream>
#include <iostream>
#include <vector>

#include "room.hpp"
#include "passage.hpp"
class Maze
{
  private:
    Room** rooms;
    int rows;
    int cols;
    std::ifstream mazeFile;

    void LoadMaze(); // Load the maze
    Passage* CreatePassage(std::string type); // Create passages
    void MakeRoomsArray(); // Make the array to store the rooms
    void MakeRooms(std::vector<std::string> tempMazeValues); // Make rooms and store them in the array

  public:
    Maze(std::string mazeFile);
    Room* GetRoom(int row, int col); // Get a Room based on row and col
    int GetNumberRows(); // Get rows in maze
    int GetNumberCols(); // Get Cols in maze

    ~Maze();
};

#endif
