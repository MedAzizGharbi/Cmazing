#include "../include/maze.h"
#include "../include/bfs.h"
#include <stdio.h>
int main()
{
    char *filename = "mazes/level1.txt";
    Maze maze = load_maze(filename);
    printf("Original maze: \n");
    print_maze(&maze);

    Point start , end;
    find_point(&maze, 'S', &start);
    find_point(&maze, 'E', &end);
    
    bfs(&maze, &start, &end);

    return 0;
}
