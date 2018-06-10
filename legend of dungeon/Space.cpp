/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/
#include "Space.hpp"

Space::Space()
{
    setBlocked(false);
    setItemInRoom(EMPTY);
    setTalkString("You don't see anyone to talk to, so you talk to yourself.\n\n");
    setUseItemString("You get the feeling this isn't the place to use it.\n\n");
    setPickUpString("pickup item string");
}

Space::~Space()
{
    
}

//getters and setters
string Space::getDescription()
{
    return description;
}

void Space::setDescription(string stringIn)
{
    description = stringIn;
}

string Space::getRoomName()
{
    return roomName;
}

void Space::setRoomName(string stringIn)
{
    roomName = stringIn;
}

string Space::getExamine()
{
    return examine;
}

void Space::setExamine(string stringIn)
{
    examine = stringIn;
}

string Space::getTalkString()
{
    return talkString;
}

void Space::setTalkString(string stringIn)
{
    talkString = stringIn;
}

string Space::getUseItemString()
{
    return useItemString;
}

void Space::setUseItemString(string stringIn)
{
    useItemString = stringIn;
}

string Space::getPickUpString()
{
    return pickUpString;
}

void Space::setPickUpString(string stringIn)
{
    pickUpString = stringIn;
}

bool Space::getBlocked()
{
    return blocked;
}

void Space::setBlocked(bool isblocked)
{
    blocked = isblocked;
}

string Space::getBlockedString()
{
    return blockedString;
}

void Space::setBlockedString(string stringIn)
{
    blockedString = stringIn;
}

item Space::getItemInRoom()
{
    return itemInRoom;
}

void Space::setItemInRoom(item targetItem)
{
    itemInRoom = targetItem;
}

item Space::getItemNeeded()
{
    return neededItem;
}

void Space::setItemNeeded(item targetItem)
{
    neededItem = targetItem;
}
