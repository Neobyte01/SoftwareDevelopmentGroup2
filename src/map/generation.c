#include "map/generation.h"
#include "map/map.h"

// Setup the default map.
static void defaultMap(struct Map* Map);

// Populate the map with predetermined items at random locations.
static void populateItems(struct Map* Map);

struct Map *generateMap() {
    struct Map *map = createMap(15);

    defaultMap(map);
    populateItems(map);

    return map;
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

	Map->array[1].name = "the North-Western Sleeping Quarter.\n";
	Map->array[2].name = "the Western Sleeping Quarter. A big and\ncolorful room full of items.\n";
	Map->array[3].name = "the Eastern Sleeping Quarter. There is\nblood on the bed sheets. At the corner of the room there is a box.\n"; //possibility to find items in this room
	Map->array[4].name = "the Eastern Common Room. Not much to\nsee here except some fresh bizarre-looking footprints.\n";
	Map->array[5].name = "the Western Hall. A dark, eerie hall with\ncreaky floorboards.\n"; //can be heard by monsters when walking here
	Map->array[6].name = "the Main Common Room. A large room filled\nwith bookshelves, a couch, chairs and a table. A chair is knocked to the floor.\n"; //might find something in the bookshelves
	Map->array[7].name = "the Dinner Hall. A large room with a long\ntable and many chairs. Leftovers and dirty dishes fill up the table. In the centre of it, something shiny can be seen.\n"; //a key can be found in this room
	Map->array[8].name = "the Kitchen. A rather small room with dark\ncounters and dirty tiles and window.\n";
	Map->array[9].name = "the Terminal Room. A tiny, sultry room\nwith a turned on CRT-monitor on a metal desk.\n";
	Map->array[10].name = "the South-Western Sleeping Quarter. A\nsmall room with only a bunk-bed and a closet.\n";
	Map->array[11].name = "the Southern Hall. A narrow, dark hall\nwith a large crack in the floorboards.\n";
	Map->array[12].name = "the Eastern Dinner Hall. A room full of\ncabinets alongside the dinner table.\n";
	Map->array[13].name = "the Southern Common Room. A messy room\nwith thrown books and other debris.\n";
	Map->array[14].name = "the South-Eastern Hall. A white and long\nhall with slippery tiles.\n";
	Map->array[15].name = "the South-Eastern Sleeping Quarter. A\ntidy room with a huge bed and a large closet.\n";

	Map->array[1].description = "A dark, dusty room.\n";
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

    Map->array[3].Objects[0].name = "bed";
}

void populateItems(struct Map* Map) {
    // TODO: implement this.
}