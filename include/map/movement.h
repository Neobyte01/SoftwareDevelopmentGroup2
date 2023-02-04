#pragma once
#include "entities/entity.h"

// Movement library.
// Handles the movement of entities and path finding.

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
};

// Change the position of an entity.
//
// args:
// - entity: Entity to move.
// - dir: Direction to move.
void moveEntity(Entity *entity, enum Direction dir);