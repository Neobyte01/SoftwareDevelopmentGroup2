#include <stdbool.h>
#include <stddef.h>
#include "game.h"
#include "menu.h"
#include "entity.h"
#include "action.h"

entity *player = NULL;
entity *monsters = NULL;

static void setup_game();
static void game_loop();

// Initalize and run the game.
void run_game() {
    // Game start and reset loop.
    while (true) {
        // printMainMenu();
        // int command = commandMainMenu(); 

        int command = 1; // Temporarily bypass menu so it's easier to run the program 

        switch (command) {
        case 1:
            setup_game();
            puts("\nYou find yourself inside the sleeping quarters naked and alone.\n");            
            game_loop();
            puts("\nEnded game. Resetting...");
        case -1:
            exit(0);
        default:
            exit(-1);
        }
    }
}

// Setup a game
void setup_game() {
    // create_map();

    if (player != NULL) freeEntity(player);

    player = createEntity("Anita Shidd", Player, none);
    player->DMG = 0;
    player->DEF = 2;

    // Setup monsters and place them at "random"
}

// Main gameplay loop.
void game_loop() {
    while (true) {
        entity *monster = createEntity("Blurgh", Monster, none);

        monster_action(monster);

        // if player and monster is in the same room
        //     combat(player, monster)
        
        // else

        //     display_surroundings(player);
        //     perform_action(player);

        //     for (monster in monsters) 
        //         perform_action(monster);

        break; // Temporary break
    }
}