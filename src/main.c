#include "../include/maze.h"
int main(int argc, char *argv[])
{
    char *filename = "mazes/level1.txt";
    Maze maze = load_maze(filename);
    print_maze(&maze);
    return 0;
}
