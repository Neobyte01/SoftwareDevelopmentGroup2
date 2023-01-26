#ifndef entity_h
#define entity_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

// This program should handle the functions regarding entities.
// Entities can be one of the following:
// - Player Characters
// - Monsters
// - Items

// -------
// Structs
// -------

typedef struct entity{
    char name[10];
    char type[5];
    char behaviour[5];
    char description[300];
    int currentHP;
    unsigned int maxHP;
    int DEX;
    int DMG;
    int DEF;
    // room* room;
    int posX;
    int posY;
    int noItems;
    entity** items;
} entity;

// ---------
// Functions
// ---------

// This function initiates an entity for the current session
// Variables to be added: pointer to current room, and int coordinates in that room.
// Arguments are: name, Max Hit Points, Damage, Defense, Dexterity
entity* createEntity(char[10], int, int, int, int);

// This function will free the entity pointer from memory
void freeEntity(entity*);

// This function contains the logic to use and enter the item menu
void commandItemMenu(entity**);

// This function prints the item menu, the integer being the number of items
void printItemMenu(entity**, int);

// This function prints info about a specific item from a file
void printEntity(entity*);

#endif