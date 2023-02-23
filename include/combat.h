#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "entities/entity.h"

// Everything that has to do with combat between player and monster is handled here

// Call this function to enter combat, pass the player and the concerned monster
// Combat should initiate when the player and the monster inhabit the same coordinates, requires implementation of grid system
// testFlag-parameter streamlines ability to perform unit tests (0 - 4, only 0 & 1 currently implemented)
// Return True indicates that player survived, False indicates death
bool combat(Entity* player, Entity* monster, int testFlag);  