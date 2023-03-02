#include "map/generation.h"
#include "map/map.h"
#include "colors.h"

// Setup the default map.
static void defaultMap(struct Map* Map);

// Populate the map with predetermined items at random locations.
static void populateItems(struct Map* Map);

struct Map *generateMap() {
    struct Map *map = createMap(50);
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
	connect_rooms(&Map->array[5], &Map->array[9], DOWN);

	Map->array[6].name = "Corridor";
	Map->array[6].type = CORRIDOR;
	connect_rooms(&Map->array[6], &Map->array[7], RIGHT);

	Map->array[7].name = "Electrical room";
	Map->array[7].type = ELECTRICAL;
	
	Map->array[8].name = "Airlock";
	Map->array[8].type = AIRLOCK;
	connect_rooms(&Map->array[8], &Map->array[12], DOWN);

	Map->array[9].name = "Corridor";
	Map->array[9].type = CORRIDOR;
	connect_rooms(&Map->array[9], &Map->array[10], RIGHT);
	connect_rooms(&Map->array[9], &Map->array[14], DOWN);

	Map->array[10].name = "Locker room";
	Map->array[10].type = LOCKER;
	
	Map->array[11].name = "Airlock";
	Map->array[11].type = AIRLOCK;
	connect_rooms(&Map->array[11], &Map->array[16], DOWN);

	Map->array[12].name = "Corridor";
	Map->array[12].type = CORRIDOR;
	connect_rooms(&Map->array[12], &Map->array[17], DOWN);

	Map->array[13].name = "Ventilation room";
	Map->array[13].type = VENTILATION;
	connect_rooms(&Map->array[13], &Map->array[18], DOWN);

	Map->array[14].name = "Corridor";
	Map->array[14].type = CORRIDOR;
	connect_rooms(&Map->array[14], &Map->array[15], RIGHT);
	connect_rooms(&Map->array[14], &Map->array[19], DOWN);

	Map->array[15].name = "Common room";
	Map->array[15].type = COMMON;

	Map->array[16].name = "Corridor";
	Map->array[16].type = CORRIDOR;
	connect_rooms(&Map->array[16], &Map->array[21], DOWN);

	Map->array[17].name = "Corridor";
	Map->array[17].type = CORRIDOR;
	connect_rooms(&Map->array[17], &Map->array[18], RIGHT);
	connect_rooms(&Map->array[17], &Map->array[24], DOWN);

	Map->array[18].name = "Corridor";
	Map->array[18].type = CORRIDOR;
	connect_rooms(&Map->array[18], &Map->array[19], RIGHT);

	Map->array[19].name = "Corridor";
	Map->array[19].type = CORRIDOR;
	connect_rooms(&Map->array[19], &Map->array[20], RIGHT);
	connect_rooms(&Map->array[19], &Map->array[26], DOWN);

	Map->array[20].name = "Corridor";
	Map->array[20].type = CORRIDOR;
	connect_rooms(&Map->array[20], &Map->array[21], RIGHT);

	Map->array[21].name = "Corridor";
	Map->array[21].type = CORRIDOR;
	connect_rooms(&Map->array[21], &Map->array[22], RIGHT);
	connect_rooms(&Map->array[21], &Map->array[28], DOWN);

	Map->array[22].name = "Terminal room";
	Map->array[22].type = TERMINAL;

	Map->array[23].name = "Equipment room";
	Map->array[23].type = EQUIPMENT;
	connect_rooms(&Map->array[23], &Map->array[33], DOWN);

	Map->array[24].name = "Corridor";
	Map->array[24].type = CORRIDOR;
	connect_rooms(&Map->array[24], &Map->array[35], DOWN);

	Map->array[25].name = "North-west hangar";
	Map->array[25].type = HANGAR;
	connect_rooms(&Map->array[25], &Map->array[26], RIGHT);
	connect_rooms(&Map->array[25], &Map->array[36], DOWN);

