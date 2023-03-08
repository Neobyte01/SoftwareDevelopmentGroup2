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

// Resets gameplay loop
static void resetLoop();

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

void resetLoop() {
    // Remove current player entity from memory
    destroyEntity(player);

    // Remove all monsters from memory
    for (int i = 0; i < noMonsters; i++) {
        destroyEntity(monsters[i]);
    }
    noMonsters = 0;

    // Remove map from memory
    destroyMap(globalMap);
}

void gameLoop() {
    int exit = 0;
    int in_combat = 0;
    int left_combat = 0;
    int bs;
    bool loop = true;
    Entity *found_monster;

    while (loop == true) {

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
                printf("\nYou have perished and failed to escape! \n ----- Game Over ----- \n\n");
                char deathCommand;

                // printf("1 to try again. Anything else to return to main menu\n");
                // printf("?: ");
                // fflush(stdin);
                // scanf("%c", &deathCommand);

                deathCommand = '0'; // Set to non 1 value
            
                switch (deathCommand)
                {
                case '1': // Start a new "run"
                    
                    // Rest Loop and setup new game
                    resetLoop();
                    setupGame();

                    // Run new game
                    puts("\nYou find yourself inside the sleeping quarters naked and alone.\n");            
                    printf(ANSI_COLOR_GREY "(type 'help' for helpful commands)\n\n" ANSI_COLOR_RESET);
                    printMap(player);
                    gameLoop();

                    // In case they exit from that game loop (return to main menu), any outer loop will also be exited
                    loop = false;
                    break;
                default: // Return to main menu
                    printf("Returning to main menu...\n\n");
                    resetLoop();
                    loop = false;
                }
            }
            else if (found_monster->currentHP <= 0) // The player killed the monster
            {
                for (int i = 0; i < noMonsters; i++) {
                    if (found_monster == monsters[i]){
                        for (int j = i + 1; j < noMonsters; j++) 
                        {
                            monsters[j - 1] = monsters[j]; // Remove the killed monster from the list of monsters
                        }
                        found_monster->roomId = 0; // Move to non-existing room
                        noMonsters--;
                        destroyEntity(found_monster); // Free the killed monster from memory
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