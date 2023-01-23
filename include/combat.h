#ifndef combat_h
#define combat_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "player.h"

// Everything that has to do with combat between player and monster is handled here

// TEMP, remove after monster implementation (Currently just a copy of player)
typedef struct monster 
{
    char ID[5];
    int currentHP;
    unsigned int maxHP;
    int DEX;
    int DMG;
    int DEF;
    // room* room;
    int posX;
    int posY;
} monster;
// END of TEMP

// ---------
// Functions
// ---------

// Call this function to enter combat, pass the player and the concerned monster
// Combat should initiate when the player and the monster inhabit the same coordinates, requires implementation of grid system
bool combat(player *player, monster *monster);  // True indicates that player survived, false indicates death

#endif