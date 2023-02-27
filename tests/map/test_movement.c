#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include "entities/player.h"
#include "map/movement.h"
#include <stdio.h>

void testMovement(){

	globalMap = generateMap(16);


	if(player == NULL) setupPlayer();

    player->roomId = 2;

	printMap(player);

	int moved = moveEntity(player, DOWN);
	moved = moveEntity(player, LEFT);
	moved = moveEntity(player, RIGHT);
	moved = moveEntity(player, UP);

	printMap(player);

	free(globalMap);
}


#ifdef TEST
int main(void){
	
	puts("Running tests...");
    testMovement();
    puts("Done.");
	
}
#endif