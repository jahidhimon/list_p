CC := gcc
CFLAGS := -Wall -ggdb -std=c11 -pedantic
TARGET := list_p
CLIBS := -ledit
OBJECTS = main.o mpc.o

GREEN='\033[0;32m'
RESET='\033[0m'
DONE=$(GREEN) DONE $(RESET)

$(TARGET): makefile $(OBJECTS)
	@echo -n Building $(TARGET) ...
	@$(CC) $(CFLAGS) $(CLIBS) -o $(TARGET) $(OBJECTS)
	@echo -e $(DONE)

mpc.o : mpc.c mpc.h
	@echo -n Building mpc.o...
	@$(CC) $(CFLAGS) $(CLIBS) mpc.c -c -o  mpc.o
	@echo -e $(DONE)

main.o : main.c mpc.h
	@echo -n Building main.o...
	@$(CC) $(CFLAGS) $(CLIBS) main.c -c -o main.o
	@echo -e $(DONE)

.PHONY: clean
clean:
	-rm list_p *.o

