#ifndef player_h
#define player_h

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "item.h"

// This program should handle the functions regarding the player's character

// -------
// Structs
// -------

typedef struct player{
    char ID[5];
    int currentHP;
    unsigned int maxHP;
    int DEX;
    int DMG;
    int DEF;
    // room* room;
    int posX;
    int posY;
    item** items;
    int noItems;
} player;

// ---------
// Functions
// ---------

// This function initiates the player for the current session
// Variables to be added: pointer to current room, and int coordinates in that room.
player* createPlayer(item**);

// This function equips an item to the player, adding it to the list of the player's items and increasing the player's stats
void equipItem(item*, player*);

// This function will free the pointer from memory
void freePlayer(player*);

// This function deals damage to a player equal to the integer argument. The function then returns the current hit points of the player.
int damagePlayer(player*, int);


#endif