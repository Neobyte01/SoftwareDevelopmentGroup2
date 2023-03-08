#pragma once
#include <stdlib.h>
#include "entities/entity.h"
#include "map/movement.h"

// Map library
// Contains the map and functions for setting it up.
// globalMap contains the map used inside the game.

#define MAX_OBJECTS 5

enum RoomType {
	CORRIDOR, 
	DINNER_HALL,
	SLEEPING_QUARTER,
	COMMON_ROOM,
	TERMINAL_ROOM,
	KITCHEN,
	HALL
}; 

// Objects or furniture inside a room. Not items.
typedef struct Object {
	char *name;
	char *description;
	Entity *item;
} Object; 

// A structure to represent a room .
typedef struct Room {
	int id; 
	enum RoomType type;
	//struct Edge* head;

	struct Room *left;
  	struct Room *right;
  	struct Room *up;
  	struct Room *down;

	char *name;
	char *description;

	bool visited; 

    struct Object* Objects; 
	int noObjects;
} Room;

// A structure to represent a Map
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in Map)
typedef struct Map {
	int V;
	struct Room* array;
} Map;

Map *globalMap; 

// A utility function that creates a graph of V Rooms.
// 
// args:
// - V: Number of rooms.
//
// returns: newly created graph.
Map* createMap(int V);

// A utility function that frees a map from memory
//
// args:
// - map: Pointer to the map to destroy
void destroyMap(struct Map* map);

// Create an object.
//
// returns: newly created object.
Object * createObject();

// Add an object to a room.
//
// args:
// - room: The room to add to.
// - object: The object to add.
void addObjectToRoom(Room *room, Object *object);

// this function prints the Map, it can be modified later e.g. we can print the ID of each room in the boxes
void printMap(Entity *entity);

// Describe the room to the player.
//
// args:
// - room_id: Id of the room to describe.
void describeRoom(struct Map *map, int room_id);

// Connecting two rooms
// input: 
//		a: room a
// 		b: room b
// 		dir: in which direction room b should be connected to room b
void connect_rooms(Room *a,Room *b,enum Direction dir);
