#include "menu.h"
#include "combat.h"

void commandMenu (void) 
{
    
    int answer;
    atexit(exitPrint);

    printf("?: ");

    scanf("%d", &answer);
    puts("");

    int i = 0;
    player p = {.ID = 3,.currentHP = 3,.maxHP = 3,.DEX = 3,.DMG = 3,.DEF = 3,.posX = 3,.posY = 3,.items = NULL,.noItems = 0};
    monster m = {.ID = 2,.currentHP = 10,.maxHP = 10,.DEX = 2,.DMG = 2,.DEF = 2,.posX = 3,.posY = 3};
    while (i == 0) 
    {
        switch (answer)
        {
        case 1:
            // Call function to start game.
            printWIP();
            break;
        case 2:
            // Call function to select file to be loaded.
            printWIP();
            break;
        case 3:
            // Initiate combat
            combat(&p,&m);
            break;
        case -1:
            i = 1;
            break;
        default:
            puts ("\nPlease enter a valid input!\n");
            break;
        }
        if (i == 0) {
            system("cls");
            printMainMenu();
            printf("?: ");
            fflush(stdin);
            scanf("%d", &answer); 
            puts("");
        }

    }
}

void printMainMenu(void) 
{
    printf("------------------------------------------\n Menu \n------------------------------------------\n");
    printf("1: Start Game.\n2: Load Save.\n3: Initiate combat. \n-1: Quit\n------------------------------------------\n\n");
}

void exitPrint(void)
{
    printf("Exiting...\n");
}

void printWIP(void) 
{
    printf("This feature has no yet been implemented.\n");
    printf("Press any button to return\n");
}