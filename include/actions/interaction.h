#pragma once
#include "entities/entity.h"
#include "map/map.h"

// Interaction library
// Systems for interacting with the environment.

// Let the player search the room they are currently in (Prints the room description)
//
// args:
// - player: Player whose position is checked to determine what room description to show
// - map: Used to fetch the currently inhabited room description
void searchRoom(Entity *player, Map *map);


// Display the terminal map of the space ship.
void outputTerminalMap();