#include <assert.h>
#include "entities/player.h"

void testSetupPlayer() {
    // Starts empty
    assert(player == NULL);

    // Fills with player
    setupPlayer();
    assert(player != NULL);
    assert(player->type == PLAYER);

    // Removes previous player and creates a new one
    int initialId = player->id;
    setupPlayer();
    assert(initialId != player->id);

    destroyEntity(player);  // ! important to reset test. 
}

#ifdef TEST
int main() {
    puts("Running tests...");
    testSetupPlayer();
    puts("Done.");
}
#endif