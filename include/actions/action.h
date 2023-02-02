#pragma once
#include "entities/entity.h"

// Action library
// This the main gameplay system. It handles the decisions
// of players and monsters throughout the game and acts upon 
// those decisions.

#define SCAN_INPUT_SIZE 256

// Let player perform natural commands.
//
// The general format for user input is like this:
// ?: <command> <...>
//
// args:
// - player: Player which performs the action
// - exitFlag: (1) when the user want to exit, (0) when not.
void playerAction(Entity *player, int *exitFlag);

// Let monster decide an action and act upon it.
//
// Choice is overall decided by random chance but previous
// actions can have an affect on the likelyhood of any given
// action.
//
// args:
// - monster: Monster which performs the action.
void monsterAction(Entity *monster);