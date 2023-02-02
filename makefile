# Generic commands
CC := gcc
CFLAGS := -I include -fcommon src/actions/*c src/map/*c src/entities/*c src/*c


# Standard make target (i.e gets run when running just "make")
all: run


# -- Setup coverage make target for windows and macos --

ifeq ($(OS),Windows_NT)

coverage:
	$(CC) --coverage -g -o0 -D TEST -g $(CFLAGS) tests/**.c main.c -o game
	./game
	gcovr

else ifeq ($(shell uname -s),Darwin)
	CC := clang

coverage:
	$(CC) -fprofile-instr-generate -fcoverage-mapping -D TEST $(CFLAGS) tests/**.c main.c -o game
	./game 
	xcrun llvm-profdata merge -sparse bin/main.profraw -o bin/main.profdata
	xcrun llvm-cov report .bin//main -instr-profile=bin/main.profdata    

endif


# Lint the whole project
lint:
	indent -kr -ut -ts4 src/**.c tests/**.c include/**.h include/tests/**.h main.c 


# Run the game
run:
	$(CC) $(CFLAGS) main.c -o game
	./game


# Run test suite
test: test-entities

# -- Custom test targets --

test-entities: test-entities-player test-entities-monsters

test-entities-player:
	$(CC) $(CFLAGS) tests/entities/test_player.c -o test_entities_player
	./test_entities_player

test-entities-monsters:
	$(CC) $(CFLAGS) tests/entities/test_monsters.c -o test_entities_monsters
	./test_entities_monsters
