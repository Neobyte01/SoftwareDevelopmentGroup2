#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include "entities/player.h"
#include "map/movement.h"
#include <stdio.h>

<<<<<<< Updated upstream
#ifdef TEST
int main(void){
	
	struct Map *map = generateMap();
	
	enum Direction dir = DOWN;
=======
void testMovement(){
	globalMap = generateMap(16);
>>>>>>> Stashed changes

	setupPlayer();
    player->roomId = 2;

	printMap(player);


	player->roomId = 3;;

	printMap(player);

<<<<<<< Updated upstream

    
	

=======
	free(globalMap);
}

#ifdef TEST
int main(void){
	puts("Running tests...");
    testMovement();
    puts("Done.");
>>>>>>> Stashed changes
}
#endif