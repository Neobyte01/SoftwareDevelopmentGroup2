#include "actions/test_action.c"
#include "actions/test_interaction.c"
#include "entities/test_entity.c"
#include "entities/test_monsters.c"
#include "entities/test_player.c"
#include "map/test_map.c"
#include "map/test_generation.c"
#include "test_combat.c"
#include "map/test_movement.c"

int main() {    
    puts("Running all tests...");
    
    testActionLibrary();
    testInteractionLibrary();

    testMonsterRegistry();
    testSetupPlayer();
    testEntity();

    testCombat();
    
    testGenerateMap();
    testMovement();
    testMap();
    
    perfTestMapGen();
}