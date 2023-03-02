#include <stdio.h>
#include "map/map.h"
#include "map/generation.h"
#include "entities/player.h"
#include "entities/monsters.h"
#include "actions/interaction.h"


void testTerminalMap() {
    setupPlayer();
    player->roomId = 2;

    Entity *monster = createBlargh();
    monster->roomId = 12;

    addMonster(monster);

    globalMap = generateMap();
    outputTerminalMap();
}

void testInteractionLibrary() {
    testTerminalMap();
}

#ifdef TEST
int main(void) {
    testInteractionLibrary();
}
#endif