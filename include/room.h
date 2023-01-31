#ifndef room_h
#define room_h

struct roomStructure {
    int roomNr;
    int item1, item2;
    float temp;
    char roomDescription[50];

};



#endif

/*
Map Text Format:

    []      []
  [][][][][][][]
    []  []  []
        []  []
            []


*/

