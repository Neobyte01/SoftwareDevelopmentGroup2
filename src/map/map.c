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
	Map->array[3].type = SLEEPING_QUARTER;
	Map->array[4].type = COMMON_ROOM;
	Map->array[5].type = HALL;
	Map->array[6].type = COMMON_ROOM;
	Map->array[7].type = DINNER_HALL;
	Map->array[8].type = KITCHEN;
	Map->array[9].type = TERMINAL_ROOM;
	Map->array[10].type = SLEEPING_QUARTER;
	Map->array[11].type = HALL;
	Map->array[12].type = DINNER_HALL;
	Map->array[13].type = COMMON_ROOM;
	Map->array[14].type = HALL;
	Map->array[15].type = SLEEPING_QUARTER;


	Map->array[1].description = "the North-Western Sleeping Quarter. A\ndark, dusty room.\n";
	Map->array[2].description = "the Western Sleeping Quarter. A big and\ncolorful room full of items.\n";
	Map->array[3].description = "the Eastern Sleeping Quarter. There is\nblood on the bed sheets. At the corner of the room there is a box.\n"; //possibility to find items in this room
	Map->array[4].description = "the Eastern Common Room. Not much to\nsee here except some fresh bizarre-looking footprints.\n";
	Map->array[5].description = "the Western Hall. A dark, eerie hall with\ncreaky floorboards.\n"; //can be heard by monsters when walking here
	Map->array[6].description = "the Main Common Room. A large room filled\nwith bookshelves, a couch, chairs and a table. A chair is knocked to the floor.\n"; //might find something in the bookshelves
	Map->array[7].description = "the Dinner Hall. A large room with a long\ntable and many chairs. Leftovers and dirty dishes fill up the table. In the centre of it, something shiny can be seen.\n"; //a key can be found in this room
	Map->array[8].description = "the Kitchen. A rather small room with dark\ncounters and dirty tiles and window.\n";
	Map->array[9].description = "the Terminal Room. A tiny, sultry room\nwith a turned on CRT-monitor on a metal desk.\n";
	Map->array[10].description = "the South-Western Sleeping Quarter. A\nsmall room with only a bunk-bed and a closet.\n";
	Map->array[11].description = "the Southern Hall. A narrow, dark hall\nwith a large crack in the floorboards.\n";
	Map->array[12].description = "the Eastern Dinner Hall. A room full of\ncabinets alongside the dinner table.\n";
	Map->array[13].description = "the Southern Common Room. A messy room\nwith thrown books and other debris.\n";
	Map->array[14].description = "the South-Eastern Hall. A white and long\nhall with slippery tiles.\n";
	Map->array[15].description = "the South-Eastern Sleeping Quarter. A\ntidy room with a huge bed and a large closet.\n";
}



