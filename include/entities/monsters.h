#pragma once
#include "entities/entity.h"

// Monsters library.
// Contains all monsters and functions for managing them.

#define MAX_MONSTERS 10

Entity *monsters[MAX_MONSTERS];
int noMonsters;

// Create a "Blargh" monster.
//
// returns: Monster entity.
Entity *createBlargh();

// Add a monster to the global monster register.
// 
// args:
// - monster: Monster to add.
void addMonster(Entity *monster);

// Remove monster from the global monster register.
//
// args:
// - monster: Monster to remove. 
void removeMonster(Entity *monster);