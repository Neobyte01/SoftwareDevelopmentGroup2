
#ifndef gridMove_h
#define gridMove_h

#include<stdio.h>

typedef enum Move{

    Left,
    Right,
    Up,
    Down,
}Move; 

// ---------
// Functions
// ---------

 void makeMove(Move *, int[10][10]);

#endif

