ifeq ($(OS),Windows_NT)
    CC := gcc

coverage:
	$(CC) --coverage -g -o0 -D TEST -g src/**.c tests/**.c main.c -I include -o bin/main
	./bin/main
	gcovr

else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		CC := clang

coverage:
	$(CC) -fprofile-instr-generate -fcoverage-mapping -D TEST src/**.c tests/**.c main.c -I include -o bin/main
	./bin/main 
	xcrun llvm-profdata merge -sparse bin/main.profraw -o bin/main.profdata
	xcrun llvm-cov report .bin//main -instr-profile=bin/main.profdata    

	endif

endif

run:
	$(CC) -g src/**.c main.c -I include -o bin/main.exe
	./bin/main.exe

test:
	$(CC) -D TEST -g src/**.c tests/**.c main.c -I include -o bin/main.exe 
	./bin/main.exe

lint:
	indent -kr -ut -ts4 src/**.c tests/**.c include/**.h include/tests/**.h main.c 
