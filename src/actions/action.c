#include "actions/action.h"
#include "actions/interaction.h"
#include "actions/types.h"
#include <stdlib.h>
#include <time.h>

// Natural language command.
static void getCommand();

void playerAction(Entity *player) {
    // - move(entity, directions)

    // - search <object>
    // - take <object>
    // - read <object>
    // - hit <object>

    // - item action 

    // - view person

    // - help 

    // ?: ...

    // ?: help (HELP, help, hel, he, h) -> gets list of instructions

    // ?: search -> help for search <object>
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

void getCommand() {
    // TODO: implement this function.
}