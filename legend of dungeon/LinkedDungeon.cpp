/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "LinkedDungeon.hpp"
#include <iostream>
using std::cout;

/*********************************************************************
 ** LinkedDungeon():
 ** Creates and connects all the rooms in the dungeon
 *********************************************************************/
LinkedDungeon::LinkedDungeon()
{
    //create rooms for dungeon
    drawBridge = new UseItemRoom;
    gateHouse = new ItemRoom;
    courtyard = new UseItemRoom;
    stables = new ItemRoom;
    keep = new UseItemRoom;
    dungeon = new ItemRoom;
    throneRoom = new TalkRoom;
    
    string roomNames[] = {
        "drawbridge",
        "gatehouse",
        "courtyard",
        "stables",
        "keep",
        "dungeon",
        "throne room"
    };
    
    string roomDescriptions[] = {
        "You stand outside the castle on it's lowered wooden drawbridge. The path to the NORTH leads to the courtyard. To the EAST lies a small gatehouse.\n\n",
        "There is a single desk and chair where a portly guard sits with his head on the desk. He appears to be snoring and drooling a little. Something metal sits on the desk beside he head. To the WEST lies the castle's drawbridge.\n\n",
        "There are a few stacks of hay and some wooden crates. To the NORTH is a large oak door. To the WEST are the castle stables. To the SOUTH lies the drawbridge.\n\n",
        "Hay is spread out throughout the stables with a single horse in the corner lazily chewing oats from a feed bag. You spy something glinting in a hay pile. To the EAST lies the courtyard.\n\n",
        "The walls are made of heavy well-cut stones. Thick tapestries showing royalty hang from the torch-lit walls. The doorway to the NORTH is leads to the throne room. To the EAST lies a stairway down to the dungeon. The courtyard is to the SOUTH.\n\n",
        "The floor is damp and the room smells of mildew. There is a single open cell with a skeleton lying in the corner. The stairwell to the WEST leads to the keep.\n\n",
        "A plush red carpet leads up stairs to a towering gold throne. Atop the throne sits an elderly, wrinkled man dressed in gold linens, the old king. To the SOUTH lies the keep.\n\n"
    };
    
    string blockedTexts[] = {
        "The portcullis is lowered and blocking your way into the courtyard. A large mechanism to the left looks like it can be used to raise it but it appears to be missing the hand crank.\n\n",
        "A large, oak door with a robust metal lock blocks your way into the castle's keep. There is a shield engraved into the lock.\n\n",
        "Two large beasts with sharp claws gnash their teeth at you. Their hulking bodies almost completely block the doorway behind them.\n\n"
    };
    
    string pickUpTexts[] = {
        "You gingerly grab the CRANK off the table, careful not to wake the guard. Though it seems that a thunderstorm wouldn't disturb his slumber.\n\n",
        "You rifle through the hay until you feel something metallic. You pull out a small KEY with a shield engraving and shove it into your satchel.\n\n",
        "You slowly inch towards the skeleton and hesitently pick up a BONE. You think it might be a femur, but you didn't really go to ye olde medical school.\n\n"
    };
    
    string useItemTexts[] = {
        "You insert the crank into the winch and crank like thine life depended on it. The portcullis slowly rises until it reaches the top and stops with a satisfying click. The path into the courtyard is now clear.\n\n",
        "You thrust the key into the lock and twist it until it clicks, allowing the door to easily open. \"Huzzah!\" you exclaim a little too excitedly.\n\n",
        "You hurl the bone (you're pretty confident it's a femur now) towards the beasts. Both lunge for it, but the beast on the left snatches it out of the air nearly breaking it in two with it's powerful jaws. The two creatures begin to fight with one another over the bone leaving the doorway ahead unguarded.\n\n"
    };
    
    string talkTexts[] = {
        "You try to start up a conversation with the drawbridge, but it doesn't answer. Probably because it's a drawbridge.\n\n",
        "\"Umm hello\" you say trying to rouse the guard from his heavy slumber. He only begins to snore louder. You notice a CRANK on his desk.\n\n",
        "You say \"Boy, I should probably get to the king instead of talking to myself.\"\n\n",
        "\"How about this weather?\" you say to the horse. He doesn't even look up from his oats. What a rude horse!\n\n",
        "\"Good doggies\" you say to the beasts. They snarl and growl in return. You're pretty sure they aren't good doggies.\n\n",
        "\"I've got a bone to pick with you\" you say to the skeleton. He is unscathed by your bad joke.\n\n",
        "\"Finally a worthy heir to the throne has arrived to claim ownership of the kingdom.\" the old king bellows. Come sit upon your throne my liege!\n\n"
    };
    
    //setup drawbridge
    drawBridge->setDescription(roomDescriptions[0]);
    drawBridge->setRoomName(roomNames[0]);
    drawBridge->setBlockedString(blockedTexts[0]);
    drawBridge->setUseItemString(useItemTexts[0]);
    drawBridge->setItemNeeded(CRANK);
    drawBridge->setTalkString(talkTexts[0]);
    connectRooms(drawBridge, courtyard, gateHouse, nullptr, nullptr);
    
    //setup gateHouse
    gateHouse->setDescription(roomDescriptions[1]);
    gateHouse->setRoomName(roomNames[1]);
    gateHouse->setItemInRoom(CRANK);
    gateHouse->setPickUpString(pickUpTexts[0]);
    gateHouse->setTalkString(talkTexts[1]);
    connectRooms(gateHouse, nullptr, nullptr, drawBridge, nullptr);
    
    
    //setup courtyard
    courtyard->setDescription(roomDescriptions[2]);
    courtyard->setRoomName(roomNames[2]);
    courtyard->setBlockedString(blockedTexts[1]);
    courtyard->setUseItemString(useItemTexts[1]);
    courtyard->setItemNeeded(KEY);
    courtyard->setTalkString(talkTexts[2]);
    connectRooms(courtyard, keep, nullptr, stables, drawBridge);
    
    //setup stables
    stables->setDescription(roomDescriptions[3]);
    stables->setRoomName(roomNames[3]);
    stables->setItemInRoom(KEY);
    stables->setPickUpString(pickUpTexts[1]);
    stables->setTalkString(talkTexts[3]);
    connectRooms(stables, nullptr, courtyard, nullptr, nullptr);
    
    //setup keep
    keep->setDescription(roomDescriptions[4]);
    keep->setRoomName(roomNames[4]);
    keep->setBlockedString(blockedTexts[2]);
    keep->setUseItemString(useItemTexts[2]);
    keep->setItemNeeded(BONE);
    keep->setTalkString(talkTexts[4]);
    connectRooms(keep, throneRoom, dungeon, nullptr, courtyard);
    
    //setup dungeon
    dungeon->setDescription(roomDescriptions[5]);
    dungeon->setRoomName(roomNames[5]);
    dungeon->setItemInRoom(BONE);
    dungeon->setPickUpString(pickUpTexts[2]);
    dungeon->setTalkString(talkTexts[5]);
    connectRooms(dungeon, nullptr, nullptr, keep, nullptr);
    
    //setup throne room
    throneRoom->setDescription(roomDescriptions[6]);
    throneRoom->setRoomName(roomNames[6]);
    throneRoom->setTalkString(talkTexts[6]);
    connectRooms(throneRoom, nullptr, nullptr, nullptr, keep);
    
    //start player in gateHouse
    currentLocation = gateHouse;
    
    //start timer
    turnsLeft = 26;
    
    //move to the drawBridge to start
    move(WEST);
}

