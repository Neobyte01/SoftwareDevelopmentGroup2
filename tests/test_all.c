#include "actions/test_action.c"
#include "entities/test_monsters.c"
#include "entities/test_player.c"
#include "map/test_generation.c"
#include "test_combat.c"

int main() {    
    puts("Running all tests...");
    testCommandCompare();
    testMonsterRegistry();
    testSetupPlayer();
    testCombat();
    testGenerateMap();
    puts("Done.");
}