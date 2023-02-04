#include <stdio.h>
#include <stdlib.h>
#include "map/graph.h"

struct Edge* newEdge(int dest) {
	struct Edge* newNode = malloc(sizeof(struct Edge));
	newNode->dest = dest;
    
	newNode->next = NULL;
	return newNode;
}

struct Graph* createGraph(int V) {
	struct Graph* graph = malloc(sizeof(struct Graph));
	graph->V = V;

	graph->array = malloc(V * sizeof(struct Room));

	int i;
	for (i = 0; i < V; ++i)
		graph->array[i].id = i;
		graph->array[i].type = Corridor;
		graph->array[i].head = NULL;

	return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
	struct Edge* check = NULL;
	struct Edge* newNode = newEdge(dest);

	if (graph->array[src].head == NULL) {
		newNode->next = graph->array[src].head;
		graph->array[src].head = newNode;
	}
	else {
		check = graph->array[src].head;
		while (check->next != NULL)
			check = check->next;

		check->next = newNode;
	}

	newNode = newEdge(src);
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

void printGraph(struct Graph* graph) {
	int v;
	
	for (v = 0; v < graph->V; ++v) {
		connectedRooms(v,graph);
		printf("\n");
	}
}
 
void connectedRooms(int id, struct Graph* graph) {
    struct Edge* pCrawl = graph->array[id].head;
    
	printf("\nFrom room %d you can move to the following rooms:\n", id);
    
	while (pCrawl) {
		printf("%d\n", pCrawl->dest);
		pCrawl = pCrawl->next;
	}

	printf("\n");
}