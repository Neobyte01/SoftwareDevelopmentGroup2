#include "map/movement.h"
#include "entities/player.h"
#include "map/map.h"

void moveEntity(Entity *entity, enum Direction dir) {
    
    int id = entity->roomId;

    switch(dir){

        case UP:
        moveUp(id);
        break;

        case DOWN:
        moveDown(id);
        break;

        case RIGHT:
        moveRight(id);
        break;

        case LEFT:
        moveLeft(id);
        break;


        default:
        break;

    }
}






void moveLeft(int id){


	if(globalMap->array[id].left != NULL){
		player->roomId =  globalMap->array[id].left->id;
	}
	else{
		printf("Can't move to the left\n");
	}


}


void moveRight(int id){
	
	if(globalMap->array[id].right != NULL){
		player->roomId =  globalMap->array[id].right->id;
	}
	else{
		printf("Can't move to the right\n");
	}

}


void moveUp(int id){
	
	if(globalMap->array[id].up != NULL){
		player->roomId =  globalMap->array[id].up->id;
	}
	else{
		printf("Can't move to the up-side\n");
	}


}




void moveDown(int id){

	if(globalMap->array[id].down != NULL){
		player->roomId =  globalMap->array[id].down->id;
	}
	else{
		printf("Can't move to the down-side\n");
	}


}