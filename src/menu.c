#include <stdbool.h>
#include "menu.h"
#include "combat.h"

int commandMainMenu() {
    int answer;
    atexit(exitPrint);

    printf("?: ");

    scanf("%d", &answer);
    puts("");

    int i = 0;
    while (true)
    {
        switch (answer)
        {
        case 1:
            // Enter How-to Play menu
            howToMenu();
            break;
        case 2:
            break;
        case 3:
            // Call function to select file to be loaded.
            printWIP();
            break;
        case -1:
            return -1;
            break;
        default:
            puts("\nPlease enter a valid input!\n");
            break;
        }
        if (i == 0)
        {
            system("cls");
            printMainMenu();
            printf("?: ");
            fflush(stdin);
            scanf("%d", &answer);
            puts("");
        }
    }
}

void printMainMenu() {
    printf("----------------------------------------------------\n Menu \n----------------------------------------------------\n");
    printf("1: Game Instructions.\n2: Start Game.\n3: Load Save.\n-1: Quit\n----------------------------------------------------\n\n");
}

void exitPrint() {
    printf("Exiting...\n");
}

void printWIP() {
    printf("This feature has no yet been implemented.\n");
    puts("\n\nPress any button to return to main menu");
    fflush(stdin);
}

void howToMenu() {
    fflush(stdin);
    // Basic premise
    printf("\n-------------------------- Welcome to the game --------------------------\n");
    printf("In this game, your objective is to traverse a spaceship that has been taken \nover by monsters and escape using an escape pod.\n");
    printf("You will get to select a character to play as and each one has different \nstarting equipment, allowing for different playstyles.\n");

    // How to use the menu
    printf("\n--------------------------------- Menus ---------------------------------\n");
    printf("As you might've already guessed, this is a text-based game, so to do things \nin the game, you will be given  numbered options (1, 2, ...) and then you \nenter what option you would like to take and press ENTER.\n");

    // Stats
    printf("\n--------------------------------- Stats ---------------------------------\n");
    printf("There are four main stats in this game: \n");
    printf("Hit Points (or HP), which is how much damage you or a monster can take before death.\n");
    printf("Damage (or DMG), wihch is how much damage you or a monster deals with its attacks.\n");
    printf("Defense (or DEF), the amount of HP you or a monster loses by an attack equals DMG - DEF (Minimum of 0).\n");
    printf("Dexterity (or DEX), affects the chance that you or a monster successfully hides. \nIt also affects your ability to flee during combat.\n");

    printf("\nThese stats can be modified by picking up items.\n");

    // Rooms
    printf("\n--------------------------------- Rooms ---------------------------------\n");
    printf("In this game, you move from room to room and in each room you can find items or monsters\n");
    printf("Don't worry though, if a monster is in a nearby room, you might notice \nthe sounds they make as they approach. But be careful since they might do the same.\n");
    printf("There are also some special rooms, such as 'Administration Rooms' \nwhere you will find 'Save Terminals'.\n");

    // Combat
    printf("\n-------------------------------- Combats --------------------------------\n");
    printf("Should you enter the same room as a monster, you will enter combat against that monster.\n");
    printf("In combat, you can choose to:\n");
    printf("Attack: Deal damage to the monster equal to your DMG - Monster DEF.\n");
    printf("Hide: You try to hide from the monster, possbibly avoid it spotting you.\n");
    printf("Flee: You attempt to flee from the monster, returning to the previous room you were in.\n");
    printf("Use Item: You use an item from your inventory, causing an effect detailed by the item");

    puts("\n\nPress any button to return to main menu");
    fflush(stdin);
}
