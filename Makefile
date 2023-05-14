CC=gcc
CFLAGS=-Wall -Wextra -g
CLIBS=
CODE=src/

all: $(CODE)*.c
	$(CC) $(CFLAGS) $(CLIBS) $? -o rv64-emu

run:
	./rv64-emu
