#include "map/map.h"
#include <stdio.h>
#include <stdlib.h>

// ...
static char check(int n, int roomId);

const char* RoomNames[10] = {"Corridor", "Dinner hall", "Sleeping quarter", "Common room", "Terminal room"};

struct Edge* newEdge(int dest) {
	struct Edge* newNode = malloc(sizeof(struct Edge));
	newNode->dest = dest;
    
	newNode->next = NULL;
	return newNode;
}

struct Map* createMap(int V) {
	struct Map* Map = (struct Map*)malloc(sizeof(struct Map)); Map->V = V;

	Map->array = (struct Room*)malloc(V * sizeof(struct Room));

	int i;
	for (i = 0; i < V; ++i){
		Map->array[i].id = i;
		Map->array[i].type = CORRIDOR;
		Map->array[i].Objects =  (struct Object*)malloc(MAX_OBJECTS * sizeof(struct Object));
		Map->array[i].head = NULL;
	}

	defultMap(Map);

	return Map;
}

void addEdge(struct Map* Map, int src, int dest) {
	struct Edge* check = NULL;
	struct Edge* newNode = newEdge(dest);

	if (Map->array[src].head == NULL) {
		newNode->next = Map->array[src].head;
		Map->array[src].head = newNode;
	} else {
		check = Map->array[src].head;
		while (check->next != NULL)
			check = check->next;

		check->next = newNode;
	}

	newNode = newEdge(src);
	if (Map->array[dest].head == NULL) {
		newNode->next = Map->array[dest].head;
		Map->array[dest].head = newNode;
	} else {
		check = Map->array[dest].head;
		while (check->next != NULL)
			check = check->next;
		
		check->next = newNode;
	}

}

void printGraph() {
	int v;
	
	for (v = 0; v < globalMap->V; ++v) {
		connectedRooms(v);
		printf("\n");
	}
}

char check(int n, int roomId) {
    return roomId == n ? '*' : ' ';
}

void printMap(Entity *entity) {
    int id = entity->roomId;

	printf("      [%c]      [%c]\n",check(2, id), check(9, id));
	printf("   [%c][%c][%c][%c][%c][%c][%c]\n", check(1, id),check(3, id), check(5, id), check(6, id), check(10, id),check(11, id),check(13, id));
	printf("      [%c]   [%c]   [%c]\n",check(4, id),check(7, id), check(12, id));
	printf("            [%c]   [%c]\n",check(8, id),check(14, id));
	printf("            \n");
}

void defultMap(struct Map* Map) {
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

	Map->array[1].type = SLEEPING_QUARTER;
	Map->array[2].type = SLEEPING_QUARTER;
	Map->array[4].type = SLEEPING_QUARTER;
	Map->array[3].type = COMMON_ROOM;
	Map->array[7].type = DINNER_HALL;
	Map->array[8].type = KITCHEN;
	Map->array[9].type = TERMINAL_ROOM;
}

void connectedRooms(int id) {
    struct Edge* pCrawl = globalMap->array[id].head;
    printf("\nFrom room %d you can move to the following rooms:\n", id);
 
    while (pCrawl) {
        printf("%d(%s)\n", pCrawl->dest,RoomNames[globalMap->array[pCrawl->dest].type]);
        pCrawl = pCrawl->next;
    }
 
    printf("\n");
}
