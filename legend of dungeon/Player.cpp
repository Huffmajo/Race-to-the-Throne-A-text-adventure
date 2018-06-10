/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "Player.hpp"

Player:: Player()
{
    gameWin = false;
}

Player::~Player()
{
    
}

/*********************************************************************
 ** addItem(item i):
 ** Accepts an item variable and adds it to the inventory
 *********************************************************************/
void Player::addItem(item i)
{
    inventory.push_back(i);
}

/*********************************************************************
 ** removeItem(item i):
 ** Accepts an item variable and removes that item from the inventory
 *********************************************************************/
void Player::removeItem(item i)
{
    inventory.clear();
}

/*********************************************************************
 ** getItem():
 ** Returns the item the player is holding
 *********************************************************************/
item Player::getItem()
{
    return inventory.front();
}

/*********************************************************************
 ** emptyInventroy():
 ** Returns true if inventory is empty, returns false otherwise
 *********************************************************************/
bool Player::emptyInventroy()
{
    if (inventory.empty())
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

bool Player::getGameWin()
{
    return gameWin;
}

void Player::setGameWin(bool winIn)
{
    gameWin = winIn;
}
