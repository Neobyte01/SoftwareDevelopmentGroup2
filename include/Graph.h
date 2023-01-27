#ifndef GRAPH_H_ /* Include guard */
#define GRAPH_H_


enum RoomType{

	Corridor, 
	DinnerHall,
	SleepingQuarter,
	CommonRoom,
	TerminalRoom,

}; 



// A structure to represent connection between rooms
struct Edge {
	int dest;
	struct Edge* next;
};


// A structure to represent a room 
struct Room {
	int id; 
	enum RoomType type;
	struct Edge* head;
};



// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in graph)
struct Graph {
	int V;
	struct Room* array;
};


// the name of the rooms
const char* RoomNames[] = {"Corridor", "DinnerHall", "SleepingQuarter", "CommonRoom", "TerminalRoom"};


int curRoomId = 0; 

// A utility function to create a new adjacency list node i.e. Room 
struct Edge* newRoom(int dest);



// A utility function that creates a graph of V Rooms
struct Graph* createGraph(int V);

// Adds a Room to an undirected graph
void addEdge(struct Graph* graph, int src, int dest);


// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph);



// a utility function to find connected rooms from the room given 
void connectedRooms(int id, struct Graph* graph);

// a utility function to move between rooms
void Move(struct Graph* graph);

#endif


