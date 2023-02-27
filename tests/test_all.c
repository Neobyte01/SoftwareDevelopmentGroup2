#include "actions/test_action.c"
#include "entities/test_monsters.c"
#include "entities/test_player.c"
#include "test_combat.c"

int main() {    
    puts("Running all tests...");
    testCommandCompare();
    testMonsterRegistry();
    testSetupPlayer();
    testCombat();
    puts("Done.");
}