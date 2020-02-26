#include "passage.hpp"

/**
 * Default Passage Constructor
 */
Passage::Passage()
{
  isOpen = false;
  key = "";
}

/**
 * Constructor for passages that don't require a key.
 * Not a door
 */
Passage::Passage(bool isOpen)
{
  this->isOpen = isOpen;
  key = "";
}

/**
 * Constructor for Doors
 */
Passage::Passage(bool isOpen, std::string key)
{
  this->isOpen = isOpen;
  this->key = key;
}

/**
 * Checks if the passage is currently open
 */
bool Passage::IsOpen()
{
  // If it's open it's good
  if(this->isOpen == true)
  {
    return true;
  }

  // If it requires a key and the player doesn't have it
  if(RequiresKey() && (GetRequiredKey() != this->key))
  {
    return false;
  }

  // This is a wall, no key not open
  if(!RequiresKey() && (this->isOpen == false))
  {
    return false;
  }

  // If the player has the key and the door is closed
  if(RequiresKey() && (GetRequiredKey() == this->key) && (this->isOpen == false))
  {
    return false;
  }
  return false;
}

/**
 * Checks to see if the door requires a key.
 */
bool Passage::RequiresKey()
{
  // Check if required key is empty
  if (GetRequiredKey() != "")
  {
    return true;
  }
  return false;
}

/**
 * Gets the required key to open a door
 */
std::string Passage::GetRequiredKey()
{
  return this->key;
}

/**
 * Opensa door if the key is in inventory
 */
void Passage::Open()
{
  this->key = "";
  this->isOpen = true;
}













