/*
 * room class for maze game
 * 
 */
 
#ifndef ROOM_DEF
#define ROOM_DEF

#include <string>
#include <vector>

#include "passage.hpp"

class Room
{
  private:
    std::string name;
    std::vector<std::string> items;
    Passage* northPassage;
    Passage* southPassage;
    Passage* eastPassage;
    Passage* westPassage;

  public:
    Room();
    Room(std::string name, Passage* north, Passage* south, Passage* east, Passage* west);

    std::string GetName(); // Get room name

    // Get passage base on direction
    Passage* GetNorthPassage();
    Passage* GetSouthPassage();
    Passage* GetEastPassage();
    Passage* GetWestPassage();

    void AddItem(std::string item); // Add an item to the room
    std::string AcquireNextItem(); // Get the next item in the room
    int ListItems(); // List the items in the room
};

#endif
