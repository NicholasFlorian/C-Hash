 CC=gcc
CFLAGS=-Wall -g -std=c99

SRC=./src/
BIN=./bin/
OBJ=./obj/

INC=./include/

all: main

main: 
	$(CC) $(CFLAGS) $(SRC)stringArray.c $(SRC)hashTable.c $(SRC)ioHandler.c $(SRC)spellCheck.c -Iinclude -o main

test: 
	$(CC) $(CFLAGS) $(SRC)hashTable.c $(SRC)ioHandler.c $(SRC)stringArray.c $(SRC)test.c -Iinclude -o test
 
clean:
	rm test main