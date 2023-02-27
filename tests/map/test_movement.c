#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include "entities/player.h"
#include "map/movement.h"

#include <stdio.h>

#ifdef TEST
int main(void){
	
	struct Map *map = generateMap();
	
	enum Direction dir = DOWN;

	setupPlayer();
    player->roomId = 2;

	printMap(player);


	player->roomId = 3;;

	printMap(player);


    
	

}
#endif