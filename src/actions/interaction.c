#include "actions/interaction.h"

void searchRoom(Entity *player, Map *map)
{
    printf("\nYou are currently in %s\n", map->array[player->roomId].name);
    printf("%s\n", map->array[player->roomId].description);
}