#include "map/map.h"
#include <stdio.h>
#include <stdlib.h>
#include "entities/player.h"
#include "map/movement.h"

// ...
static char check(int n, int roomId);

const char* RoomNames[10] = {"Corridor", "Dinner hall", "Sleeping quarter", "Common room", "Terminal room"};





struct Map* createMap(int V) {
	struct Map* Map = (struct Map*)malloc(sizeof(struct Map)); Map->V = V;

	Map->array = (struct Room*)malloc(V * sizeof(struct Room));

	int i;
	for (i = 0; i < V; ++i){
		Map->array[i].id = i;
		Map->array[i].type = CORRIDOR;
		Map->array[i].Objects =  (struct Object*)malloc(MAX_OBJECTS * sizeof(struct Object));
		Map->array[i].left = NULL;
		Map->array[i].right = NULL;
		Map->array[i].up = NULL;
		Map->array[i].down = NULL;
		Map->array[i].description = "N/A";
	}

	defaultMap(Map);

	return Map;
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

void printMap(Entity *entity) {
    int id = entity->roomId;

	printf("      [%c]         [%c]\n",check(2, id), check(10, id));
	printf("   [%c][%c][%c][%c][%c][%c][%c]\n", check(1, id),check(3, id), check(5, id), check(6, id), check(9,id),check(11, id),check(15, id));
	printf("      [%c]   [%c]   [%c]\n",check(4, id),check(7, id), check(12, id));
	printf("            [%c]   [%c]\n",check(8, id),check(13, id));
	printf("                  [%c]\n",check(13, id));
	printf("            \n");
}

void describeRoom(struct Map *map, int room_id) {
	printf("%s\n\n",  map->array[room_id].description);
}

void defaultMap(struct Map* Map) {
	connect_rooms(&Map->array[1],&Map->array[3],RIGHT);
	connect_rooms(&Map->array[3],&Map->array[2],UP);
	connect_rooms(&Map->array[3],&Map->array[4],DOWN);
	connect_rooms(&Map->array[3],&Map->array[5],RIGHT);
	connect_rooms(&Map->array[5],&Map->array[6],RIGHT);
	connect_rooms(&Map->array[6],&Map->array[7],DOWN);
	connect_rooms(&Map->array[7],&Map->array[8],DOWN);
	connect_rooms(&Map->array[6],&Map->array[9],RIGHT);
	connect_rooms(&Map->array[9],&Map->array[11],RIGHT);
	connect_rooms(&Map->array[11],&Map->array[10],UP);
	connect_rooms(&Map->array[11],&Map->array[12],DOWN);
	connect_rooms(&Map->array[12],&Map->array[13],DOWN);
	connect_rooms(&Map->array[13],&Map->array[14],DOWN);
	connect_rooms(&Map->array[11],&Map->array[15],RIGHT);



	Map->array[1].type = SLEEPING_QUARTER;
	Map->array[2].type = SLEEPING_QUARTER;
	Map->array[4].type = SLEEPING_QUARTER;
	Map->array[3].type = COMMON_ROOM;
	Map->array[7].type = DINNER_HALL;
	Map->array[8].type = KITCHEN;
	Map->array[9].type = TERMINAL_ROOM;
}



