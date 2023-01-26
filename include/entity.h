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
    char name[10]; // Name of the entity
    char type; // Type of entity, P for player, M for monster, I for item
    char behaviour[5]; // Behaviour of the entity, will only matter for monsters
    char description[300]; 
    int currentHP;
    unsigned int maxHP;
    int DMG;
    int DEF;
    int DEX;
    struct entity** attached; // Attached entities (Items)
    int num; // Number of attached entities
    // room* room;
    // int **pos;
} entity;

// ---------
// Functions
// ---------

// This function initiates an entity for the current session
// Variables to be added: pointer to current room, and current position in that room.
// Arguments are: Name, Type, Behaviour, Max Hit Points (& Current), Damage, Defense, Dexterity
entity* createEntity(char[10], char[5], char, int, int, int, int);

// This function will free the entity pointer from memory
void freeEntity(entity*);

// This function clears the console, then prints the description of an entity
// To return to previous state, the user must press any button
void printDesc(entity*);

// This function will add an entity to another entity's list of attached entities.
// The second entity is attached to the first entity (called primary).
// This will add stats from the secondary entity to the primary entity.
// This can used to give stat bonuses, or to increase the currentHP of the primary entity.
void attachEntity(entity*, entity*);

// This function contains the logic to use and enter the item menu
void commandItemMenu(entity**);

// This function prints the item menu, the integer being the number of items
void printItemMenu(entity**, int);

#endif