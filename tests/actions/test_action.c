#include <assert.h>
#include "actions/action.h"
#include "entities/monsters.h"
#include "entities/player.h"
#include "entities/entity.h"
#include "map/movement.h"
#include "map/generation.h"
#include "map/map.h"

void testPlayerAction() {
    globalMap = generateMap();
    
    setupPlayer();
    player->roomId = 2;

    int exitFlag = 0;

    playerAction(player, &exitFlag, "help");

    playerAction(player, &exitFlag, "test");

    playerAction(player, &exitFlag, "search");

    playerAction(player, &exitFlag, "map");

    playerAction(player, &exitFlag, "move north");
    assert(player->roomId == 2);

    playerAction(player, &exitFlag, "move east");
    assert(player->roomId == 2);

    playerAction(player, &exitFlag, "move west");
    assert(player->roomId == 2);

    playerAction(player, &exitFlag, "move south");
    moveUp(player->roomId);
    assert(player->roomId == 2);

    destroyEntity(player);
    player = NULL;
    free(globalMap);
}

void testMonsterAction() {
    Entity *monster = createBlargh();
    monsterAction(monster);
    assert(monster->last_action != NULL);
}

void testCommandCompare() {
    char *commands[] = {"abc", "123", "abc 123"};

    for (int i = 0; i < 3; i++)
        assert(commandCompare(commands[i], commands, 3));

    assert(!commandCompare("test", commands, 3));
}

void testActionLibrary() {
    testPlayerAction();
    testMonsterAction();
    testCommandCompare();
}

#ifdef TEST
int main(void) {
    puts("Running tests...");
    testCommandCompare();
    puts("Done.");
}
#endif