/*********************************************************************
 ** ~LinkedDungeon():
 ** Frees all the allocated memory
 *********************************************************************/
LinkedDungeon::~LinkedDungeon()
{
    delete drawBridge;
    delete gateHouse;
    delete courtyard;
    delete stables;
    delete keep;
    delete dungeon;
    delete throneRoom;
    drawBridge = nullptr;
    gateHouse = nullptr;
    courtyard = nullptr;
    stables = nullptr;
    keep = nullptr;
    dungeon = nullptr;
    throneRoom = nullptr;
}

/*********************************************************************
 ** move(direction dir):
 ** Takes a direction. Checks if player can move in that direction. If
 ** a room exists there, the player moves to that room, otherwise they
 ** are given a reason why they can't move there.
 *********************************************************************/
void LinkedDungeon::move(direction dir)
{
    //check if room is not null
    if (roomExists(dir))
    {
        switch (dir)
        {
            case NORTH:
                if (currentLocation->getBlocked())
                {
                    cout << currentLocation->getBlockedString();
                }
                
                else
                {
                    useTurn();
                    currentLocation = currentLocation->top;
                    transitionText();
                }
                break;
                
            case SOUTH:
                useTurn();
                currentLocation = currentLocation->bottom;
                transitionText();
                break;
                
            case EAST:
                useTurn();
                currentLocation = currentLocation->right;
                transitionText();
                break;
                
            case WEST:
                useTurn();
                currentLocation = currentLocation->left;
                transitionText();
                break;
                
            default:
                useTurn();
                currentLocation = currentLocation->top;
                transitionText();
                break;
        }
    }
    
    //if can't move that way
    else
    {
        cout << "You can't go that way\n\n";
    }
}

