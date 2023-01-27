#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"



// A utility function to create a new adjacency list node i.e. Room 
struct Room* newRoom(int dest)
{
	struct Room* newNode = (struct Room*)malloc(sizeof(struct Room));
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

	
	graph->array = (struct AdjList*)malloc(
		V * sizeof(struct AdjList));

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].head = NULL;

	return graph;
}





// Adds a Room to an undirected graph
void addEdge(struct Graph* graph, int src, int dest)
{
	
	struct Room* check = NULL;
	struct Room* newNode = newRoom(dest);

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




// A utility function to print the adjacency list
// representation of graph
void printGraph(struct Graph* graph)
{
	int v;
	for (v = 0; v < graph->V; ++v) {
		struct Room* pCrawl = graph->array[v].head;
		printf("\nFrom room %d you can go to the following rooms:\n", v);
		while (pCrawl) {
			printf("%d,", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
	}
}


// a utility function to find connected rooms from the room given 
void connectedRooms(int id, struct Graph* graph){

    struct Room* pCrawl = graph->array[id].head;
    printf("\nFrom room %d you can go to the following rooms:\n", id);
    while (pCrawl) {
			printf("%d,", pCrawl->dest);
			pCrawl = pCrawl->next;
		}
		printf("\n");
}