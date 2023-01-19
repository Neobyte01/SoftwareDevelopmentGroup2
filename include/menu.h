#ifndef menu_h
#define menu_h

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// ---------
// Functions
// ---------

// This function handles the logic of the main menu.
void commandMenu (void);

// This function prints the main menu to the console.
void printMainMenu (void);

// This function prints a message when the console is closed.
void exitPrint(void);

// This function prints a message that a feature is WIP
void printWIP(void);

#endif