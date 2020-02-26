#include <algorithm>

#include "player.hpp"

/**
 * Defalut Constructor.
 *
 * TODO: Start Player in top Left Corner
 */
Player::Player()
{
  row = 0;
  col = 0;
  moves = 0;
}

/**
 * Get the Players x position
 */
int Player::GetRow()
{
  return this->row;
}

/**
 * Get the Players y position
 */
int Player::GetCol()
{
  return this->col;
}

/**
 * Set the Players position
 */
void Player::SetPosition(int row, int col)
{
  this->row = row;
  this->col = col;
  IncrementMoves();
}

/**
 * Add Items in the room to Player's Inventory
 */
void Player::AddItem(std::string item)
{
  this->items.push_back(item);
}

/**
 * Checks if the Player has an item in their inventory
 */
bool Player::HasItem(std::string item)
{
  for(std::string inven_item : this->items)
  {
    if(inven_item == item)
    {
      return true;
    }
  }
  return false;
}

/**
 * Use a player item and then destroy that item
 */
void Player::UseItem(std::string item)
{
  if(HasItem(item))
  {
    this->items.erase(std::remove(this->items.begin(), this->items.end(), item ), this->items.end());
  }
}

/*
 * Get players move count
 */
int Player::GetMoveCount()
{
  return this->moves;
}

/*
 * Increment player moves
 */
void Player::IncrementMoves()
{
  this->moves++;
}

















