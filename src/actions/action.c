#include "actions/action.h"
#include "actions/interaction.h"
#include "actions/types.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Prompt user for input.
//
// returns: Integer assigned to selected command.
static int getCommand();

// Scan user input
//
// args:
// - input: String to scan to.
static void scanInput(char *input);

// Give users helpful instructions on writing commands.
static void helpCommand();

void playerAction(Entity *player, int *exitFlag) {
    // - move(entity, directions)

    // - search <object>
    // - take <object>
    // - read <object>
    // - hit <object>

    // - item action 

    // - view person

    // - help 

    int command = getCommand();

    switch (command) {
        case 1: // exit
            printf("Exiting to main menu...\n");
            *exitFlag = 1;
            break;
        default: 
            printf("Error: Command not recongized\n");
            break;
    }
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

int getCommand() {
    int command;
    char *input = malloc(SCAN_INPUT_SIZE);

    while (true) {
        printf("?: ");
        scanInput(input);

        if (strcmp(input, "help") == 0) {
            helpCommand();
            // Special command that doesn't affect game loop.
        } else if (strcmp(input, "exit") == 0) {
            command = 1;
            break;
        } else {
            printf("'%s' is not a recognized command. Type 'help' you're unsure.\n\n", input);    
        }
    }

    free(input);
    return command;
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
    printf("----------------------------------------------------\n");
    printf("help: Helpful instructions on how to write commands.\n");
    printf("exit: Exit back to the main menu.\n");
    printf("\n");
}