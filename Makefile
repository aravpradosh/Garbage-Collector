CC = gcc
CFLAGS = -Wall -Wextra -g
INCLUDES = -Iinclude -Iexternal/munit

SRC = src/*.c
TEST = tests/main.c
MUNIT = external/munit/munit.c

TARGET = gc_tests

all:
	$(CC) $(CFLAGS) $(SRC) $(TEST) $(MUNIT) $(INCLUDES) -o $(TARGET)

run: all
	./$(TARGET)

valgrind: all
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm -f $(TARGET)