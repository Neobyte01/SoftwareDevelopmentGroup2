#include <assert.h>
#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include <string.h>
#include <stdio.h>

void testMap1Description() {
	assert(strcmp(globalMap->array[1].description, "A dark, dusty room.\n") == 0);
}

void testMap1Type() {
	assert(globalMap->array[1].type == SLEEPING_QUARTER);
}

void testMap1Name() {
	assert(strcmp(globalMap->array[1].name, "the North-Western Sleeping Quarter.\n") == 0);
}


void testTerminalRoom() {
	assert(globalMap->array[9].type == TERMINAL_ROOM);
	assert(strcmp(globalMap->array[9].name, "the Terminal Room.\n") == 0);
	assert(strcmp(globalMap->array[9].description, "A tiny, sultry room with a turned on CRT-monitor on a metal desk.\n") == 0);
}

void testAll() {
  globalMap = generateMap(16);
	testMap1Description();
	testMap1Type();
	testMap1Name();
	testTerminalRoom();
  free(globalMap);
}

#ifdef TEST
int main(void){
	testAll();
	puts("Testing maps done.");
}
#endif