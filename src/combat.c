#include "combat.h"

// Helper function declarations
static void printCombatMenu();
static void playerAction(Entity *player, Entity *monster, bool *combatFinished);
static void monsterAction(Entity *player, Entity *monster);
static void resolvePlayerAttack(Entity *player, Entity *monster, bool *combatFinished);
static void resolveHide(Entity *player, Entity *monster, bool *combatFinished);
static void resolveFlee(Entity *player, Entity *monster, bool *combatFinished);
static void resolveItemUse(Entity *player, Entity *monster, bool *combatFinished);
static void performTest(Entity *player, Entity *monster, bool *combatFinished, int testFlag);

bool combat(Entity *player, Entity *monster, int testFlag)
{
    bool combatFinished = false;
    if(testFlag == 0)   // Normal operation, no tests performed
    {
        system("cls");
        printf("\nCombat has commenced!\n\n");
        while(!combatFinished)      //Combat loop, should initiative be decided by DEX-stat? Should it always be player first?
        {
            printCombatMenu();                                  // Roughly implemented, should it be part of the loop?
            playerAction(player, monster, &combatFinished);     // Begun, WIP
            if(monster->currentHP > 0 && !combatFinished)
            {
                monsterAction(player, monster);                 // Not started
            }
            if(player->currentHP <= 0) combatFinished = true;
            break;
        }
    }else // Perform unit tests
    {
        performTest(player, monster, &combatFinished, testFlag);
    }
    if(player->currentHP <= 0) return false;    // Player died during combat
    return true;                                // Player survived combat
}

void printCombatMenu()
{
    printf("--- Choose your Action ---\n  1. Attack\n  2. Hide\n  3. Flee\n  4. Use Item\n--------------------------\n");
}

void playerAction(Entity *player, Entity *monster, bool *combatFinished)     // WIP, will see changes as further details are decided
{
    int answer;
    int i = 0;
    while(i == 0)
    {
        printf("?: ");

        scanf("%d", &answer);
        puts("");

        switch(answer)
        {
        case 1:
            resolvePlayerAttack(player, monster, combatFinished);
            i = 1;
            break;
        case 2:
            //Hiding logic goes here, requires further discussion about room types
            resolveHide(player, monster, combatFinished);
            i = 1;
            break;
        case 3:
            //Flee logic goes here, requires grid movement system
            resolveFlee(player, monster, combatFinished);
            i = 1;
            break;
        case 4:
            //Item logic goes here, requires further discussions about item types/abilities
            resolveItemUse(player, monster, combatFinished);
            i = 1;
            break;
        default:
            printf("Please select a valid Action!\n");
            break;
        }
    }
}

void resolvePlayerAttack(Entity *player, Entity *monster, bool *combatFinished)
{
    if(player->DMG - monster->DEF > 0)  // If the attack goes through the monsters defense...
    {
        monster->currentHP -= (player->DMG - monster->DEF);
        printf("You wounded the monster!\n");
        if(monster->currentHP <= 0)
        {
            printf("The monster has perished!\n");
            *combatFinished = true;
            // Trigger monster death effect (Respawn, deal damage to player, resist death?), 
            // requires discussion and implementetation of monster
        }
    }else   // Attack is too weak...
    {
        printf("Your attack had no effect!\n");     // Should an attack always deal some minor damage (1 or more?)?
    }
}

void resolveHide(Entity *player, Entity *monster, bool *combatFinished)
{
    printf("Pardon the dust, this feature is not implemented yet (Hide).\n");
    *combatFinished = true;
}

void resolveFlee(Entity *player, Entity *monster, bool *combatFinished)
{
    printf("Pardon the dust, this feature is not implemented yet (Flee).\n");
    *combatFinished = true;
}

void resolveItemUse(Entity *player, Entity *monster, bool *combatFinished)
{
    printf("Pardon the dust, this feature is not implemented yet (Items).\n");
    *combatFinished = true;
}

void monsterAction(Entity *player, Entity *monster)    // WIP, will see changes as further details are decided
{
    // Discussion needed, what actions should the monster take? Always attack, always run away, 
    // weighted chart giving increased probabilities for certain outcomes dependent on monster type?
    
   printf("Pardon the dust, this feature is not implemented yet (Monster Action).\n");
}

// Function used for unit testing (WIP)
void performTest(Entity *player, Entity *monster, bool *combatFinished, int testFlag)
{
    switch(testFlag)
    {
        case 1: // Testing Attack-option (Player kills Monster)
            while(!*combatFinished)
            {
                resolvePlayerAttack(player, monster, combatFinished);
            }
            break;
        case 2: // Testing Hide-option (Player hides from Monster)
            resolveHide(player, monster, combatFinished);
            break;
        case 3: // Testing Flee-option (Player flees from Monster)
            resolveFlee(player, monster, combatFinished);
            break;
        case 4: // Testing "Use Items"-option
            resolveItemUse(player, monster, combatFinished);
            break;
        default:
            printf("Invalid testFlag was set, please try again!\n");
            break;
    }
}