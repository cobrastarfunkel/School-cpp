#include <iostream>
#include <sstream>

#include "maze.hpp"

Maze::Maze(std::string mazeFile)
{
    this->mazeFile.open(mazeFile);

    if(this->mazeFile)
    {
      LoadMaze();
    }
    else
    {
      std::cout << "Maze File Not Found\n";
    }
}

/*
 * Maze destructor
 * Loop through rooms array and free up memmory from the heap
 */
Maze::~Maze()
{
  for(int i = 0; i < this->rows; i++)
  {
      delete[] this->rooms[i];
  }
  delete[] this->rooms;
}

/*
 * Loads the maze for the Game
 */
void Maze::LoadMaze()
{
  std::string line;
  std::vector<std::string> tempMazeValues;

  // Read in the file
  while(std::getline(this->mazeFile, line))
  {
    if(!line.empty())
    {
      // Add lines into a vector
      tempMazeValues.push_back(line);
    }
  }
  this->mazeFile.close();

  // Assign the rows and cols values to chars
  char tempchar = tempMazeValues[0][0];
  char tempcol = tempMazeValues[0][2];

  // If I don't do this the values of the chars are changed to higher numbers
  this->rows = tempchar - '0';
  this->cols = tempcol - '0';

  // Erase the first item from the vector, The row and col size
  // This way we don;t have to deal with that line when we're looking
  // for rooms.
  tempMazeValues.erase(tempMazeValues.begin());

  // Initiate the rooms array
  MakeRoomsArray();

  // Make rooms
  MakeRooms(tempMazeValues);
}

/*
 * Create the dynamic array for rooms
 */
void Maze::MakeRoomsArray()
{
  rooms = new Room*[this->rows];
  for(int i = 0; i < this->rows; i++)
  {
    rooms[i] = new Room[this->cols];
  }
}

/*
 * Make the rooms and add them to the rooms array
 */
void Maze::MakeRooms(std::vector<std::string> tempValues)
{
  // Strings for the passage assignments
  std::string name, northPass, southPass, eastPass, westPass;

  // Room count == rows * cols
  int roomCount = rows*cols;

  int counter = 0;
    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < cols; j++)
      {
        // Find the words or symbols separated by ',' and assign them to
        // passages, then delete it from the vector, then create a room with the assigned passages
        if (counter < roomCount)
        {
          name = tempValues[counter].substr(0, tempValues[counter].find(","));
          tempValues[counter].erase(0, tempValues[counter].find(",")+1);

          northPass = tempValues[counter].substr(0, tempValues[counter].find(","));
          tempValues[counter].erase(0, tempValues[counter].find(",")+1);

          southPass = tempValues[counter].substr(0, tempValues[counter].find(","));
          tempValues[counter].erase(0, tempValues[counter].find(",")+1);
  
          eastPass = tempValues[counter].substr(0, tempValues[counter].find(","));
          tempValues[counter].erase(0, tempValues[counter].find(",")+1);

          westPass = tempValues[counter].substr(0, tempValues[counter].find(","));
          tempValues[counter].erase(0, tempValues[counter].find(",")+1);
          
        }
        
        // Create and add the room to the array
        rooms[i][j] = Room(
            name, 
            CreatePassage(northPass), 
            CreatePassage(southPass), 
            CreatePassage(eastPass), 
            CreatePassage(westPass));

        // If the vector still has stuff in it, then there are items
        if(!tempValues[counter].empty())
        {
          // Stream the rest of the values in the vector for this element
          // This delimits them by " " automatically
          std::stringstream stream(tempValues[counter]);
          std::string buffer;

          // While there's an item to stream in the vector
          while(stream >> buffer)
          {
            // Add the item to the room
            rooms[i][j].AddItem(buffer);
          }
        }
        counter++;
      }
    }
}

/*
 * Create a passage based on the symbol or word used in the file
 */
Passage* Maze::CreatePassage(std::string type)
{
  // open passage
  if(type == "+")
  {
      return new Passage(true);
  }

  // Closed passage
  else if (type == "-")
  {
      return new Passage();
  }

  // Else it requires a key
  return new Passage(false, type);
}

/*
 * Get the number of rows in the maze
 */
int Maze::GetNumberRows()
{
  return this->rows;
}

/*
 * Get the number of columns in the maze
 */
int Maze::GetNumberCols()
{
  return this->cols;
}

/*
 * Get a Room in the maze based on row and col
 */
Room* Maze::GetRoom(int row, int col)
{
  return &rooms[row][col];
}
















