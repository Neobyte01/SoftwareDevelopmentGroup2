#pragma once
#include "map/room.h"

// Graph library
// Contains graph that is the basis for the map.

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
} Room;

// A structure to represent a graph. A graph.
// is an array of adjacency lists.
// Size of array will be V (number of vertices.
// in graph)
typedef struct Graph {
	int V;
	struct Room* array;
} Graph;

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
Graph* createGraph(int V);

// Adds a Room to an undirected graph.
// 
// args:
// - graph: Graph to add to.
// - src: Source node.
// - dest: Destination node.
void addEdge(Graph* graph, int src, int dest);

// A utility function to print the adjacency list.
// representation of graph.
//
// args:
// - graph: Graph to print.
void printGraph(Graph* graph);

// Utility function to find connected rooms from the room given 
// 
// args:
// - id: Id of room.
// - graph: Graph with room in it.
void connectedRooms(int id, Graph* graph);