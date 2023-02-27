#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include "entities/player.h"
#include "map/movement.h"
#include <stdio.h>

<<<<<<<<< Temporary merge branch 1
=========
void testMovement(){
	globalMap = generateMap(16);
>>>>>>>>> Temporary merge branch 2

void testMovement(){

	globalMap = generateMap(16);


	if(player == NULL) setupPlayer();

    player->roomId = 2;

	printMap(player);

	int moved = moveEntity(player, DOWN);

	printMap(player);

	free(globalMap);
<<<<<<<<< Temporary merge branch 1

}


#ifdef TEST
int main(void){
	
	puts("Running tests...");
    testMovement();
    puts("Done.");
	

=========
}

#ifdef TEST
int main(void){
	puts("Running tests...");
    testMovement();
    puts("Done.");
>>>>>>>>> Temporary merge branch 2
}
#endif