#include <stdio.h>
#include <stdlib.h>
#include "map.h"


struct Map* GlobalMap; 


// A utility function to create a new edge
struct Edge* newRoom(int dest)
{
	struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
	newNode->dest = dest;
    
	newNode->next = NULL;
	return newNode;
}






// A utility function that creates a Map of V Rooms
struct Map* createMap(int V)
{
	struct Map* Map = (struct Map*)malloc(sizeof(struct Map)); Map->V = V;

	Map->array = (struct Room*)malloc(V * sizeof(struct Room));

	Map->curRoomId = 1; 

	int i;
	for (i = 0; i < V; ++i){
		Map->array[i].id = i;
		Map->array[i].type = Corridor;
		Map->array[i].Objects =  (struct Object*)malloc(X * sizeof(struct Object));
		Map->array[i].head = NULL;
	}


	defultMap(Map);


	return Map;
}





// Adds edge to an undirected Map
void addEdge(struct Map* Map, int src, int dest)
{
	
	struct Edge* check = NULL;
	struct Edge* newNode = newRoom(dest);

	if (Map->array[src].head == NULL) {
		newNode->next = Map->array[src].head;
		Map->array[src].head = newNode;
	}
	else {

		check = Map->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

	

	newNode = newRoom(src);
	if (Map->array[dest].head == NULL) {
		newNode->next = Map->array[dest].head;
		Map->array[dest].head = newNode;
	}
	else {
		check = Map->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

}



/*
this function is used when we print the Map, it checks where the current room is 
and prints a '*' to make it easier for user to see where we are in the Map
*/
char check(int n){


	if(GlobalMap->curRoomId == n){
		return '*';
	}
	else{
		return ' ';  // we can print something eler later 
	}
}






// this function prints the Map, it can be modified later e.g. we can print the ID of each room in the boxes
void printMap(){

	printf("\n ----GAME MAP----\n\n");
	printf("      [%c]      [%c]\n",check(2), check(9));
	printf("   [%c][%c][%c][%c][%c][%c][%c]\n", check(1),check(3), check(5), check(6), check(10),check(11),check(13));
	printf("      [%c]   [%c]   [%c]\n",check(4),check(7), check(12));
	printf("            [%c]   [%c]\n",check(8),check(14));
	printf("            \n");
    
	connectedRooms();

}




/*
 this function sets the default values and configuration for the Map, 
 for now the defualt values are based on the Discord Map
*/
void defultMap(struct Map* Map)
{

		

    addEdge(Map, 1, 3);
	addEdge(Map, 3, 2);
    addEdge(Map, 3, 4);
    addEdge(Map, 3, 5);
	addEdge(Map, 5, 6);
	addEdge(Map, 6, 7);
	addEdge(Map, 7, 8);

	addEdge(Map, 6, 10);
    addEdge(Map, 10, 9);
    addEdge(Map, 10, 11);
    addEdge(Map, 11, 12);
    addEdge(Map, 12, 14);
	addEdge(Map, 11, 13);



	Map->array[1].type = SleepingQuarter;
	Map->array[2].type = SleepingQuarter;
	Map->array[4].type = SleepingQuarter;
	Map->array[3].type = CommonRoom;
	Map->array[7].type = DinnerHall;
	Map->array[8].type = Kitchen;
	Map->array[9].type = TerminalRoom;



}



/*
 this function can be used to move between rooms, it takes the ID of the room we want to move to
*/
void Move(int roomID){

	GlobalMap->curRoomId = roomID; 
}






void connectedRooms(){

    struct Edge* pCrawl = GlobalMap->array[GlobalMap->curRoomId].head;
    printf("\nFrom room %d you can move to the following rooms:\n", GlobalMap->curRoomId);
    while (pCrawl) {
			printf("%d(%s)\n", pCrawl->dest,RoomNames[GlobalMap->array[pCrawl->dest].type]);
			pCrawl = pCrawl->next;
		}
		printf("\n");
}










