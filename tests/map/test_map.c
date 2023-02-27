#include <assert.h>
#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include <string.h>
#include <stdio.h>
#include <time.h>

void testMapDescription() {
	assert(strcmp(globalMap->array[1].description, "A dark, dusty room.\n") == 0);
}

void testMapType() {
	assert(globalMap->array[1].type == SLEEPING_QUARTER);
}

void testMapName() {
	assert(strcmp(globalMap->array[1].name, "the North-Western Sleeping Quarter.\n") == 0);
}

void testTerminalRoom() {
	assert(globalMap->array[9].type == TERMINAL_ROOM);
	assert(strcmp(globalMap->array[9].name, "the Terminal Room.\n") == 0);
	assert(strcmp(globalMap->array[9].description, "A tiny, sultry room with a turned on CRT-monitor on a metal desk.\n") == 0);
}

<<<<<<< HEAD
=======
void perfTestMapGen()
{
	printf("Tests generation of map\n");
	clock_t start, end;
	double total;
	start = clock();
	puts("Before");
	struct Map *genMap = generateMap();
	puts("After");
	end = clock();
	total = (double)(end - start)/CLOCKS_PER_SEC;
	assert(total < 0.5);
	printf("Elapsed time: %f\n", total);
	free(genMap);
}

>>>>>>> c1f247205230868ff387390a24483815657e2c13
void testMap() {
  globalMap = generateMap(16);
	testMapDescription();
	testMapType();
	testMapName();
	testTerminalRoom();
  free(globalMap);
}

#ifdef TEST
int main(void){
	testMap();
	puts("Testing maps done.");
}
#endif