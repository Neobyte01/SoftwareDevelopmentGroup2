ifeq ($(OS),Windows_NT)
    CC := gcc
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Darwin)
        CC := clang
    endif
endif

run:
	$(CC) -g src/**.c main.c -I include -o main.exe && ./main.exe

test:
	$(CC) -D TEST -g src/**.c tests/**.c main.c -I include -o main.exe && ./main.exe
