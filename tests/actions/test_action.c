#include <assert.h>
#include "actions/action.h"


void testCommandCompare() {
    char *commands[] = {"abc", "123", "abc 123"};

    for (int i = 0; i < 3; i++)
        assert(commandCompare(commands[i], commands, 3));

    assert(!commandCompare("test", commands, 3));
}

#ifdef TEST
int main(void) {
    puts("Running tests...");
    testCommandCompare();
    puts("Done.");
}
#endif