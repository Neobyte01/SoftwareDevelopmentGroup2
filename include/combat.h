#ifndef combat_h
#define combat_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "entity.h"

// Everything that has to do with combat between player and monster is handled here

// ---------
// Functions
// ---------

// Call this function to enter combat, pass the player and the concerned monster
// Combat should initiate when the player and the monster inhabit the same coordinates, requires implementation of grid system
bool combat(entity* player, entity* monster);  // True indicates that player survived, false indicates death

#endif