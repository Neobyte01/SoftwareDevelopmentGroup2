#ifndef item_h
#define item_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// This program should handle the functions regarding the player's character

// -------
// Structs
// -------

typedef struct item
{
    char name[20];
    unsigned int type;
    int bonus;
    bool usable;
    bool consumable;
} item;

// ---------
// Functions
// ---------

// This function contains the logic to use and enter the item menu
void commandItemMenu(item**);

// This function prints the item menu
void printItemMenu(item**, int);

// This function prints info about a specific item from a file
void printItem(item*);

#endif