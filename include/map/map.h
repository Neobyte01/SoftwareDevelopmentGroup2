#pragma once
#include <stdlib.h>
#include "entities/entity.h"

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
	KITCHEN
}; 

const char* RoomNames[10];

// A structure to represent connection between rooms.
typedef struct Edge {
	int dest;
	struct Edge* next;
} Edge;

// A structure to represent a room .
typedef struct Room {
	int id; 
	enum RoomType type;
	struct Edge* head;
    struct Object* Objects; 
} Room;

struct Object {
	// we can add items to this section later 
}; 

// A structure to represent a Map
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in Map)
typedef struct Map {
	int V;
	struct Room* array;
} Map;

Map *globalMap; 

// A utility function to create a new adjacency list node i.e. Room.
// 
// args:
// - dest: Destination to connect.
//
// returns: newly created edge.
Edge* newEdge(int dest);

// A utility function that creates a graph of V Rooms.
// 
// args:
// - V: Number of rooms.
//
// returns: newly created graph.
Map* createMap(int V);

// Adds a Room to an undirected graph.
// 
// args:
// - graph: Graph to add to.
// - src: Source node.
// - dest: Destination node.
void addEdge(Map* map, int src, int dest);

// A utility function to print the adjacency list.
// representation of graph.
void printGraph();

// this function prints the Map, it can be modified later e.g. we can print the ID of each room in the boxes
void printMap(Entity *entity);

// Utility function to find connected rooms from the room given 
// 
// args:
// - id: Id of room.
void connectedRooms(int id);

// this function sets the default values and configuration for the Map, 
// for now the defualt values are based on the Discord Map
void defultMap(struct Map* Map);
