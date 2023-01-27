#include <stdbool.h>
#include "menu.h"
#include "combat.h"

int commandMainMenu (void) 
{
    
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
                // Call function to start game.
                return 1;
                break;
            case 2:
                // Call function to select file to be loaded.
                printWIP();
                return 2;
                break;
            case -1:
                return -1;
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
    printf("1: Start Game.\n2: Load Save.\n-1: Quit\n------------------------------------------\n\n");
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