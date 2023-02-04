#ifndef  Map_H_ /* Include guard */
#define  Map_H_


enum RoomType{

	Corridor, 
	DinnerHall,
	SleepingQuarter,
	CommonRoom,
	TerminalRoom,
	Kitchen

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
	struct Object* Objects; 
};




struct Object {

	// we can add items to this section later 
}; 

int X = 5; // this is temporary, this indicates the maximum number of Objects each room can have 


// A structure to represent a Map
// is an array of adjacency lists.
// Size of array will be V (number of vertices
// in Map)
struct Map {
	int V;
	struct Room* array;
	int curRoomId;
};


//struct Map* GlobalMap; 


// the name of the rooms
const char* RoomNames[] = {"Corridor", "DinnerHall", "SleepingQuarter", "CommonRoom", "TerminalRoom"};


// A utility function to create a new adjacency list node i.e. Room 
struct Edge* newRoom(int dest);



// A utility function that creates a Map of V Rooms
struct Map* createMap(int V);

// Adds a Room to an undirected Map
void addEdge(struct Map* Map, int src, int dest);





// this function sets the default values and configuration for the Map, 
// for now the defualt values are based on the Discord Map
void defultMap(struct Map* Map);





//this function is used when we print the Map, it checks where the current room is 
//and prints a '*' to make it easier for user to see where we are in the Map
char check(int n);


// a utility function to find connected rooms from GlobalMaps currentRoom 
void connectedRooms();


// a utility function to move between rooms
void Move();





#endif


