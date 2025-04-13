#ifndef MAZE_H
#define MAZE_H

#include <stdbool.h>

typedef struct {
  char **grid;
  int rows;
  int cols;
} Maze;

typedef struct {
  int row;
  int col;
} Point;

Maze load_maze(const char *filename);
void print_maze(const Maze *maze);
bool find_point(const Maze *maze, char target, Point *point);
void free_maze(Maze *maze);
#endif // !MAZE_H
