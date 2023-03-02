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
	Map->array[0].name = "Command bridge";
	Map->array[0].type = COMMAND_BRIDGE;
	connect_rooms(&Map->array[0], &Map->array[2], DOWN);

	Map->array[1].name = "Storage room";
	Map->array[1].type = STORAGE;
	connect_rooms(&Map->array[1], &Map->array[2], RIGHT);

	Map->array[2].name = "Corridor";
	Map->array[2].type = CORRIDOR;
	connect_rooms(&Map->array[2], &Map->array[5], DOWN);

	Map->array[3].name = "Toilet";
	Map->array[3].type = TOILET;
	connect_rooms(&Map->array[3], &Map->array[2], LEFT);

	Map->array[4].name = "Sleeping quarters";
	Map->array[4].type = SLEEPING;
	connect_rooms(&Map->array[4], &Map->array[5], RIGHT);

	Map->array[5].name = "Corridor";
	Map->array[5].type = CORRIDOR;
	connect_rooms(&Map->array[5], &Map->array[6], RIGHT);

	Map->array[6].name = "Corridor";
	Map->array[6].type = CORRIDOR;
	connect_rooms(&Map->array[6], &Map->array[7], RIGHT);

	Map->array[7].name = "Electrical room";
	Map->array[7].type = ELECTRICAL;
}

void populateItems(struct Map* Map) {
    // TODO: implement this.
}