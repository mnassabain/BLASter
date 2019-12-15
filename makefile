# ne pas oublier de mkdir bin/ pcq git le regarde pas

TARGET = main
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

.PHONY: default all clean

default: $(TARGET)
all: default

OBJECTS = $(patsubst src/%.c, bin/%.o, $(wildcard src/*.c))
HEADERS = $(wildcard include/*.h)

bin/%.o: src/%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@

clean:
	-rm -f bin/*.o
	-rm -f $(TARGET)

exec:
	./bin/main