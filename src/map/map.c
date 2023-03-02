#include "map/map.h"
#include <stdio.h>
#include <stdlib.h>
#include "entities/player.h"
#include "map/movement.h"

// Check entity position.
static char check(int n, int roomId);

struct Map* createMap(int V) {
	struct Map* Map = (struct Map*)malloc(sizeof(struct Map)); Map->V = V;

	Map->array = (struct Room*)malloc(V * sizeof(struct Room));

	int i;
	for (i = 0; i < V; ++i){
		Map->array[i].id = i;
		Map->array[i].type = CORRIDOR;
		
		Map->array[i].Objects =  (struct Object*)malloc(MAX_OBJECTS * sizeof(struct Object));
		for (int j = 0; j < MAX_OBJECTS; j++) {
			Map->array[i].Objects[j].name = NULL;
			Map->array[i].Objects[j].description = "N/A";
			Map->array[i].visited = false; 
			Map->array[i].Objects[j].item = NULL;
		}
		
		Map->array[i].left = NULL;
		Map->array[i].right = NULL;
		Map->array[i].up = NULL;
		Map->array[i].down = NULL;
		Map->array[i].name = "N/A";
		Map->array[i].description = "N/A";
	}

	return Map;
}

void describeRoom(struct Map *map, int room_id) {
	printf("%s\n\n",  map->array[room_id].name);
}

void connect_rooms(Room *a,Room *b, enum Direction dir) {
	if (dir == LEFT) {
		a->left = b;
		b->right = a;
	} else if (dir == RIGHT) {
		a->right = b;
		b->left = a;
	} else if (dir == UP) {
		a->up = b;
		b->down = a;
	} else if (dir == DOWN) {
		a->down = b;
		b->up = a;
	}
}

char check(int n, int roomId) {
    return roomId == n ? '*' : ' ';
}
