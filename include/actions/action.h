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
void playerAction(Entity *player, int *exitFlag, char *testInput);

// Let monster decide an action and act upon it.
//
// Choice is overall decided by random chance but previous
// actions can have an affect on the likelyhood of any given
// action.
//
// args:
// - monster: Monster which performs the action.
void monsterAction(Entity *monster);

// Compare input command with array of valid commands;
// 
// args:
// - command: Input command.
// - valid_commands: List of valid commands.
// - noCommands: Number of valid commands.
//
// returns: Input command is found in array of valid commands.
bool commandCompare(char *command, char **valid_commands, int noCommands);
