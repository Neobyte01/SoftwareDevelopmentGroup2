#include "entities/player.h"

void setupPlayer() {
    if (player != NULL) destroyEntity(player);

    player = createEntity(PLAYER, NONE);
    player->DMG = 0;
    player->DEF = 2;
}
