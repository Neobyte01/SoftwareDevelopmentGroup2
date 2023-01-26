#include <assert.h>
#include "combat.h"

// Check monster health after applying attacks from the player (Not yet implemented)
player p = {.ID = 3,.currentHP = 3,.maxHP = 3,.DEX = 3,.DMG = 4,.DEF = 3,.posX = 3,.posY = 3,.items = NULL,.noItems = 0};
monster m = {.ID = 2,.currentHP = 10,.maxHP = 10,.DEX = 2,.DMG = 2,.DEF = 2,.posX = 3,.posY = 3};

void main(void)
{
    bool playerSurvived = combat(&p, &m);

    assert(m.currentHP == 0);
}

 