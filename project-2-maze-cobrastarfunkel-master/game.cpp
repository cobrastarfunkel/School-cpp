#include <iostream>

#include "game.hpp"

Game::Game(Maze* maze, Player* player)
{
  this->maze = maze;
  this->player = player;
}

/*
 * Return a Description of the passage based on the status of the passage
 */
std::string Game::GetPassageDescription(Passage* passage)
{
  // If It's an open passage
  if(passage->IsOpen())
  {
    return "Open Passage";
  }
  // If it requires a key and the player doesn't have it
  else if (passage->RequiresKey() && !this->player->HasItem(passage->GetRequiredKey()))
  {
    return "Closed Passage that requires a " + passage->GetRequiredKey();

  }
  // If the player has the key
  else if (passage->RequiresKey())
  {
    return "There is a locked Passage for which you have the Key ";    
  }
  // Else it's a wall
  return "Solid Wall";
}

/*
 * Display's the items and drives the Game class
 */
void Game::DisplayItems()
{
  // Print room name
  std::cout << "\n############\n" << GetCurrentRoomName() << "\n############";
  
  // Check each room for an exit
  ExitFound();

  // Loot the room of the items
  LootRoom();

  // List all the available passages in this room
  DisplayPassages();
}

/*
 * List available Passages with description form GetPassageDescription()
 */
void Game::DisplayPassages()
{
  std::string interfaceString = "There is a(n) ";

  std::cout << interfaceString << GetPassageDescription(this->maze->GetRoom(
       this->player->GetRow(), this->player->GetCol())->GetNorthPassage()) << " to the (N)orth.\n";
  std::cout << interfaceString << GetPassageDescription(this->maze->GetRoom(
       this->player->GetRow(), this->player->GetCol())->GetEastPassage()) << " to the (E)ast.\n";
  std::cout << interfaceString << GetPassageDescription(this->maze->GetRoom(
       this->player->GetRow(), this->player->GetCol())->GetSouthPassage()) << " to the (S)outh.\n";
  std::cout << interfaceString << GetPassageDescription(this->maze->GetRoom(
       this->player->GetRow(), this->player->GetCol())->GetWestPassage()) << " to the (W)est.\n";
}

/*
 * Get room name
 */
std::string Game::GetCurrentRoomName()
{
  return  this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetName();
}

/*
 * Loot the Room
 */
void Game::LootRoom()
{
  // Get a count of the amount of items in the room
  int counter = this->maze->GetRoom(
      this->player->GetRow(), this->player->GetCol())->ListItems();

  // If the count is > than 0
  if(counter > 0)
  {
    // Loop through the items in the room and add them to the players inventory
    while(counter > 0)
    {
      this->player->AddItem(
         this->maze->GetRoom(
         this->player->GetRow(), this->player->GetCol())->AcquireNextItem());
      counter--;
    }
    std::cout << "All Items added to Inventory.\n\n";
  }
  else
  {
    std::cout << "There are no Items in this room\n\n";
  }
}

/**
 * Check whether the direction that was entered is a valid direction based on the
 * Input and whether the Passage is accessible.  The notes for 'e' work for the rest
 * of the possible inputs as well
 * */