	Map->array[26].name = "North hangar";
	Map->array[26].type = HANGAR;
	connect_rooms(&Map->array[26], &Map->array[27], RIGHT);

	Map->array[27].name = "North-east hangar";
	Map->array[27].type = HANGAR;
	connect_rooms(&Map->array[27], &Map->array[38], DOWN);

	Map->array[28].name = "Corridor";
	Map->array[28].type = CORRIDOR;
	connect_rooms(&Map->array[28], &Map->array[29], RIGHT);
	connect_rooms(&Map->array[28], &Map->array[39], DOWN);

	Map->array[29].name = "Corridor";
	Map->array[29].type = CORRIDOR;
	connect_rooms(&Map->array[29], &Map->array[30], RIGHT);
	connect_rooms(&Map->array[29], &Map->array[40], DOWN);

	Map->array[30].name = "Corridor";
	Map->array[30].type = CORRIDOR;
	connect_rooms(&Map->array[30], &Map->array[31], RIGHT);
	connect_rooms(&Map->array[30], &Map->array[41], DOWN);

	Map->array[31].name = "Medical bay";
	Map->array[31].type = MEDICAL;

	Map->array[32].name = "Engine room";
	Map->array[32].type = ENGINE;

	Map->array[33].name = "Corridor";
	Map->array[33].type = CORRIDOR;
	connect_rooms(&Map->array[33], &Map->array[32], LEFT);
	connect_rooms(&Map->array[33], &Map->array[34], RIGHT);

	Map->array[34].name = "Corridor";
	Map->array[34].type = CORRIDOR;
	connect_rooms(&Map->array[34], &Map->array[35], RIGHT);
	connect_rooms(&Map->array[34], &Map->array[43], DOWN);

	Map->array[35].name = "Corridor";
	Map->array[35].type = CORRIDOR;
	connect_rooms(&Map->array[35], &Map->array[36], RIGHT);

	Map->array[36].name = "West hangar";
	Map->array[36].type = HANGAR;
	connect_rooms(&Map->array[36], &Map->array[44], DOWN);

	Map->array[37].name = "";
	Map->array[37].type = HANGAR;

	Map->array[38].name = "East hangar";
	Map->array[38].type = HANGAR;
	connect_rooms(&Map->array[38], &Map->array[39], RIGHT);
	connect_rooms(&Map->array[38], &Map->array[46], RIGHT);

	Map->array[39].name = "Corridor";
	Map->array[39].type = CORRIDOR;
	connect_rooms(&Map->array[39], &Map->array[40], RIGHT);

	Map->array[40].name = "Containment facility";
	Map->array[40].type = CONTAINMENT_FACILITY;
	connect_rooms(&Map->array[40], &Map->array[47], DOWN);

	Map->array[41].name = "Engine room";
	Map->array[41].type = ENGINE;

	Map->array[42].name = "Food storage";
	Map->array[42].type = FOOD_STORAGE;
	connect_rooms(&Map->array[42], &Map->array[48], DOWN);

	Map->array[43].name = "Corridor";
	Map->array[43].type = CORRIDOR;
	connect_rooms(&Map->array[43], &Map->array[49], DOWN);

	Map->array[44].name = "South-west hangar";
	Map->array[44].type = HANGAR;
	connect_rooms(&Map->array[44], &Map->array[45], RIGHT);

	Map->array[45].name = "South hangar";
	Map->array[45].type = HANGAR;
	connect_rooms(&Map->array[45], &Map->array[46], RIGHT);

	Map->array[46].name = "South-east hangar";
	Map->array[46].type = HANGAR;

	Map->array[47].name = "Specimen observation";
	Map->array[47].type = OBSERVATION;

	Map->array[48].name = "Kitchen";
	Map->array[48].type = KITCHEN;
	connect_rooms(&Map->array[48], &Map->array[49], RIGHT);

	Map->array[49].name = "Dinner hall";
	Map->array[49].type = DINNER;
}

void populateItems(struct Map* Map) {
    // TODO: implement this.
}