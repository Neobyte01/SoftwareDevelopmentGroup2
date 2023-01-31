#pragma once
#include "entity.h"

// Actions:

// - move(entity, directions)

// - search <object>
// - take <object>
// - read <object>
// - hit <object>

// - item action 

// - view person

// - help 

void player_action(struct entity Player);

void monster_action(struct entity Monster);

// Tidigare beskrivning

// ?: ...

// ?: help (HELP, help, hel, he, h) -> gets list of instructions

// ?: search -> help for search <object>