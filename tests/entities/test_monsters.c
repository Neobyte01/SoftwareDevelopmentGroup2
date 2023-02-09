#include <assert.h>
#include "entities/monsters.h"

void testMonsterRegistry() {
    assert(monsters[0] == NULL);

    addMonster(createEntity(MONSTER, NONE));
    assert(monsters[0] != NULL);
    assert(monsters[1] == NULL);

    addMonster(createEntity(MONSTER, NONE));
    assert(monsters[0] != NULL);
    assert(monsters[1] != NULL);
    
    int secondId = monsters[1]->id;
    removeMonster(monsters[0]);
    assert(monsters[0]->id == secondId);
    assert(noMonsters == 1);

    removeMonster(monsters[0]);
    assert(noMonsters == 0);
}

int main() {
    puts("Running tests...");
    testMonsterRegistry();
    puts("Done.");
}