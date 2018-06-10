/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef Player_hpp
#define Player_hpp

//#include "LinkedDungeon.hpp"
#include <vector>
using std::vector;

enum item {CRANK, KEY, BONE, EMPTY};

class Player
{
private:
    vector<item> inventory;
    bool gameWin;
    
public:
    Player();
    ~Player();
    void addItem(item i);
    void removeItem(item i);
    item getItem();
    bool emptyInventroy();
    bool getGameWin();
    void setGameWin(bool winIn);
    
};

#endif /* Player_hpp */
