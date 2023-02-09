#include "entities/monsters.h"
#include <stdbool.h>

int noMonsters = 0;

Entity *createBlargh() {
    Entity *blargh = createEntity(MONSTER, NONE);
    blargh->maxHP = 20;
    blargh->DMG = 3;

    return blargh;
}

void addMonster(Entity *monster) {
    if (noMonsters == MAX_MONSTERS) {
        printf("ERROR: Monster registry is full.\n");
        return;
    }

    monsters[noMonsters] = monster;
    noMonsters++;
}

void removeMonster(Entity *monster) {
    bool found = false;

    for (int i = 0; i < noMonsters; i++) {
        if (monster == monsters[i]) {
            destroyEntity(monster);

            // Move trailing monsters up in the array.
            for (int j = i; j < (noMonsters-1); j++)
                monsters[j] = monsters[j+1];

            noMonsters--;
            found = true;
            break;
        }
    }

    if (!found) printf("ERROR: Monster not found in registry\n");
}