#include <assert.h>
#include "combat.h"

// Check monster health after applying attacks from the player (Not yet implemented)
entity p = {.name = "player", .type = 'P', .currentHP = 3, .maxHP = 3, .DEX = 3, .DMG = 4, .DEF = 3, .attached = NULL, .num = 0};
entity m = {.name = "monster", .type = 'M', .currentHP = 10, .maxHP = 10, .DEX = 2, .DMG = 2, .DEF = 2, .attached = NULL, .num = 0};

void testCombat(void)
{
    printf("--- Testing combat ---\n");
    printf("<<Player kills Monster using Attack (1)>>\n");
    bool playerSurvived = combat(&p, &m, 1);
    assert(playerSurvived == true);
    assert(m.currentHP <= 0);

    printf("<<Player hides from Monster (2)>>\n");
    playerSurvived = combat(&p, &m, 2);
    assert(playerSurvived == true);

    printf("<<Player flees from Monster (3)>>\n");
    playerSurvived = combat(&p, &m, 3);
    assert(playerSurvived == true);

    printf("<<Player uses items (4)>>\n");
    playerSurvived = combat(&p, &m, 4);
    assert(playerSurvived == true);

    printf("--- Completed Combat Tests ---\n");
}