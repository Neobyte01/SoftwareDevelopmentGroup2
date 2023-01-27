#include "map.h"

void create_map() {
    map = createGraph(5);

    addEdge(map, 0, 1);
    addEdge(map, 1, 2);
    addEdge(map, 2, 3);
    addEdge(map, 3, 4);
    addEdge(map, 4, 5);

    printGraph(map);
}