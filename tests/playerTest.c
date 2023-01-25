#include <assert.h>
#include "player.h"

void damageTest()
{
    player* pPtr = createPlayer(NULL);

    assert(damagePlayer(pPtr, 5) == 20);
    freePlayer(pPtr);
};