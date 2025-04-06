#include "../include/maze.h"
#include <stdio.h>
#include <stdlib.h>

Maze load_maze(const char *filename){
    const unsigned MAX_LENGTH = 256;
    Maze maze = {0};
    FILE *fp = fopen(filename,"r");
    if(fp == NULL){
        perror("File couldn't be loaded");
        exit(EXIT_FAILURE);
    }
    char buffer[MAX_LENGTH];
    while(fgets(buffer,MAX_LENGTH,fp)){
        printf("%s",buffer);
    }
    fclose(fp);
    return maze;
}
