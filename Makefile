CC = gcc
MAIN = src/main.c
INPUT = src/input.c
OUTPUT = src/output.c
METHODS = src/expensesMethods.c
TEST = src/testCases.c

# WINDOWS: use ~ mingw32-make [ command ]
# MAC/LINUS: use ~ make [command]

#OBJECTS 

# mathMain.o: mathMain.c 

#     $(CC) -c mathMain.c -o mathMain.o 

# mathFunc.o: mathFunc.c 

#     $(CC) -c mathFunc.c -o mathFunc.o 

ifeq ($(OS), Windows_NT)
	DELETE = del
	EXT=.exe
else 
	UNAME_S:=$(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		DELETE = rm -f
		EXT=.out
	endif
endif

all: program

program:

	$(CC) -o bin/program$(EXT) $(MAIN) $(INPUT) $(OUTPUT) $(METHODS) $(TEST)

noTest:

	$(CC) -o bin/program$(EXT) $(MAIN) $(INPUT) $(OUTPUT) $(METHODS)

objects: main.o input.o output.o expensesMethods.o testCases.o

main.o: $(MAIN)
	$(CC) -c $(MAIN) -o obj/main.o
input.o: $(INPUT)
	$(CC) -c $(INPUT) -o obj/input.o
output.o: $(OUTPUT)
	$(CC) -c $(OUTPUT) -o obj/output.o
expensesMethods.o: $(METHODS)
	$(CC) -c $(METHODS) -o obj/expensesMethods.o
testCases.o: $(TEST)
	$(CC) -c $(TEST) -o obj/testCases.o

run: bin/program$(EXT)
	bin/program$(EXT)

objects: obj/

clean: 

	$(DELETE) bin\*$(EXT) obj\*o
