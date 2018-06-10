/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#include "utils.hpp"

/*********************************************************************
 ** intValidation:
 ** Checks cin if input is an integer within the minimum and maximum
 ** values. Returns the integer if it is acceptable, lists prompt and
 ** asks again if input is invalid.
 *********************************************************************/
int intValidation(int min, int max, string prompt)
{
    string input;
    int validInt;
    
    while (true)
    {
        cout << prompt;
        
        //get inut from user
        getline(cin, input);
        
        stringstream ss(input);
        
        //if input has an int and nothing after that
        if (ss >> validInt && !(ss >> input))
        {
            //check if within bounds
            if (validInt > max || validInt < min)
            {
                cout << "Invalid int. Must be between "
                << min << " and " << max << ".\n";
            }
            
            //if valid integer
            else
            {
                return validInt;
            }
        }
        
        //if noninteger value entered
        else
        {
            cout << "Invalid input. Please enter an integer.\n";
        }
        
    }
}

/*********************************************************************
 ** menu:
 ** Allows the user to choose actions for their character.
 *********************************************************************/
int menu()
{
    string prompts[] = {
        "Welcome to Race to the Throne!\n\n",
        "Your uncle is the reigning king of Londor. But in his old age, he knows he must choose a successor before his death. Without any children of his own, he has challenged all of his nephews and nieces to a race to his throne room. The first one there claims right to the throne and the title of ruler of Londor. You've just arrived at the outside of his castle and just need to find the throne room and talk to your uncle.\n\n",
        "Choose your action:\n1. Move\n2. Use item\n3. Pick up item\n4. Talk\n5. Quit game\n\n",
    };
    
    cout << prompts[0];
    cout << prompts[1];
    
    //create dungeon and player objects
    LinkedDungeon* dungeon = new LinkedDungeon;
    Player* player = new Player;
    
    //keep playing until turns are up
    while (dungeon->getTurnsLeft() > 0)
    {
        //Choose player 1 character
        switch(intValidation(1, 5, prompts[2]))
        {
                //move rooms
            case 1:
            {
                moveMenu(dungeon);
                break;
            }
                
                //use item
            case 2:
            {
                itemMenu(dungeon, player);
                break;
            }
                
                //pick up item
            case 3:
            {
                dungeon->getCurrentLocation()->pickUp(player);
                break;
            }
                
                //talk
            case 4:
            {
                dungeon->getCurrentLocation()->talk(player);
                break;
            }
                
                //quit game
            case 5:
            {
                delete dungeon;
                delete player;
                return 0;
                break;
            }
                
            default:
                break;
        }
        
        if (player->getGameWin())
        {
            delete dungeon;
            delete player;
            return 2;
        }
    }
    delete dungeon;
    delete player;
    return 1;
}

/*********************************************************************
 ** moveMenu:
 ** Allows the user to choose which direction to move.
 *********************************************************************/
int moveMenu(LinkedDungeon* d)
{
    string dirChoices = "Choose which direction to move:\n1. North\n2. East\n3. West\n4. South\n\n";
    switch(intValidation(1, 4, dirChoices))
    {
            //go north
        case 1:
            d->move(NORTH);
            break;
            //go east
        case 2:
            d->move(EAST);
            break;
            //go west
        case 3:
            d->move(WEST);
            break;
            //go south
        case 4:
            d->move(SOUTH);
            break;
            
        default:
            break;
    }
    
    return 0;
}

/*********************************************************************
 ** itemMenu:
 ** Allows the user to choose if they want to use their item.
 *********************************************************************/
int itemMenu(LinkedDungeon* d, Player* p)
{
    string promptItem = "Use that item?\n1. Yes\n2. No.\n\n";
    
    if (p->emptyInventroy())
    {
        cout << "Your inventory is empty.\n\n";
    }
    
    else
    {
        string itemName;
        
        switch(p->getItem())
        {
            case BONE:
                itemName = "bone";
                break;
                
            case KEY:
                itemName = "key";
                break;
                
            case CRANK:
                itemName = "crank";
                break;
                
            case EMPTY:
                itemName = "EMPTY";
                break;
        }
        
        cout << "You're holding a " << itemName << ".\n";
        
        switch(intValidation(1, 2, promptItem))
        {
            case 1:
                d->getCurrentLocation()->useItem(p->getItem(), p);
                break;
                
            case 2:
                break;
                
            default:
                cout << "Something went wrong\n\n";
                break;
        }
    }
    
    
    return 0;
}
