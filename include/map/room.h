#pragma once

// Room library
// Handles the rooms and information connected to the rooms.

enum RoomType{
	Corridor, 
	DinnerHall,
	SleepingQuarter,
	CommonRoom,
	TerminalRoom,
}; 

struct roomStructure {
    int roomNr;
    int item1, item2;
    float temp;
    char roomDescription[50];

};

/*
Map Text Format:

    []      []
  [][][][][][][]
    []  []  []
        []  []
            []

*/
