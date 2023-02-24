#include <assert.h>
#include "map/map.h"
#include "entities/entity.h"
#include "map/generation.h"
#include <string.h>
#include <stdio.h>


void testMapDescription() {

	assert(strcmp(globalMap->array[1].description, "A dark, dusty room.\n") == 0);
}

void testMapType() {

	assert(globalMap->array[1].type == SLEEPING_QUARTER);
}

void testMapName() {

	assert(strcmp(globalMap->array[1].name, "the North-Western Sleeping Quarter.\n") == 0);
}

int main(void){
	globalMap = generateMap(16);
	testMapDescription();
	void testMapType();
	void testMapName();
	puts("Testing map done.");
	


	// ...
}