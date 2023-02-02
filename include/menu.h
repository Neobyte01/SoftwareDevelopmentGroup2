#pragma once

#include <stdio.h>
#include <stdlib.h>

// Main menu library.
// Allows the program to display a main menu in which
// you can for example start and exit the game.

// This function handles the logic of the main menu.
//
// returns: The selected command.
int commandMainMenu();

// This function prints the main menu to the console.
void printMainMenu();

// This function contains a message that will be printed when the console is closed.
void exitPrint();

// This function prints a message that a feature is WIP.
void printWIP();

// This function enters a short loop that prints the basic instructions of the game
void howToMenu();