/*********************************************************************
 ** roomExists(direction dir):
 ** Takes a direction. Checks if the space in that direction contains
 ** a room. Returns true if there is a room or false if no room exists
 *********************************************************************/
bool LinkedDungeon::roomExists(direction dir)
{
    bool roomIsThere = false;
    
    //check if can move north
    if (dir == NORTH)
    {
        if (currentLocation->top != nullptr)
        {
            roomIsThere = true;
        }
    }
    
    //check if can move east
    else if (dir == EAST)
    {
        if (currentLocation->right != nullptr)
        {
            roomIsThere = true;
        }
    }
    
    //check if can move south
    else if (dir == SOUTH)
    {
        if (currentLocation->bottom != nullptr)
        {
            roomIsThere = true;
        }
    }
    
    //check if an move west
    else if (dir == WEST)
    {
        if (currentLocation->left != nullptr)
        {
            roomIsThere = true;
        }
    }
    return roomIsThere;
}

/*********************************************************************
 ** connectRooms(Space* baseRoom, Space* n, Space* e, Space* w, Space* s):
 ** Accepts a pointer to a baseRoom and 4 more pointers to rooms, one for
 ** each direction. Connects the baseRoom to the 4 other rooms in the order
 ** of north/top, east/right, west/left, south/bottom.
 *********************************************************************/
void LinkedDungeon::connectRooms(Space* baseRoom, Space* n, Space* e, Space* w, Space* s)
{
    baseRoom->top = n;
    baseRoom->right = e;
    baseRoom->left = w;
    baseRoom->bottom = s;
}

/*********************************************************************
 ** transitionText():
 ** Prints information about the new room the character is entering
 *********************************************************************/
void LinkedDungeon::transitionText()
{
    cout << "You are now entering the " << currentLocation->getRoomName() << ".\n";
    cout << currentLocation->getDescription();
}

/*********************************************************************
 ** useTurn():
 ** lowers turnsLeft by 1 and prints the number of remaining turns
 *********************************************************************/
void LinkedDungeon::useTurn()
{
    turnsLeft--;
    string spaces = "";
    if (turnsLeft < 10)
    {
        spaces = " ";
    }
    cout << "+------------------+\n";
    cout << "|" << spaces << turnsLeft << " turns remaining|\n";
    cout << "+------------------+\n";
}

Space* LinkedDungeon::getCurrentLocation()
{
    return currentLocation;
}

void LinkedDungeon::setCurrentLocation(Space* room)
{
    currentLocation = room;
}

int LinkedDungeon::getTurnsLeft()
{
    return turnsLeft;
}

void LinkedDungeon::setTurnsLeft(int turnsIn)
{
    turnsLeft = turnsIn;
}


