#ifdef TEST

#include "tests/test.h"

int 
main(void)
{
	test_program();
}

#else

#include "game.h"

int 
main(void)
{
	mapPrint();
	run_game();
}

#endif