#include "actions/action.h"
#include "actions/interaction.h"
#include "actions/types.h"
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>
#include "map/map.h"
#include "colors.h"
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

// Compare input command with array of valid commands;
// 
// args:
// - command: Input command.
// - valid_commands: List of valid commands.
// - noCommands: Number of valid commands.
//
// returns: Input command is found in array of valid commands.
static bool commandCompare(char *command, char **valid_commands, int noCommands);

// Scan user input.
//
// args:
// - input: String to scan to.
static void scanInput(char *input);

// Give users helpful instructions on writing commands.
static void helpCommand();

char *exit_commands[] = {"exit", "exit game", "quit", "quit game"};
char *move_west_commands[] = {"move west", "move w"};
char *move_east_commands[] = {"move east", "move e"};
char *move_north_commands[] = {"move north", "move n"};
char *move_south_commands[] = {"move south", "move s"};
char *map_commands[] = {"map", "show map", "view map", "open map"};

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
        printf(ANSI_COLOR_BLUE "?: " ANSI_COLOR_RESET);
        scanInput(input);

        if (strcmp(input, "help") == 0) {
            helpCommand();
            // Special command that doesn't affect game loop.
        } else if (commandCompare(input, exit_commands, 4)) {
            printf("Exiting to main menu...\n\n");
            *exitFlag = 1;
            break;
        } else if(commandCompare(input, move_west_commands, 2)){
            moved = moveEntity(player,LEFT);
            if (moved == 1) {
                printf("\nYou walk westward. There you find ");
                describeRoom(globalMap, player->roomId);
            } else {
                printf("Can't move west. There's a wall in the way.\n\n");
            }
            break;
        } else if(commandCompare(input, move_east_commands, 2)){
            moved = moveEntity(player,RIGHT);
            if (moved == 1) {
                printf("\nYou walk eastward. There you find ");
                describeRoom(globalMap, player->roomId);
            } else {
                printf("Can't move east. There's a wall in the way.\n\n");
            }
            break;
        } else if(commandCompare(input, move_north_commands, 2)){
            moved = moveEntity(player,UP);
            if (moved == 1) {
                printf("\nYou walk northward. There you find ");
                describeRoom(globalMap, player->roomId);
            } else {
                printf("Can't move north. There's a wall in the way.\n\n");
            }
            break;
        } else if(commandCompare(input, move_south_commands, 2)){
            moved = moveEntity(player,DOWN);
            if (moved == 1) {
                printf("\nYou walk southward. There you find ");
                describeRoom(globalMap, player->roomId);
            } else {
                printf("Can't move south. There's a wall in the way.\n\n");
            }
            break;
        } else if(commandCompare(input, map_commands, 4)){
            printf("Opening the map...\n\n");
            // delay(200, 20);
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

bool commandCompare(char *command, char **valid_commands, int noCommands) {
    for (int i = 0; i < noCommands; i++)
        if (strcmp(command, valid_commands[i]) == 0) return true;

    return false;
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
    printf("move north: Move northward/upward.\n");
    printf("move south: Move southward/downward.\n");
    printf("move west: Move westward/leftward.\n");
    printf("move east: Move eastward/rightward.\n\n");
    printf("help: Helpful commands.\n");
    printf("exit: Exit back to the main menu.\n");
    printf("\n");
}