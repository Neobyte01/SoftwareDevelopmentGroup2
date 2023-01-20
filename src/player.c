#include "player.h"

player* createPlayer(item** items)
{
    // Create pointer to player in memory
    player* pPtr = (player*) malloc(sizeof(struct player));

    pPtr->maxHP = 25; // Set to base values
    pPtr->currentHP = pPtr->maxHP; // Set to base values
    pPtr->DEF = 0; // Set to base values
    pPtr->DMG = 0; // Set to base values
    pPtr->DEX = 0; // Set to base values
    pPtr->noItems = (sizeof(items)/sizeof(item*));
    // pPtr->posX = x;
    // pPtr->posY = y;
    // pPtr->room = room;


    // For each item to be added, equip it and add to list of items
    for (int i = 0; i <= pPtr->noItems; i++) 
    {
        equipItem(pPtr->items[i], pPtr);
    }

    return(pPtr);
}

void equipItem(item* equip, player* pPtr)
{
    switch(equip->type)
    {
        // Item gives DMG
        case 1: 
            pPtr->DMG += equip->bonus;
            break;
        // Item gives DEF
        case 2:
            pPtr->DEF += equip->bonus;
            break;
        // Item gives DEX
        case 3:
            pPtr->DEX += equip->bonus;
            break;
        // Item gives maxHP
        case 4: 
            pPtr->maxHP += equip->bonus;
            break;
        // Item restores currentHP
        case 5: 
            pPtr->currentHP += equip->bonus;
            break;
        default: 
            printf("Error, missing item type ID\n");
            return;
    }

    // Add item to list of equipped items by player
    pPtr->items[pPtr->noItems - 1] = equip;
}

