#include "../include/maze.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Maze load_maze(const char *filename){
    FILE *fp = fopen(filename,"r");
    if(fp == NULL){
        perror("File couldn't be loaded");
        exit(EXIT_FAILURE);
    }
    char ch;
    int cols = 0  , rows = 0;
    while((ch = fgetc(fp)) != EOF){
        if(ch == '\n'){
            rows++;
        }
        if(rows == 1 && ch != '\n'){
            cols++;
        }
    }
    rewind(fp);
    Maze maze;
    maze.rows = rows;
    maze.cols = cols;
    maze.grid = malloc(rows * sizeof(char*));
    for(int i = 0 ; i < rows ; i++){
        maze.grid[i] = malloc(cols * sizeof(char));
    }
    int row = 0 , col = 0;
    while((ch = fgetc(fp)) != EOF){
        if(ch == '\n'){
            row++;
            col = 0;
        }else{
            maze.grid[row][col] = ch;
            col++;
        }
    }
    fclose(fp);
    return maze;
}

void print_maze(const Maze *maze){
    printf("Loading the maze : \n");
    for(int i = 0 ; i < maze->rows ; i++){
        for(int j = 0 ; j < maze->cols ; j++){
            printf("%c" , maze->grid[i][j]);
        }
        printf("\n");
    }
}

bool find_point(const Maze *maze, char target,Point *point){
    for(int i = 0 ; i < maze->rows ; i++){
        for(int j = 0 ; j < maze->cols ; j++){
            if(maze->grid[i][j] == target){
                point->row = i;
                point->col = j;
                return true;
            }
        }
    }
    return false;
}

void free_maze(Maze *maze){
    for(int i = 0 ; i < maze->rows ; i++){
        free(maze->grid[i]);
        }
    free(maze->grid);
}












