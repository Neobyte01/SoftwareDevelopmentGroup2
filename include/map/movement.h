#pragma once
#include "entities/entity.h"

// Movement library.
// Handles the movement of entities and path finding.

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

// Change the position of an entity.
//
// args:
// - entity: Entity to move.
// - dir: Direction to move.
void moveEntity(Entity *entity, enum Direction dir);



// move player to left-side of the map
// input: 
//      id: players current roomID
void moveLeft(int id);


// move player to right-side of the mkap
// input: 
//      id: players current roomID
void moveRight(int id);


// move player to the Up-side
// input: 
//      id: players current roomID
void moveUp(int id);


// move to player to the Down-side of the map
// input: 
//      id: players current roomID
void moveDown(int id);