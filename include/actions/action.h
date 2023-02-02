#pragma once
#include "entities/entity.h"

// Action library
// This the main gameplay system. It handles the decisions
// of players and monsters throughout the game and acts upon 
// those decisions.

// Let player perform natural commands.
//
// The general format for user input is like this:
// ?: <command> <...>
//
// args:
// - player: Player which performs the action
void playerAction(Entity *player);

// Let monster decide an action and act upon it.
//
// Choice is overall decided by random chance but previous
// actions can have an affect on the likelyhood of any given
// action.
//
// args:
// - monster: Monster which performs the action.
void monsterAction(Entity *monster);