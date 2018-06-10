/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef LinkedDungeon_hpp
#define LinkedDungeon_hpp

#include "ItemRoom.hpp"
#include "UseItemRoom.hpp"
#include "TalkRoom.hpp"
#include <string>
using std::string;
#include <vector>
using std::vector;

enum direction {NORTH, SOUTH, EAST, WEST};

class LinkedDungeon
{
private:
    Space* drawBridge;
    Space* gateHouse;
    Space* courtyard;
    Space* stables;
    Space* keep;
    Space* dungeon;
    Space* throneRoom;
    Space* currentLocation;
    int turnsLeft;
    
public:
    LinkedDungeon();
    ~LinkedDungeon();
    void move(direction dir);
    bool roomExists(direction dir);
    void connectRooms(Space* baseRoom, Space* n, Space* e, Space* w, Space* s);
    void transitionText();
    
    
    Space* getCurrentLocation();
    void setCurrentLocation(Space* room);
    int getTurnsLeft();
    void setTurnsLeft(int turnsIn);
    void useTurn();
    
};

#endif /* LinkedDungeon_hpp */
