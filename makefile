# Generic commands
CC := gcc
CFLAGS := -I include -fcommon src/actions/*.c src/map/*.c src/entities/*.c src/*.c
TESTFLAGS := -D TEST $(CFLAGS)

ifeq ($(shell uname -s),Darwin)
	CC := clang
endif

# Standard make target (i.e gets run when running just "make")
all: 
	$(CC) $(CFLAGS) main.c -o bin/game

# -- Setup coverage make target for windows and macos --

ifeq ($(OS),Windows_NT)

coverage:
	$(CC) --coverage -g -o0 -g $(CFLAGS) tests/test_all.c -o bin/coverage
	./bin/coverage
	gcovr

else ifeq ($(shell uname -s),Darwin)

coverage:
	$(CC) -fprofile-instr-generate -fcoverage-mapping $(CFLAGS) tests/test_all.c -o bin/coverage
	./bin/coverage 
	xcrun llvm-profdata merge -sparse default.profraw -o default.profdata
	xcrun llvm-cov report bin/coverage -instr-profile=default.profdata    

endif


# Lint the whole project
lint:
	indent -kr -ut -ts4 src/**.c tests/**.c include/**.h include/tests/**.h main.c 


# Run the game
run: all
	./bin/game

# Run test suite
test: 
	$(CC) $(CFLAGS) tests/test_all.c -o bin/test_all
	./bin/test_all

# -- Custom test targets --

test-combat:
	$(CC) $(TESTFLAGS) tests/test_combat.c -o bin/test_combat
	./bin/test_combat

test-actions-action: 
	$(CC) $(TESTFLAGS) tests/actions/test_action.c -o bin/test_actions_action
	./bin/test_actions_action

test-actions-interaction: 
	$(CC) $(TESTFLAGS) tests/actions/test_interaction.c -o bin/test_actions_interaction
	./bin/test_actions_interaction

test-entities-player:
	$(CC) $(TESTFLAGS) tests/entities/test_player.c -o bin/test_entities_player
	./bin/test_entities_player

test-entities-monsters:
	$(CC) $(TESTFLAGS) tests/entities/test_monsters.c -o bin/test_entities_monsters
	./bin/test_entities_monsters

test-entities-entity:
	$(CC) $(TESTFLAGS) tests/entities/test_entity.c -o bin/test_entities_entity
	./bin/test_entities_entity

test-map-map:
	$(CC) $(TESTFLAGS) tests/map/test_map.c -o bin/test_map_map
	./bin/test_map_map

test-map-movement:
	$(CC) $(TESTFLAGS) tests/map/test_movement.c -o bin/test_map_movement
	./bin/test_map_movement

test-map-generation:
	$(CC) $(TESTFLAGS) tests/map/test_generation.c -o bin/test_map_generation
	./bin/test_map_generation