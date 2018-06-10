/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/
#include <iostream>
#include "utils.hpp"
using std::cout;

int main() {
    
    int endGameStatus = menu();
    
    switch(endGameStatus)
    {
            //quit the game
        case 0:
            cout << "Thank you for playing Race to the Throne.\n";
            break;
            
            //run out of turns
        case 1:
            cout << "+---------+\n";
            cout << "|GAME OVER|\n";
            cout << "+---------+\n";
            cout << "You were too slow to get to the throne. By the time you arrived at the throne room, your eldest sister had already been crowned ruler.\n";
            cout << "Thank you for playing Race to the Throne.\n";
            break;
            
            //won the game
        case 2:
            cout << "+----------------+\n";
            cout << "|A WINNER IS YOU!|\n";
            cout << "+----------------+\n";
            cout << "Thank you for playing Race to the Throne.\n";
            break;
    }
    
    return 0;
}
