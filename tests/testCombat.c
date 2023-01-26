#include <assert.h>
#include "combat.h"

// Check monster health after applying attacks from the player (Not yet implemented)
entity p = {.name = "player", .type = 'P', .currentHP = 3, .maxHP = 3, .DEX = 3, .DMG = 4, .DEF = 3, .attached = NULL, .num = 0};
entity m = {.name = "monster", .type = 'M', .currentHP = 10, .maxHP = 10, .DEX = 2, .DMG = 2, .DEF = 2, .attached = NULL, .num = 0};

void testCombatPlayerKillsMonster(void)
{
    printf("--- Testing combat ---\n");
    printf("<<Player kills Monster using Attack>>\n");
    bool playerSurvived = combat(&p, &m, 1);
    assert(playerSurvived == true);
    assert(m.currentHP <= 0);
    printf("--- Completed Combat Tests ---\n");
}