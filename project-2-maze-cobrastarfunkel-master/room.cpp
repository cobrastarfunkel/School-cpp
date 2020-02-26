#include <iostream>

#include "room.hpp"


/**
 * Default Constructor
 */
Room::Room()
{
  name = "Lobby";
  Passage* northPassage();
  Passage* southPassage();
  Passage* eastPassage();
  Passage* westPassage();
}

/**
 * Param Constructor
 */
Room::Room(std::string name, Passage* north, Passage* east, Passage* south, Passage* west)
{
  this->name = name;
  this->northPassage = north;
  this->southPassage = south;
  this->eastPassage = east;
  this->westPassage = west;
}

/**
 * Get name of the room
 */
std::string Room::GetName()
{
  return this->name;
}

/**
 * Get the Passages based on their drection
 */
Passage* Room::GetNorthPassage()
{
  return northPassage;
}

Passage* Room::GetSouthPassage()
{
  return southPassage;
}

Passage* Room::GetEastPassage()
{
  return eastPassage;
}

Passage* Room::GetWestPassage()
{
  return westPassage;
}

/**
 * Add Items to Player inventory
 */
void Room::AddItem(std::string item)
{
  items.push_back(item);
}

/*
 * Get the next item in the room
 */
std::string Room::AcquireNextItem()
{
  // If items is not empty
  if(!items.empty()) 
  {
    // Assign that item to a return string
    std::string retItem = items.back();

    // Remove the item
    items.pop_back();
    return retItem;
  }
  return "";
}

/*
 * Helper function to print out all the items in the room
 * and return a counter for game class to keep track of
 * how many times it needs to grab items for the player
 */
int Room::ListItems()
{
  int counter = 0;
  std::cout << "\n\n";
  for(std::string item: items)
  {
    std::cout << "There is a(n) " << item << " in this room.\n";
    counter++;
  }
  std::cout << "\n";
  return counter;
}








