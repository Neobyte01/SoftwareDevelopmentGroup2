#include <assert.h>
#include "entities/entity.h"
#include "combat.h"

// Check monster health after applying attacks from the player (Not yet implemented)
Entity p = {.type = PLAYER, .currentHP = 3, .maxHP = 3, .SEN = 1, .DEX = 3, .DMG = 4, .DEF = 3, .attached = NULL, .noAttached = 0};
Entity m = {.type = MONSTER, .currentHP = 10, .maxHP = 10, .SEN = 2, .DEX = 2, .DMG = 2, .DEF = 2, .attached = NULL, .noAttached = 0};

void testCombat(void)
{
    printf("<<Player kills Monster using Attack (1)>>\n");
    bool playerSurvived = combat(&p, &m, 1);
    assert(playerSurvived == true);
    assert(m.currentHP <= 0);

    printf("<<Player hides from Monster (2)>>\n");
    playerSurvived = combat(&p, &m, 2);
    assert(playerSurvived == true);

    printf("<Ensuring that 1 is still equal to 1>");
    assert(1 == 1);
}

int main() {
    puts("Running tests...");
    testCombat();
    puts("Done.");
}