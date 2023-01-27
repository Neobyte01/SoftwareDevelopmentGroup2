#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"



// A utility function to create a new edge
struct Edge* newRoom(int dest)
{
	struct Edge* newNode = (struct Edge*)malloc(sizeof(struct Edge));
	newNode->dest = dest;
    
	newNode->next = NULL;
	return newNode;
}






// A utility function that creates a graph of V Rooms
struct Graph* createGraph(int V)
{
	struct Graph* graph
		= (struct Graph*)malloc(sizeof(struct Graph));
	graph->V = V;

	
	graph->array = (struct Room*)malloc(
		V * sizeof(struct Room));

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].id = i;
		graph->array[i].type = Corridor;
		graph->array[i].head = NULL;

	return graph;
}





// Adds edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
	
	struct Edge* check = NULL;
	struct Edge* newNode = newRoom(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {

		check = graph->array[src].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

	

	newNode = newRoom(src);
	if (graph->array[dest].head == NULL) {
		newNode->next = graph->array[dest].head;
		graph->array[dest].head = newNode;
	}
	else {
		check = graph->array[dest].head;
		while (check->next != NULL) {
			check = check->next;
		}
		check->next = newNode;
	}

}


void Move(struct Graph* graph){

	// Add som condition later 
	connectedRooms(curRoomId,graph);
	printf("Room to Move: ");
	scanf("%d",&curRoomId);

	printf("the current room is: %d(%s)\n", graph->array[curRoomId].id, RoomNames[graph->array[curRoomId].type]);
}


// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		connectedRooms(v,graph);
		
		printf("\n");
	}
}


// a utility function to find connected rooms from the room given 
void connectedRooms(int id, struct Graph* graph){

    struct Edge* pCrawl = graph->array[id].head;
    printf("\nFrom room %d you can move to the following rooms:\n", id);
    while (pCrawl) {
			printf("%d(%s)\n", pCrawl->dest,RoomNames[graph->array[pCrawl->dest].type]);
			pCrawl = pCrawl->next;
		}
		printf("\n");
}



