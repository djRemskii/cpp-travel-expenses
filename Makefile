CC = gcc
MAIN = src/main.c
INPUT = src/input.c
OUTPUT = src/output.c
METHODS = src/expensesMethods.c

all: program

program: src

	$(CC) -o bin/program $(MAIN) $(INPUT) $(OUTPUT) $(METHODS)

run: bin
	bin/program.exe
