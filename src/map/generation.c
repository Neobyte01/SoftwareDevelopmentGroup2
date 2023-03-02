#include "map/generation.h"
#include "map/map.h"
#include "colors.h"

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
	connect_rooms(&Map->array[0],&Map->array[2],RIGHT);
	connect_rooms(&Map->array[2],&Map->array[1],UP);
	connect_rooms(&Map->array[2],&Map->array[3],DOWN);
	connect_rooms(&Map->array[2],&Map->array[4],RIGHT);
	connect_rooms(&Map->array[4],&Map->array[5],RIGHT);
	connect_rooms(&Map->array[5],&Map->array[6],DOWN);
	connect_rooms(&Map->array[6],&Map->array[7],DOWN);
	connect_rooms(&Map->array[5],&Map->array[8],RIGHT);
	connect_rooms(&Map->array[8],&Map->array[10],RIGHT);
	connect_rooms(&Map->array[10],&Map->array[9],UP);
	connect_rooms(&Map->array[10],&Map->array[11],DOWN);
	connect_rooms(&Map->array[11],&Map->array[12],DOWN);
	connect_rooms(&Map->array[12],&Map->array[13],DOWN);
	connect_rooms(&Map->array[10],&Map->array[14],RIGHT);

	Map->array[0].type = SLEEPING;
	Map->array[1].type = SLEEPING;
	Map->array[2].type = SLEEPING;
	Map->array[3].type = COMMON;
	Map->array[4].type = CORRIDOR;
	Map->array[5].type = COMMON;
	Map->array[6].type = DINNER;
	Map->array[7].type = KITCHEN;
	Map->array[8].type = TERMINAL;
	Map->array[9].type = SLEEPING;
	Map->array[10].type = CORRIDOR;
	Map->array[11].type = DINNER;
	Map->array[12].type = COMMON;
	Map->array[13].type = CORRIDOR;
	Map->array[14].type = SLEEPING;

	Map->array[0].name = "the North-Western Sleeping Quarter.\n";
	Map->array[1].name = "the Western Sleeping Quarter.\n";
	Map->array[2].name = "the Eastern Sleeping Quarter.\n";
	Map->array[3].name = "the Eastern Common Room.\n";
	Map->array[4].name = "the Western Hall.\n";
	Map->array[5].name = "the Main Common Room.\n";
	Map->array[6].name = "the Dinner Hall.\n";
	Map->array[7].name = "the Kitchen.\n";
	Map->array[8].name = "the Terminal Room.\n";
	Map->array[9].name = "the South-Western Sleeping Quarter.\n";
	Map->array[10].name = "the Southern Hall.\n";
	Map->array[11].name = "the Eastern Dinner Hall.\n";
	Map->array[12].name = "the Southern Common Room.\n";
	Map->array[13].name = "the South-Eastern Hall.\n";
	Map->array[14].name = "the South-Eastern Sleeping Quarter.\n";

	Map->array[0].description = "A dark, dusty room.\n";
	Map->array[1].description = "A big and colorful room full of items.\n";
	Map->array[2].description = "There is blood on the bed sheets. At the corner of the room there is a"ANSI_COLOR_CYAN" box."ANSI_COLOR_RESET"\n"; //possibility to find items in this room
	Map->array[3].description = "Not much to see here except some fresh bizarre-looking footprints.\n";
	Map->array[4].description = "A dark, eerie hall with creaky floorboards.\n"; //can be heard by monsters when walking here
	Map->array[5].description = "A large room filled with bookshelves, a couch, chairs and a table. A chair is knocked to the floor.\n"; //might find something in the bookshelves
	Map->array[6].description = "A large room with a long table and many chairs. Leftovers and dirty dishes fill up the table. In the centre of it, something shiny can be seen.\n"; //a key can be found in this room
	Map->array[7].description = "A rather small room with dark counters and dirty tiles and window.\n";
	Map->array[8].description = "A tiny, sultry room with a turned on CRT-monitor on a metal desk.\n";
	Map->array[9].description = "A small room with only a bunk-bed and a "ANSI_COLOR_CYAN"closet"ANSI_COLOR_RESET".\n";
	Map->array[10].description = "A narrow, dark hall with a large "ANSI_COLOR_CYAN"crack"ANSI_COLOR_RESET" in the floorboards.\n";
	Map->array[11].description = "A room full of "ANSI_COLOR_CYAN"cabinets"ANSI_COLOR_RESET" alongside the dinner table.\n";
	Map->array[12].description = "A messy room with thrown books and other "ANSI_COLOR_CYAN"debris"ANSI_COLOR_RESET".\n";
	Map->array[13].description = "A white and long hall with slippery tiles.\n";
	Map->array[14].description = "A tidy room with a huge "ANSI_COLOR_CYAN"bed"ANSI_COLOR_RESET" and a large "ANSI_COLOR_CYAN"closet"ANSI_COLOR_RESET".\n";

    Map->array[3].Objects[0].name = "bed";
}

void populateItems(struct Map* Map) {
    // TODO: implement this.
}