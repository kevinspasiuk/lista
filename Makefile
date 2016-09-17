# NOMBRE DEL EJECUTABLE DEL TP
EXEC =  main
VALGRIND = valgrind
V_FLAGS = --track-origins=yes --leak-check=full --show-reachable=yes
VALGRIND_V = $(VALGRIND) $(V_FLAGS) -v
VALGRIND_Q = $(VALGRIND) $(V_FLAGS) -q
CC = gcc
CFLAGS = -Wall -Werror -pedantic -std=c99 -g
BIN = $(filter-out $(EXEC).c, $(wildcard *.c))
BINFILES = $(BIN:.c=.o)

all: main

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $<
	
main: $(BINFILES)  $(EXEC).c
	$(CC) $(CFLAGS) $(BINFILES) $(EXEC).c -o $(EXEC)

run: main
	./main

vrun: $(EXEC)
	    $(VALGRIND_V) ./$(EXEC)

clean:
	rm -f $(wildcard *.o) $(EXEC)

.PHONY: clean main


