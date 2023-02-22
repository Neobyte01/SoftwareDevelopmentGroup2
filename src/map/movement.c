#include "map/movement.h"
#include "entities/player.h"
#include "map/map.h"

int moveEntity(Entity *entity, enum Direction dir) {
    int id = entity->roomId;
	int moved;

    switch(dir){
        case UP:
			moved = moveUp(id);
			break;
        case DOWN:
			moved = moveDown(id);
			break;
        case RIGHT:
			moved = moveRight(id);
			break;
        case LEFT:
			moved = moveLeft(id);
			break;
        default:
			break;
    }

	return moved;
}

int moveLeft(int id) {
	if(globalMap->array[id].left != NULL){
		player->roomId =  globalMap->array[id].left->id;
		return 1;
	} else{
		printf("Can't move to the left\n");
		return 0;
	}
}

int moveRight(int id) {
	if(globalMap->array[id].right != NULL){
		player->roomId =  globalMap->array[id].right->id;
		return 1;
	} else {
		printf("Can't move to the right\n");
		return 0;
	}
}

int moveUp(int id) {
	if(globalMap->array[id].up != NULL){
		player->roomId =  globalMap->array[id].up->id;
		return 1;
	} else {
		printf("Can't move to the up-side\n");
		return 0;
	}
}

int moveDown(int id){
	if(globalMap->array[id].down != NULL){
		player->roomId =  globalMap->array[id].down->id;
		return 1;
	} else {
		printf("Can't move to the down-side\n");
		return 0;
	}
}