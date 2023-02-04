
#include "map.h"
#include<stdio.h>





int main(void){

	GlobalMap = createMap(16);
	printMap();

	Move(10);
	printMap();

	Move(11);
	printMap();


}


