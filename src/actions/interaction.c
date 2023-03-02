#include "actions/interaction.h"
#include "entities/monsters.h"
#include "entities/player.h"
#include "map/map.h"
#include <stdbool.h>

void searchRoom(Entity *player, Map *map) {
    printf("\nYou are currently in %s\n", map->array[player->roomId].name);
    printf("%s\n", map->array[player->roomId].description);
}

static int* createGridMap(int width, int height) {
    int *grid_map = malloc(sizeof(int) * width * height);
    if (grid_map == NULL) return NULL;

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++)
            grid_map[x + y * width] = -1;

    return grid_map;
}

static void destroyGridMap(int* grid_map) {
    if (grid_map != NULL) 
        free(grid_map);
    
    grid_map = NULL;
}

static int *expandMap(int *grid_map, int *width, int *height, int x_inc, int y_inc, int x_off, int y_off) {
    int *new_map = createGridMap((*width)+x_inc, (*height)+y_inc);

    int width_offset = x_inc - x_off;

    for (int x = 0; x < (*width); x++)
        for (int y = 0; y < (*height); y++)
            new_map[(x+x_off) + (y+y_off) * ((*width)+width_offset)] = grid_map[x + y * (*width)];

    (*width) += x_inc;
    (*height) += y_inc;

    destroyGridMap(grid_map);

    return new_map;
}

static int findCoordinate(int *grid_map, int width, int height, int room_id) {
    int coord;
    
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            coord = x + y * width;

            if (grid_map[coord] == room_id) 
                return coord;
        }
    }

    return -1;
}   

void outputTerminalMap() {
    int width = 1;
    int height = 1;

    int *grid_map = createGridMap(width, height);

    Room room;
    int coord;
    int x;
    int y;

    int checked_rooms[globalMap->V];
    int no_checked_rooms = 0;

    grid_map[0] = 0;

    int i = 0;
    while (i != -1) {
        room = globalMap->array[i];
        
        checked_rooms[no_checked_rooms] = i;
        no_checked_rooms++;

        coord = findCoordinate(grid_map, width, height, i);
        x = coord % width;
        y = (coord - x) / width;

        if (room.up != NULL) {
            if (y == 0) {
                grid_map = expandMap(grid_map, &width, &height, 0, 1, 0, 1);  
                y++;
            }

            grid_map[x + (y-1) * width] = room.up->id;
        }
        if (room.right != NULL) {
            if (x == (width - 1)) 
                grid_map = expandMap(grid_map, &width, &height, 1, 0, 0, 0);
            
            grid_map[(x+1) + y * width] = room.right->id;
        }
        if (room.down != NULL) {
            if (y == (height - 1)) 
                grid_map = expandMap(grid_map, &width, &height, 0, 1, 0, 0);
            
            grid_map[x + (y+1) * width] = room.down->id;
        }
        if (room.left != NULL) {
            if (x == 0) {
                grid_map = expandMap(grid_map, &width, &height, 1, 0, 1, 0);
                x++;
            }
            
            grid_map[(x-1) + y * width] = room.left->id;
        }

        i = -1;
        bool checked = false;
        for (int xi = 0; xi < width; xi++) {
            for (int yi = 0; yi < height; yi++) {
                coord = xi + yi * width;

                if (grid_map[coord] == -1) continue;

                for (int j = 0; j < no_checked_rooms; j++) {
                    if (grid_map[coord] == checked_rooms[j]) {
                        checked = true;
                        break;
                    }
                }

                if (!checked) {
                    i = grid_map[coord];
                    break;
                } else {
                    checked = false;
                }
            }

            if (i != -1) break;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            char output[] = "   ";
            int room_id = grid_map[x + y * width];

            if (room_id != -1) {
                if (globalMap->array[room_id].type == CORRIDOR) {
                    output[1] = '.';
                } else {
                    output[0] = '[';
                    output[2] = ']';
                }

                if (player->roomId == room_id) {
                    output[1] = '*';
                } else {
                    for (int m = 0; m < noMonsters; m++) {
                        if (monsters[m]->roomId == room_id) {
                            output[1] = 'x';
                            break;
                        }
                    }
                }
            }

            printf("%s", output);
        }

        printf("\n");
    }

    destroyGridMap(grid_map);
}