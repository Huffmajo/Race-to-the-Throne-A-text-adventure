/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "ItemRoom.hpp"

ItemRoom::ItemRoom():Space()
{
    setBlocked(false);
    setTalkString("You don't see anyone to talk to, so you talk to yourself.\n\n");
    setUseItemString("You get the feeling this isn't the place to use it.\n\n");
    setPickUpString("pickup item string");
}

ItemRoom::~ItemRoom()
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
void ItemRoom::useItem(item activeItem, Player* p)
{
    cout << getUseItemString();
}

/*********************************************************************
 ** pickUp():
 ** Prints a string of the player trying to pick up something in the room
 *********************************************************************/
void ItemRoom::talk(Player* p)
{
    cout << getTalkString();
}

/*********************************************************************
 ** pickUp(Player* p):
 ** Accepts a pointer to the player object. Prints a string of the
 ** player trying to pick up something in the room. If an object exists
 ** to be picked up it is removed from the room and added to the inventory,
 ** otherwise text is displayed telling there is nothing to pick up
 *********************************************************************/
void ItemRoom::pickUp(Player* p)
{
    //if there is an item in the room
    if (getItemInRoom() != EMPTY)
    {
        //display pick up text
        cout << getPickUpString();
        
        //add item to inventory
        p->addItem(getItemInRoom());
        
        //remove item from room
        setItemInRoom(EMPTY);
        
        //set pickup string to show there are no more item in here
        setPickUpString("There is nothing else of use in this room\n\n");
        
        //set room description to reflect missing item
        string room = getRoomName();
        
        //for gatehouse
        if (room == "gatehouse")
        {
            setTalkString("You give the guard a nudge. He snorts and mumbles something about slaying dragons. He's not waking up anytime soon.\n\n");
            setDescription("The guard is still fast asleep with his head on the desk. He appears to be snoring and murmuring something about fair maidens in his sleep. To the WEST lies the castle's drawbridge.\n\n");
        }
        
        //for stables
        else if (room == "stables")
        {
            setDescription("Hay is spread out throughout the stables with a single horse in the corner lazily chewing oats from a feed bag. You spy something else among the hay. Wait, it's just more hay. To the EAST lies the courtyard.\n\n");
        }
        
        //for dungeon
        else
        {
            setDescription("The floor is damp and the room smells of mildew. There is a single open cell with a skeleton lying in the corner. The skeleton is missing a leg bone, but he doesn't seem too distraught over it. The stairwell to the WEST leads to the keep.\n\n");
        }
    }
    
    else
    {
        cout << getPickUpString();
    }
}
