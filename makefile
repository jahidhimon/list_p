CC := gcc
CFLAGS := -Wall -ggdb -std=c11 -pedantic
TARGET := list_p

all: $(TARGET)

$(TARGET): main.c
	$(CC) $(CFLAGS) -o $(TARGET) main.c

.PHONY: clean
clean:
	rm *.o *.gch

