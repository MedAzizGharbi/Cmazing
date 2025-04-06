#ifndef MAZE_H
#define MAZE_H

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
#endif // !MAZE_H
