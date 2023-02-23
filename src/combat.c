#include "combat.h"

// Helper function declarations
static void printCombatMenu();
static void playerAction(Entity *player, Entity *monster, bool *combatFinished);
static void monsterAction(Entity *player, Entity *monster, bool *combatFinished);
static void resolvePlayerAttack(Entity *player, Entity *monster, bool *combatFinished);
static void resolveHide(Entity *player, Entity *monster, bool *combatFinished);
void resolveMonsterAttack(Entity *player, Entity *monster, bool *combatFinished);
static void performTest(Entity *player, Entity *monster, bool *combatFinished, int testFlag);

bool combat(Entity *player, Entity *monster, int testFlag) {
    bool combatFinished = false;
    if(testFlag == 0)   // Normal operation, no tests performed
    {
        printf("\nCombat has commenced!\n");
        while(!combatFinished)      
        {
            printCombatMenu();                                  
            playerAction(player, monster, &combatFinished);     
            if(monster->currentHP > 0 && !combatFinished)
            {
                monsterAction(player, monster, &combatFinished);                 
            }
        }
    }else // Perform unit tests
    {
        performTest(player, monster, &combatFinished, testFlag);
    }
    if(player->currentHP <= 0) return false;    // Player died during combat
    return true;                                // Player survived combat
}

void printCombatMenu() {
    printf("\n--- Choose your Action ---\n  1. Attack\n  2. Hide\n--------------------------\n");
}

void playerAction(Entity *player, Entity *monster, bool *combatFinished) {
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
        default:
            printf("Please select a valid Action!\n");
            break;
        }
    }
}

void resolvePlayerAttack(Entity *player, Entity *monster, bool *combatFinished) {
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

void resolveHide(Entity *player, Entity *monster, bool *combatFinished) {    

    int s = 100 * (player->DEX / monster->SEN);
    // Should the chance be modified depending on if the monster has been attacked?

    // Get the random chance
    srand(time(NULL));
    int r = (rand() % 100) + 1;

    if (r < s) // Player hides successfully
    {
        printf("You successfully hid from the monster!\n");
        *combatFinished = true;
        // Combat should end and the monster should return to normal behaviour and not engage in combat again.
    }
    else // Player fails to hide
    {
        printf("You failed to hide from the monster!\n");
    }
}

void monsterAction(Entity *player, Entity *monster, bool *combatFinished)   {
    // Discussion needed, what actions should the monster take? Always attack, always run away, 
    // weighted chart giving increased probabilities for certain outcomes dependent on monster type?

    // Base 25% chance that the monster flees, otherwise, it attacks
    int f = 25;

    // If the monster is aggresive, reduce the chance that if flees to 10%
    if (monster->behaviour == AGGRESSIVE) 
    {
        f -= 15;
    }
    else if (monster->behaviour == SCARED) // If the monster is scared, increase the chance that it flees to 75%
    {
        f += 50;
    }
    
    // Random variable for it's action
    srand(time(NULL));
    int r = (rand() % 100) + 1;

    // The monster flees if the random variable is lower than its "Flee chance"
    if (r < f) 
    {
        // Moves to room 0
        monster->roomId = 0;
    }
    else // Monster attacks
    {
        resolveMonsterAttack(player, monster, combatFinished);
    }
}

void resolveMonsterAttack(Entity *player, Entity *monster, bool *combatFinished) {
    if(monster->DMG - player->DEF > 0)  // If the attack goes through the player defense...
    {
        player->currentHP -= (monster->DMG - player->DEF);
        printf("You were wounded by the monster!\n");
        printf("Current HP: %d\n", player->currentHP);
        if(player->currentHP <= 0)
        {
            printf("You have perished!\n");
            *combatFinished = true;
        }
    }else   // Attack is too weak...
    {
        printf("The monster's attack had no effect!\n");     // Should an attack always deal some minor damage (1 or more?)?
    }
}

// Function used for unit testing (WIP)
void performTest(Entity *player, Entity *monster, bool *combatFinished, int testFlag) {
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
        default:
            printf("Invalid testFlag was set, please try again!\n");
            break;
    }
}