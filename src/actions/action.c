#include "actions/action.h"
#include "actions/interaction.h"
#include "actions/types.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "map/map.h"
#include "entities/player.h"
#include "map/movement.h"

// Delay the program.
//
// args:
// - ms: Number of milliseconds to delay.
// - rms: Random variability in milliseconds. So resulting 
//        delay is ms +- rms.
static void delay(int ms, int rms);

// Prompt user for input.
//
// returns: Integer assigned to selected command.
static int getCommand();

// Scan user input.
//
// args:
// - input: String to scan to.
static void scanInput(char *input);

// Give users helpful instructions on writing commands.
static void helpCommand();

void playerAction(Entity *player, int *exitFlag) {
    // - search <object>
    // - take <object>
    // - read <object>
    // - hit <object>

    // - item action 

    // - view person

    int command;
    char *input = malloc(SCAN_INPUT_SIZE);

    int moved;

    while (true) {
        printf("?: ");
        scanInput(input);

        if (strcmp(input, "help") == 0) {
            helpCommand();
            // Special command that doesn't affect game loop.
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting to main menu...\n\n");
            *exitFlag = 1;
            break;
        } else if(strcmp(input, "move left") == 0){
            moved = moveEntity(player,LEFT);
            printf("Moving leftward...\n\n");
<<<<<<< HEAD
            //delay(300, 50);
=======
            // delay(300, 50);
            if (moved == 1) {
                printf("You walk to the left. There you find ");
                describeRoom(globalMap, player->roomId);
            }
>>>>>>> a1d99abc3061ff2371e55e72f0806bf46c8d6a36
            break;
        } else if(strcmp(input, "move right") == 0){
            moved = moveEntity(player,RIGHT);
            printf("Moving rightward...\n\n");
<<<<<<< HEAD
           // delay(300, 50);
=======
            // delay(300, 50);
            if (moved == 1) {
                printf("You walk to the right. There you find ");
                describeRoom(globalMap, player->roomId);
            }
>>>>>>> a1d99abc3061ff2371e55e72f0806bf46c8d6a36
            break;
        } else if(strcmp(input, "move up") == 0){
            moved = moveEntity(player,UP);
            printf("Moving upward...\n\n");
<<<<<<< HEAD
            //delay(300, 50);
=======
            // delay(300, 50);
            if (moved == 1) {
                printf("You walk to upward. There you find ");
                describeRoom(globalMap, player->roomId);
            }
>>>>>>> a1d99abc3061ff2371e55e72f0806bf46c8d6a36
            break;
        } else if(strcmp(input, "move down") == 0){
            moved = moveEntity(player,DOWN);
            printf("Moving downward...\n\n");
<<<<<<< HEAD
            //delay(300, 50);
            break;
        } else if(strcmp(input, "map") == 0){
            printf("Opening the map...\n\n");
            //delay(200, 20);
=======
            // delay(300, 50);
            if (moved == 1) {
                printf("You walk to downward. There you find ");
                describeRoom(globalMap, player->roomId);
            }
            break;
        } else if(strcmp(input, "map") == 0){
            printf("Opening the map...\n\n");
            // delay(200, 20);
>>>>>>> a1d99abc3061ff2371e55e72f0806bf46c8d6a36
            printMap(player);
            // Doesn't affect game loop
        } else {
            printf("'%s' is not a recognized command. Type 'help' you're unsure.\n\n", input);    
        } 
    }

    free(input);
}

void monsterAction(Entity *monster) {
    // Remove target if found
    // Make more aggresive when following target
    
    srand(time(NULL));
    int choice = rand() % 10;  // 0-9

    if (choice == 0 && monster->last_action != GROWL) {
        // monster_growl(monster)
        monster->last_action = GROWL;
    } else if (choice == 1 && monster->last_action != SNIFF) {
        // sniff room
        // if player track found then add target
        monster->last_action = SNIFF;
    } else if (choice <= 4) {
        // if player track has been sniffed
        //     find_path_toward_target(room)
        // else
        //     random_path

        // move_entity(monster, direction);
        monster->last_action = MOVE;
    } else {
        // Does nothing
        monster->last_action = WAIT;
    }
}

void delay(int ms, int rms) {
    clock_t start_time = clock();

    srand(time(NULL));
    int delay_time = ms + rand() % (rms * 2) - rms;

    while (clock() < start_time + ms * 1000) {
        // waiting
    }
}

void scanInput(char *input) {
    fgets(input, SCAN_INPUT_SIZE, stdin);

    // Remove any trailing newline
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';

    // Convert to lowercase
    for(int i = 0; input[i]; i++)
        input[i] = tolower(input[i]);

    char *p = input;
    int l = strlen(input);

    // Remove leading/trailing whitespaces
    while(isspace(p[l - 1])) p[--l] = 0;
    while(*p && isspace(* p)) ++p, --l;
    memmove(input, p, l + 1);
}

void helpCommand() {
    printf("\nAvailable commands:\n");
    printf("-----------------------------------\n");
    printf("map: Show your location on the map.\n\n");
    printf("move up: Move upward.\n");
    printf("move down: Move downward.\n");
    printf("move left: Move leftward.\n");
    printf("move right: Move rightward.\n\n");
    printf("help: Helpful commands.\n");
    printf("exit: Exit back to the main menu.\n");
    printf("\n");
}