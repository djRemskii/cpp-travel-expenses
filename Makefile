CC = gcc
MAIN = src/main.c
INPUT = src/input.c
METHODS = src/expensesMethods.c

all: program

program: src

	$(CC) -o bin/program $(MAIN) $(INPUT) $(METHODS)

run: bin
	bin/program.exe
