#include <stdbool.h>
#include <stddef.h>
#include "game.h"
#include "menu.h"
#include "entities/player.h"
#include "entities/monsters.h"
#include "actions/action.h"
#include "combat.h"
#include "colors.h"
#include "map/map.h"
#include "map/generation.h"

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
            printf(ANSI_COLOR_GREY "(type 'help' for helpful commands)\n\n" ANSI_COLOR_RESET);
            printMap(player);
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
    globalMap = generateMap();

    setupPlayer();
    player->roomId = 2;

    Entity *blargh = createBlargh();
    blargh->roomId = 12;

    addMonster(blargh);
}

void gameLoop() {
    int exit = 0;
    int in_combat = 0;
    int left_combat = 0;
    int bs;
    Entity *found_monster;

    while (true) {

        // Check for monsters in the same room as player.
        if (left_combat == 0) {
            for (int i = 0; i < noMonsters; i++) {
                if (player->roomId == monsters[i]->roomId) {
                    in_combat = 1;
                    found_monster = monsters[i];
                    break;
                }
            }
        }

        // Enter combat or exploration
        if (in_combat == 1 && left_combat == 0) {
            left_combat = 0;
            combat(player, found_monster, bs);

            if (player->currentHP <= 0) // The player has died in combat
            {
                printf("You have perished and failed to escape! \n -----Game Over-----\n");
                // Enter Death Menu
            }
            else if (found_monster->currentHP <= 0) // The player killed the monster
            {
                for (int i = 0; i < noMonsters; i++) {
                    if (found_monster == monsters[i]){
                        // Remove the monster from the list and move it to room 0
                        // destroyEntity(found_monster);
                    }
                }
            }
            else // The player left combat, but did not kill the monster (hide)
            {
                printf("You are no longer in combat\n");
                left_combat = 1;
            }
            
            // Player is no longer in combat
            in_combat = 0;
        } else {
            playerAction(player, &exit, NULL);
            left_combat = 0;

            if (exit == 1) return;

            for (int i = 0; i < noMonsters; i++)
                monsterAction(monsters[i]);
        }
    }
}