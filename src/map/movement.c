#include "map/movement.h"
#include "entities/player.h"
#include "map/map.h"

int moveEntity(Entity *entity, enum Direction dir) {
    int id = entity->roomId;
	int moved;

    switch(dir){
        case UP:
			moved = moveUp(id,entity);
			break;
        case DOWN:
			moved = moveDown(id,entity);
			break;
        case RIGHT:
			moved = moveRight(id,entity);
			break;
        case LEFT:
			moved = moveLeft(id,entity);
			break;
        default:
			break;
    }

	return moved;
}

int moveLeft(int id,Entity *entity) {
	if(globalMap->array[id].left != NULL){
		entity->roomId =  globalMap->array[id].left->id;
		return 1;
	} else{
		return 0;
	}
}

int moveRight(int id,Entity *entity) {
	if(globalMap->array[id].right != NULL){
		entity->roomId =  globalMap->array[id].right->id;
		return 1;
	} else {
		return 0;
	}
}

int moveUp(int id,Entity *entity) {
	if(globalMap->array[id].up != NULL){
		entity->roomId =  globalMap->array[id].up->id;
		return 1;
	} else {
		return 0;
	}
}

int moveDown(int id, Entity *entity){
	if(globalMap->array[id].down != NULL){
		entity->roomId =  globalMap->array[id].down->id;
		return 1;
	} else {
		return 0;
	}
}