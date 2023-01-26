ifeq ($(OS),Windows_NT)
    CC := gcc

coverage:
	$(CC) --coverage -g -o0 -D TEST -g src/**.c tests/**.c main.c -I include -o main
	./main 
	gcovr

endif

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	CC := clang

coverage:
	$(CC) -fprofile-instr-generate -fcoverage-mapping -D TEST src/**.c tests/**.c main.c -I include -o main
	./main 
	xcrun llvm-profdata merge -sparse main.profraw -o main.profdata
	xcrun llvm-cov report ./main -instr-profile=main.profdata    

endif

run:
	$(CC) -g src/**.c main.c -I include -o main.exe && ./main.exe

test:
	$(CC) -D TEST -g src/**.c tests/**.c main.c -I include -o main.exe && ./main.exe
