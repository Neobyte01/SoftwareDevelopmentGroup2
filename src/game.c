#include <stdbool.h>
#include <stddef.h>
#include "game.h"
#include "menu.h"
#include "entity.h"

entity *player = NULL;
entity** monsters = NULL;

static void setup_game();
static void game_loop();

// Initalize and run the game.
void run_game() {
    // Game start and reset loop.
    while (true) {
        printMainMenu();
        int command = commandMainMenu();

        switch (command) {
        case 1:
            setup_game();
            game_loop();
            printf("Ended game. Resetting...\n");
        case -1:
            exit(0);
        default:
            exit(-1);
        }
    }
}

// Setup a game
void setup_game() {
    if (player != NULL) {
        freeEntity(player);
    }

    player = createEntity("Anita Shidd", 0, 0, 10, 0, 2, 4);

    monsters[0] = createEntity("Rabbities", 1, 3, 1, 0, 0, 2);
    
    // create_map();
}

// Main gameplay loop.
void game_loop() {
    while (true) {
        printf("Running the main game loop\n"); // Temporary message

        // Place the game logic that needs to be run repeatedly
        // like: the player deciding on a move, monsters moving 
        // and combat. 

        break; // Temporary break
    }
}