/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "UseItemRoom.hpp"

UseItemRoom::UseItemRoom():Space()
{
    setBlocked(true);
    setTalkString("You don't see anyone to talk to, so you talk to yourself.\n\n");
    setUseItemString("You get the feeling this isn't the place to use it.\n\n");
    setPickUpString("You don't see anything worth picking up.\n\n");
}


UseItemRoom::~UseItemRoom()
{
    top = nullptr;
    left = nullptr;
    right = nullptr;
    bottom = nullptr;
}

/*********************************************************************
 ** useItem(item activeItem):
 ** Accepts an item variable. Attempts to use that item in this room.
 ** If it is successful, prints a string describing it, removes item
 ** from inventory and opens path to next room. Otherwise test describing
 ** the failure is printed.
 *********************************************************************/
void UseItemRoom::useItem(item activeItem, Player* p)
{
    if (activeItem == neededItem)
    {
        cout << getUseItemString();
        
        //remove item from inventory
        p->removeItem(activeItem);
        
        //open path to next room
        setBlocked(false);
        
        //change description text
    }
    
    else
    {
        cout << "That item isn't needed here\n";
    }
}

/*********************************************************************
 ** talk():
 ** Prints a string of the player trying to talk to someone in that room
 *********************************************************************/
void UseItemRoom::talk(Player* p)
{
    cout << getTalkString();
}

/*********************************************************************
 ** pickUp():
 ** Prints a string of the player trying to pick up something in the room
 *********************************************************************/
void UseItemRoom::pickUp(Player* p)
{
    cout << getPickUpString();
}


/*********************************************************************
 ** examineRoom():
 ** Prints string of examination of the current room
 *********************************************************************/
/*
void UseItemRoom::examineRoom()
{
    cout << getExamine();
}
*/



