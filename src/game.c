#include <stdbool.h>
#include <stddef.h>
#include "game.h"
#include "menu.h"
#include "entities/player.h"
#include "entities/monsters.h"
#include "actions/action.h"
#include "map/map.h"

// Setup a game
static void setupGame();

// Main gameplay loop.
static void gameLoop();

void runGame() {
    // Game start and reset loop.
    while (true) {
        // printMainMenu();
        // int command = commandMainMenu(); 

        int command = 1; // Temporarily bypass menu so it's easier to run the program 

        switch (command) {
        case 1:
            setupGame();
            puts("\nYou find yourself inside the sleeping quarters naked and alone.\n");            
            gameLoop();
            puts("\nEnding game...");
        case -1:
            exit(0);
        default:
            exit(-1);
        }
    }
}

void setupGame() {
    createMap(15);

    setupPlayer();
    player->roomId = 1;

    Entity *blargh = createBlargh();
    blargh->roomId = 12;

    addMonster(blargh);
}

void gameLoop() {
    int exit = 0;

    while (true) {
        // if player and monster is in the same room
        //     combat(player, monster)
        
        // else...

        printMap(player);
        
        playerAction(player, &exit);

        if (exit == 1) return;

        for (int i = 0; i < noMonsters; i++)
            monsterAction(monsters[i]);
    }
}