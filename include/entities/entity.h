#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include "actions/types.h"

// This library handle the functions regarding entities.
// Entities can be one of the following:
// - Player Characters
// - Monsters
// - Items

enum EntityType {
    PLAYER,
    MONSTER,
    ITEM,
};

enum EntityBehaviour {
    NONE,
    AGGRESSIVE,
    STALKING,
    SCARED,
};

int nextId;

typedef struct Entity {
    int id;
    enum EntityType type; 
    enum EntityBehaviour behaviour;
    
    // Stats
    int currentHP;
    unsigned int maxHP;
    int DMG;
    int DEF;
    int DEX;
    int SEN;

    // Items
    struct Entity** attached; // Attached entities
    int noAttached; // Number of attached entities
    
    // Tracking
    int roomId;
    enum ActionType last_action;
} Entity;

// Allocate memory and setup default attributes for an entity.
// 
// args:
// - type: Type of entity to create.
// - behaviour: Behaviour the entity should exhibit.
//
// returns: The created entity.
Entity* createEntity(enum EntityType type, enum EntityBehaviour behaviour);

// Free up memory and destroy entity.
//
// args:
// - entity: Entity to destroy.
void destroyEntity(Entity *entity);

// Add an entity to another.
// 
// The second entity is attached to the first entity (called primary).
// This will add stats from the secondary entity to the primary entity.
// This can used to give stat bonuses, or to increase the currentHP of the primary entity.
//
// args:
// - primary: Attacher.
// - secondary: Attachee.
void attachEntity(Entity* primary, Entity* secondary);

// Remove entity from other entity.
//
// The second entity is to be removed from the first one.
//
// args:
// - primary: Attacher
// - secondary: Attachee
void removeEntity(Entity* primary, Entity* secondary);

// Debug print an entity
//
// args:
// - entity: Entity to print.
void printEntity(Entity* entity);