/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/
#ifndef Space_hpp
#define Space_hpp

#include "Player.hpp"
#include <string>
using std::string;
#include <iostream>
using std::cout;

class Space
{
protected:
    string roomName;
    string description;
    string examine;
    string talkString;
    string useItemString;
    string pickUpString;
    string blockedString;
    bool blocked;
    item itemInRoom;
    item neededItem;
    
public:
    Space* top;
    Space* left;
    Space* right;
    Space* bottom;
    
    Space();
    virtual ~Space();
    
    string getDescription();
    void setDescription(string stringIn);
    string getRoomName();
    void setRoomName(string stringIn);
    string getExamine();
    void setExamine(string stringIn);
    string getTalkString();
    void setTalkString(string stringIn);
    string getUseItemString();
    void setUseItemString(string stringIn);
    string getPickUpString();
    void setPickUpString(string stringIn);
    bool getBlocked();
    void setBlocked(bool isblocked);
    string getBlockedString();
    void setBlockedString(string stringIn);
    item getItemInRoom();
    void setItemInRoom(item targetItem);
    item getItemNeeded();
    void setItemNeeded(item targetItem);
    
    virtual void useItem(item activeItem, Player* p)=0;
    virtual void talk(Player* p)=0;
    virtual void pickUp(Player* p)=0;
    //virtual void examineRoom()=0;
    
};
#endif /* Space_hpp */
