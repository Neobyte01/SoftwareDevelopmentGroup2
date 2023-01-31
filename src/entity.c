#include "entity.h"

entity* createEntity(char name[10], entityType type, entityBehaviour beh, int HP, int DMG, int DEF, int DEX)
{
    // Create pointer to entity in memory
    entity* ePtr = (entity*) malloc(sizeof(struct entity));

    // Assign integer values
    ePtr->maxHP = HP;
    ePtr->currentHP = ePtr->maxHP;
    ePtr->DMG = DMG;
    ePtr->DEF = DEF;
    ePtr->DEX = DEX;

    // Assign character values
    strcpy(name, ePtr->name);
    ePtr->type = type;
    ePtr->behaviour = beh;
    strcpy(NULL, ePtr->description);

    // ePtr->room = room;
    // ePtr->pos = pos;

    return(ePtr);
}

void freeEntity(entity* ePtr)
{
    free(ePtr);
}

void printDesc(entity* item) {
    system("cls");
    printf(item->description);
    printf("Press any button to return");
    scanf("");
}

void attachEntity(entity* primary, entity* secondary) {
    
    primary->maxHP += secondary->maxHP;
    primary->currentHP += secondary->currentHP;
    primary->DMG += secondary->DMG;
    primary->DEF += secondary->DEF;
    primary->DEX += secondary->DEX;

    primary->attached[primary->num] = secondary;
    primary->num++;
}

void commandItemMenu(entity** items) {
    
    int answer;
    int noOfItems = (sizeof(items)/sizeof(entity*));

    system("cls");
    printItemMenu(items, noOfItems);
    printf("?: ");
    fflush(stdin);
    scanf("%d", &answer);
    puts("");

    int i = 0;

    // Have to use if-statement since we have a dynamic array
    while (i == 0) {
        if (answer == -1) {
            i = 1;
        }
        else if (answer >= 1 && answer <= noOfItems) {
            printDesc(items[answer - 1]);
        }
        else {
            puts ("\nPlease enter a valid input!\n");
        }
        if (i == 0) {
            system("cls");
            printItemMenu(items, noOfItems);
            printf("?: ");
            fflush(stdin);
            scanf("%d", &answer); 
            puts("");
        }
    }
}

void printItemMenu(entity** items, int num) {

    printf("What item would you like to examine?");
    for (int i = 1; i <= num; i++) {
        printf(i + ": ");
        printf(items[i]->name);
        puts("");
    }
}

