#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

#define GRID_SIZE 3

int is_stable(int grid[GRID_SIZE][GRID_SIZE]);
void topple(int grid[GRID_SIZE][GRID_SIZE], int x, int y);
void stabilize(int grid[GRID_SIZE][GRID_SIZE]);
void sandpiles_sum(int grid1[GRID_SIZE][GRID_SIZE], int grid2[GRID_SIZE][GRID_SIZE]);


#endif