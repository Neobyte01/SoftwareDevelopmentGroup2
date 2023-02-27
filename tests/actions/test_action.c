#include <assert.h>
#include "actions/action.h"
#include "entities/monsters.h"

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