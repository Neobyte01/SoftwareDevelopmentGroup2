#include <assert.h>
#include "entities/entity.h"

void testEntity()
{
    puts("--Testing general entity functionality--");
    struct Entity *ent1 = createEntity(MONSTER, NONE);
    struct Entity *ent2 = createEntity(MONSTER, NONE);

    puts("<Attach entity to other entity>");
    assert(ent1->noAttached == 0);
    attachEntity(ent1, ent2);
    assert(ent1->noAttached == 1);
    //assert(ent1->attached[0] == ent2);
    puts("Entity could be attached");

    puts("<Remove entity from other entity>");
    assert(ent1->noAttached == 1);
    removeEntity(ent1, ent2);
    assert(ent1->noAttached == 0);
    puts("Entity could be 'removed'");

    destroyEntity(ent1);
    destroyEntity(ent2);
    puts("--General entity tests complete--");
}

#ifdef TEST
int main() {
    puts("Running tests...");
    testEntity();
    puts("Done.");
}
#endif