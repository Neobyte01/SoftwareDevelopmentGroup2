#include "Graph.h"
#include<stdio.h>


// Driver program to test the Graph 
void testGraph()
{
	int V = 9;
	struct Graph* graph = createGraph(V);
	

    addEdge(graph, 0, 3);
	addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
	addEdge(graph, 2, 5);
	addEdge(graph, 3, 4);
	addEdge(graph, 3, 6);
	addEdge(graph, 4, 7);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 8);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);
	
	printGraph(graph);

    int roomId; 
    printf("Enter the roomId to find all connected rooms: ");
    scanf("%d", &roomId);
    connectedRooms(roomId, graph);


	
}

