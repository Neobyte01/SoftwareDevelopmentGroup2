#include "actions/interaction.h"

void searchRoom(Entity *player, Map *map)
{
    printf("%s\n", map->array[player->roomId].description);
}