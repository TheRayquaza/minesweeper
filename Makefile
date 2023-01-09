# Makefile
CC := g++
CFLAGS = -Wall -Wextra -std=c99 -O0 -g -fsanitize=address -static-libasan
LDLIBS = -lm -fsanitize=address -static-libasan
LDFLAGS =

# Source files for the neural network
SOURCE := $(shell find . -type f -name "*.cpp")
OBJECTS = $(SOURCE:%.cpp=%.o)

all: minesweeper

minesweeper: $(OBJECTS)
	$(CC) -o build/minesweeper $(OBJECTS) $(LDLIBS)

clean:
	rm -rf $(OBJECTS)
	rm -rf build/*

.PHONY: all minesweeper

# END
