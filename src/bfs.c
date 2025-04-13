#include "../include/bfs.h"
#include "../include/maze.h"
#include "../include/queue.h"
#include <stdlib.h>
#include <stdio.h>
Point directions[4]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int **create_2d_int_array(int height, int width , int initial_value){
    int **array = malloc(height * sizeof(int *));
    for(int i = 0 ; i < height ; i++){
        array[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width;j++) {
            array[i][j] = 0;
        }
    }
    return array;
}

Point **create_2d_point_array(int height , int width){
    Point **array = malloc(height * sizeof(Point*));
    for(int i = 0 ; i < height ; i++){
        array[i] = malloc(width * sizeof(Point));
        for (int j = 0; j < width;j++) {
            array[i][j].col = -1;
            array[i][j].row = -1;
        }
    }
    return array;
}

int is_valid(Maze *maze , Point p){
    return p.row >= 0 && p.row < maze->rows &&
        p.col >= 0 && p.col < maze->cols &&
        (maze->grid[p.row][p.col]) != '#';
}

void reconstructPath(Maze *maze ,Point **parent, Point start , Point end){
    Point current = end;
    while(!(current.row == start.row && current.col == start.col)){
        if(maze->grid[current.row][current.col] != 'E'&&
            maze->grid[current.row][current.col] != 'S'){
            maze->grid[current.row][current.col] = '*';
        }
        current = parent[current.row][current.col];
    }
    
}
void bfs(Maze *maze, Point *start, Point *end){
    int height = maze->rows;
    int width = maze->cols;

    int **visited = create_2d_int_array(height, width, 0);
    Point **parent = create_2d_point_array(height, width);

    Queue* q = create_queue();
    enqueue(q , *start);
    visited[start->row][start->col] = 1;

    while(!is_empty(q)){
        Point current = dequeue(q);
        if(current.col == end->col && current.row == end->row){
            reconstructPath(maze,parent, *start, *end);
            print_maze(maze);
            printf("Path Found ! \n");
            goto cleanup;
        }
        for (int i = 0; i < 4; i++) {
            Point next = {
                .row = current.row + directions[i].row,
                .col = current.col + directions[i].col
            };

            if (is_valid(maze, next) && !visited[next.row][next.col]) {
                visited[next.row][next.col] = 1;
                parent[next.row][next.col] = current;
                enqueue(q, next);
            }
        }
    }
    printf("No Path found! \n");
cleanup:
    for (int i = 0; i < height; i++) {
        free(visited[i]);
        free(parent[i]);
    }
    free(visited);
    free(parent);
    free_queue(q);
}
