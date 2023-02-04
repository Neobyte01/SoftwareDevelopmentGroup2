#include "entities/entity.h"

int nextId = 0;

Entity* createEntity(enum EntityType type, enum EntityBehaviour behaviour) {
    Entity* entity = malloc(sizeof(Entity));

    entity->id = nextId;
    entity->type = type;
    entity->behaviour = behaviour;

    // Stats
    entity->maxHP = 10;
    entity->currentHP = entity->maxHP;
    entity->DMG = 5;
    entity->DEF = 5;
    entity->DEX = 5;

    // Items
    entity->attached = NULL;
    entity->noAttached = 0;

    // Tracking
    entity->last_action = CREATED;
    entity->room = NULL;

    nextId++;

    return entity;
}

void destroyEntity(Entity* entity) {
    if (entity != NULL) free(entity);

    entity = NULL;
}

void attachEntity(Entity* primary, Entity* secondary) {
    // Stats
    primary->maxHP += secondary->maxHP;
    primary->currentHP += secondary->currentHP;
    primary->DMG += secondary->DMG;
    primary->DEF += secondary->DEF;
    primary->DEX += secondary->DEX;

    // Items
    primary->attached[primary->noAttached] = secondary;
    primary->noAttached++;
}

void removeEntity(Entity* primary, Entity* secondary) {
    bool found = false;

    for (int i = 0; i < primary->noAttached; i++) {
        if (secondary == primary->attached[i]) {
            for (int j = i; j < (primary->noAttached-1); j++) 
                primary->attached[j] = primary->attached[j+1];

            found = true;
            break;
        }
    }

    if (!found) {
        printf("ERROR: Secondary entity not attached to primary entity\n");
        return;
    } 
    
    // Stats
    primary->maxHP -= secondary->maxHP;
    primary->currentHP -= secondary->currentHP;
    primary->DMG -= secondary->DMG;
    primary->DEF -= secondary->DEF;
    primary->DEX -= secondary->DEX;

    // Items
    primary->noAttached--;
}

void printEntity(Entity* entity) {
    printf("Entity (%d)\n", entity->id);
    printf("------------------\n");
    
    if (entity->room != NULL) 
        printf("room: %d\n", entity->room->roomNr);
    
    printf("hp: %d\n", entity->currentHP);
}