#include <assert.h>
#include "entities/entity.h"
#include "combat.h"

// Check monster health after applying attacks from the player (Not yet implemented)
Entity p = {.type = PLAYER, .currentHP = 10, .maxHP = 10, .SEN = 1, .DEX = 3, .DMG = 4, .DEF = 3, .attached = NULL, .noAttached = 0};
Entity m = {.type = MONSTER, .currentHP = 10, .maxHP = 10, .SEN = 2, .DEX = 2, .DMG = 4, .DEF = 2, .attached = NULL, .noAttached = 0};

void testCombat(void)
{
    printf("<<Player kills Monster using Attack (1)>>\n");
    bool playerSurvived = combat(&p, &m, 1);
    assert(playerSurvived == true);
    assert(m.currentHP <= 0);

    printf("<<Player hides from Monster (2)>>\n");
    playerSurvived = combat(&p, &m, 2);
    assert(playerSurvived == true);

    printf("<<Monster attacks and kills Player (3)>>\n");
    playerSurvived = combat(&p, &m, 3);
    assert(playerSurvived == false);
    assert(p.currentHP <= 0);

    printf("<<Player fights against Monster and wins, but takes some damage>>\n");
    p.currentHP = p.maxHP;
    m.currentHP = m.maxHP;
    playerSurvived = combat(&p, &m, 4);
    assert(playerSurvived == true);
    assert(m.currentHP <= 0);
    assert(p.currentHP < p.maxHP);

    printf("<Ensuring that 1 is still equal to 1>\n");
    assert(1 == 1);
}

int main() {
    puts("Running tests...");
    testCombat();
    puts("Done.");
}