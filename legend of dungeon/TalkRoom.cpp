/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "TalkRoom.hpp"

TalkRoom::TalkRoom():Space()
{
    setBlocked(false);
    setTalkString("You don't see anyone to talk to, so you talk to yourself.\n\n");
    setUseItemString("You get the feeling this isn't the place to use it.\n\n");
    setPickUpString("You don't see anything worth picking up.\n\n");
}

TalkRoom::~TalkRoom()
{
    top = nullptr;
    left = nullptr;
    right = nullptr;
    bottom = nullptr;
}

/*********************************************************************
 ** pickUp():
 ** Prints a string of the player trying to pick up something in the room
 *********************************************************************/
void TalkRoom::useItem(item activeItem, Player* p)
{
    cout << getUseItemString();
}

/*********************************************************************
 ** pickUp():
 ** Prints a string of the player trying to pick up something in the room
 *********************************************************************/
void TalkRoom::talk(Player* p)
{
    cout << getTalkString();
    
    //win the game!
    p->setGameWin(true);
}

/*********************************************************************
 ** pickUp(Player* p):
 ** Accepts a pointer to the player object. Prints a string of the
 ** player trying to pick up something in the room.
 *********************************************************************/
void TalkRoom::pickUp(Player* p)
{
        //display pick up text
        cout << getPickUpString();
}
