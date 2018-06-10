/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef TalkRoom_hpp
#define TalkRoom_hpp

#include "Space.hpp"

class TalkRoom: public Space
{
public:
    TalkRoom();
    ~TalkRoom();
    void useItem(item activeItem, Player* p);
    void talk(Player* p);
    void pickUp(Player* p);
    
};
#endif /* TalkRoom_hpp */