bool Game::ValidDirection(std::string direction)
{
  // Cut the players input down to the first character and lowercase it
  char charInput = std::tolower(direction[0], std::locale());

  if(charInput == 'e')
  {
    // Check if the passage is open
    if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->IsOpen())
    {
      return true;
    }
    // Check if it requires a key
    else if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->RequiresKey())
    {
      // Check if the player has the key
      if(this->player->HasItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->GetRequiredKey()))
      {
        // Use the key
        this->player->UseItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->GetRequiredKey());

        // Open the passage permanently
        this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->Open();

        // Open the passage from the other side so if the player goes back it isn't locked again
        this->maze->GetRoom(this->player->GetRow(), this->player->GetCol()+1)->GetWestPassage()->Open();
        return true;
      }
    }
  }

  else if(charInput == 's')
  {
    if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->IsOpen())
    {
      return true;
    }
    else if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->RequiresKey())
    {
      if(this->player->HasItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->GetRequiredKey()))
      {
        this->player->UseItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->GetRequiredKey());
        this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->Open();
        this->maze->GetRoom(this->player->GetRow()+1, this->player->GetCol())->GetNorthPassage()->Open();
        return true;
      }
    }
  }
  
  else if(charInput == 'n')
  {
    if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->IsOpen())
    {
      return true;
    }
    else if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->RequiresKey())
    {
      if(this->player->HasItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->GetRequiredKey()))
      {
        this->player->UseItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->GetRequiredKey());
        this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->Open();
        this->maze->GetRoom(this->player->GetRow()-1, this->player->GetCol())->GetSouthPassage()->Open();
        return true;
      }
    }
  }

  else if(charInput == 'w')
  {
    if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->IsOpen())
    {
      return true;
    }
    else if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->RequiresKey())
    {
      if(this->player->HasItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->GetRequiredKey()))
      {
        this->player->UseItem(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->GetRequiredKey());
        this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->Open();
        this->maze->GetRoom(this->player->GetRow()-1, this->player->GetCol())->GetEastPassage()->Open();
        return true;
      }
    }
  }

  // Return false if the input doesn;t match a valid option
  return false;
}

/*
 * Move the player after verifying the input using ValidDirection()
 */
void Game::MoveDirection(std::string direction)
{
  // If the direction is valid
  if(ValidDirection(direction))
  {
    // Grab first letter and lowercase it
    char charInput = std::tolower(direction[0], std::locale());

    // Switch for input
    switch(charInput)
    {
      // Increment the players position based on direction
      // 'e' means col +1
      // 's' row +1
      // 'n' row -1
      // 'w' col -1
      case 'e':
        this->player->SetPosition(this->player->GetRow(), this->player->GetCol()+1);
        break;
    
      case 's':
        this->player->SetPosition(this->player->GetRow()+1, this->player->GetCol());
        break;
    
      case 'n':
        this->player->SetPosition(this->player->GetRow()-1, this->player->GetCol());
        break;
    
      case 'w':
        this->player->SetPosition(this->player->GetRow(), this->player->GetCol()-1);
        break;
    }
  }
  // Invalid direction ex. Wall or locked door
  else
  {
    std::cout << "\n***** You Can't Go That Way *****\n";
  }
}

/*
 * Check if they found the exit by comparing the passages in the room, if the passage is open
 * and the other side of that passage is a number that is either below 0 or higher than
 * the row or col size minus 1.  An exit is found.  The comparison and the number it looks for
 * is based on the direction of the passage
 *
 * East col >= number of cols
 * South row >= number of rows
 * West col < 0
 * North row < 0
 */
bool Game::ExitFound()
{
  // String to be used if they found the exit
  std::string exitString = "You found the exit!\n";

  // If the east passage is open
  if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetEastPassage()->IsOpen()) 
  {
    // If the passage on the other side of the open passage is out of bounds they found an exit
    if(this->player->GetCol()+1 >= this->maze->GetNumberCols())
    {
      std::cout << exitString;

      // Get Player turns
      std::cout << "It took you " << this->player->GetMoveCount() << " turns to find the exit!\n";
      return true;
    }
  }

  // West Passage
  if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetWestPassage()->IsOpen()) 
  {
    if(this->player->GetCol()-1 < 0)
    {
      std::cout << exitString;
      std::cout << "It took you " << this->player->GetMoveCount() << " turns to find the exit!\n";
      return true;
    }
  }
 
  // North Passage
  if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetNorthPassage()->IsOpen()) 
  {
    if(this->player->GetRow()-1 < 0)
    {
      std::cout << exitString;
      std::cout << "It took you " << this->player->GetMoveCount() << " turns to find the exit!\n";
      return true;
    }
  }
 
  // South Passage
  if(this->maze->GetRoom(this->player->GetRow(), this->player->GetCol())->GetSouthPassage()->IsOpen()) 
  {
    if(this->player->GetCol()+1 >= this->maze->GetNumberRows())
    {
      std::cout << exitString; 
      std::cout << "It took you " << this->player->GetMoveCount() << " turns to find the exit!\n";
      return true;
    }
  }
  // No exits found
  return false;
}
