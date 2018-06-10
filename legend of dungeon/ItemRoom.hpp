/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef ItemRoom_hpp
#define ItemRoom_hpp

#include "Space.hpp"

class ItemRoom: public Space
{
public:
    ItemRoom();
    ~ItemRoom();
    void useItem(item activeItem, Player* p);
    void talk(Player* p);
    void pickUp(Player* p);
    
};

#endif /* ItemRoom_hpp */
