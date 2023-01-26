#include <stdio.h>
#include "tests/test.h"
#include "tests/test_game.h"
#include "tests/testCombat.h"

void test_program() {
    printf("Testing program...\n");
    testCombatPlayerKillsMonster();
    printf("Done!\n");
}