#ifndef entity_h
#define entity_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <action.h>
#include "room.h"

// This program should handle the functions regarding entities.
// Entities can be one of the following:
// - Player Characters
// - Monsters
// - Items

// ---------------
// Structs & Enums
// ---------------

enum entityType {

    Player,
    Monster,
    Item,

};

enum entityBehaviour {

    none,
    aggresive,
    stalking,
    scared,
    
};

typedef struct entity{
    char name[10]; // Name of the entity
    enum entityType type; 
    enum entityBehaviour behaviour;
    char description[300]; 
    int currentHP;
    unsigned int maxHP;
    int DMG;
    int DEF;
    int DEX;
    struct entity** attached; // Attached entities (Items)
    int num; // Number of attached entities
    struct roomStructure* room;
    enum Action *last_action;
    // int **pos;
} entity;

// ---------
// Functions
// ---------

// This function initiates an entity for the current session
// Variables to be added: pointer to current room, and current position in that room.
// Arguments are: Name, Type, Behaviour
entity* createEntity(char[10], enum entityType, enum entityBehaviour);

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