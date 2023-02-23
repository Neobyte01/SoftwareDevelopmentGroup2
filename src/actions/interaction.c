#include "actions/interaction.h"

void searchRoom(Entity *player, Map *map)
{
    printf("\n%s\n", map->array[player->roomId].description);
}