#include "sandpiles.h"

/**
 * is_stable - returns true  if the version of the sandbox is stable
 * 
 * 
*/
int is_stable(int grid[GRID_SIZE][GRID_SIZE])
{
	int i;
	int j;

	for (i = 0; i < GRID_SIZE; i++)
	{
		for (j = 0; j < GRID_SIZE; j++)
		{
			if (grid[i][j] > 3)
			{
				return 0;
			}
		}
	}
	return 1;
}

/**
 * topple - returns true if the version of the sandbox
 * 
 * 
*/
void topple(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
	if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
		grid[x][y] -= 4;

		if (x - 1 >= 0) grid[x - 1][y]++;
		if (x + 1 < GRID_SIZE) grid[x + 1][y]++;
		if (y - 1 >= 0) grid[x][y - 1]++;
		if (y + 1 < GRID_SIZE) grid[x][y + 1]++;
	}
}

/**
 * stabilize -  
 * 
 * 
*/
void stabilize(int grid[GRID_SIZE][GRID_SIZE])
{
	int temp[GRID_SIZE][GRID_SIZE];
	int i;
	int j;

	while (!is_stable(grid)) {

		for (i = 0; i < GRID_SIZE; i++) {
			for (j = 0; j < GRID_SIZE; j++) {
				temp[i][j] = grid[i][j];
			}
		}

		for (i = 0; i < GRID_SIZE; i++) {
			for (j = 0; j < GRID_SIZE; j++) {
				if (temp[i][j] > 3) {
					topple(grid, i, j);
				}
			}
		}
	}
}

/**
 * sandpiles_sum - calculate sum of sand in the given grid
 * 
 * 
*/
void sandpiles_sum(int grid1[GRID_SIZE][GRID_SIZE], int grid2[GRID_SIZE][GRID_SIZE]) {
	int i, j;
	for (i = 0; i < GRID_SIZE; i++) {
		for (j = 0; j < GRID_SIZE; j++) {
			grid1[i][j] += grid2[i][j];
		}
	}

	stabilize(grid1);
}
