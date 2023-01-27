#ifndef GRAPH_H_ /* Include guard */
#define GRAPH_H_

// A structure to represent an adjacency list node i.e. Room 
struct Room {
	int dest;
	struct Room* next;
};


// A structure to represent an adjacency list
struct AdjList {
	struct Room* head;
};



// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph {
	int V;
	struct AdjList* array;
};



// A utility function to create a new adjacency list node i.e. Room 
struct Room* newRoom(int dest);



// A utility function that creates a graph of V Rooms
struct Graph* createGraph(int V);

// Adds a Room to an undirected graph
void addEdge(struct Graph* graph, int src, int dest);


// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph);



// a utility function to find connected rooms from the room given 
void connectedRooms(int id, struct Graph* graph);

#endif
