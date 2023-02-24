#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include "entities/player.h"

#include <stdio.h>

int main(void){
	
	struct Map *map = generateMap();
	

	setupPlayer();
    player->roomId = 2;

	printMap(player);
	// ...
}