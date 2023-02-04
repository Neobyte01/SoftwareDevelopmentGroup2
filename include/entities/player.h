#pragma once
#include "entities/entity.h"

// Player library.
// Contains the player and functions for setting it up.

Entity *player;

// Setup the player object.
// Will reset the player and therefore delete previous player.
void setupPlayer();