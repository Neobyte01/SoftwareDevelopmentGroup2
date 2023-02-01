#pragma once
#include "entity.h"

enum Action {
    CREATED,
    GROWL,
    SNIFF,
    MOVE,
    WAIT,
};

void player_action(struct entity player);

void monster_action(struct entity *monster);

