#include "map/generation.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

void testGenerateMap() {
    struct Map *map = generateMap();
    assert(map != NULL);
    free(map);
}

#ifdef TEST
int main(void) {
    puts("Running tests...");
    testGenerateMap();
    puts("Done.");
}
#endif