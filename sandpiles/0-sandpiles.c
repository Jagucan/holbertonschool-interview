#include <stdio.h>


#define GRID_SIZE 3


void print_grid(int grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			printf("%d", grid[i][j]);
			if (j < GRID_SIZE - 1) {
				printf(" ");
			}
		}
		printf("\n");
	}
}


int is_stable(int grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			if (grid[i][j] > 3) {
				return 0;
			}
		}
	}
	return 1;
}


void topple(int grid[GRID_SIZE][GRID_SIZE], int x, int y) {
	if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE) {
		grid[x][y] -= 4;

		if (x - 1 >= 0) grid[x - 1][y]++;
		if (x + 1 < GRID_SIZE) grid[x + 1][y]++;
		if (y - 1 >= 0) grid[x][y - 1]++;
		if (y + 1 < GRID_SIZE) grid[x][y + 1]++;
	}
}


void stabilize(int grid[GRID_SIZE][GRID_SIZE]) {
	int temp[GRID_SIZE][GRID_SIZE];

	while (!is_stable(grid)) {
		printf("=\n");
		print_grid(grid);
		printf("\n");

		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				temp[i][j] = grid[i][j];
			}
		}

		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				if (temp[i][j] > 3) {
					topple(grid, i, j);
				}
			}
		}
	}
}


void sandpiles_sum(int grid1[GRID_SIZE][GRID_SIZE], int grid2[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			grid1[i][j] += grid2[i][j];
		}
	}

	stabilize(grid1);
}
