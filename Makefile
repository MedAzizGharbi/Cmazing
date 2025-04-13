#Compiler and Flags
cc = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

#Source files
SRC = src/main.c src/maze.c src/bfs.c src/queue.c
OBJ = $(SRC:.c=.o)

#Output binary
BIN = build/maze_solver

#Default Target
all: $(BIN)

# Linking
$(BIN): $(OBJ)
	@mkdir -p build
	$(CC) $(FLAGS) -o $@ $^

#Clean object files and binary
clean:
	rm -rf src/*.o build

#Run with Sample maze
run: all
	./$(BIN) mazes/level1.txt

.PHONY: all clean run
