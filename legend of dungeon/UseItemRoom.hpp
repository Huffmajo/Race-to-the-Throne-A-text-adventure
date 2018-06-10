/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef UseItemRoom_hpp
#define UseItemRoom_hpp

#include "Space.hpp"

class UseItemRoom: public Space
{
private:
    
        
public:
    UseItemRoom();
    ~UseItemRoom();
    void useItem(item activeItem, Player* p);
    void talk(Player* p);
    void pickUp(Player* p);
    //void examineRoom();
    
    
    
};

#endif /* UseItemRoom_hpp */
