/*********************************************************************
 ** Program name: Race to the Throne
 ** Author: Joel Huffman
 ** Date: 03/7/18
 ** Description: A text-based adventure game
 *********************************************************************/

#ifndef utils_hpp
#define utils_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedDungeon.hpp"
using std::cin;
using std::cout;
using std::string;
using std::stringstream;

int intValidation(int min, int max, string prompt);
int menu();
int moveMenu(LinkedDungeon* d);
int itemMenu(LinkedDungeon* d, Player* p);

#endif /* utils_hpp */
