#include "sandpiles.h"

/**
 * is_stable - returns true  if the version of the sandbox is stable.
 * @grid: the sandbox.
 * Return: Return true if the version of the sandbox is stable
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
				return (0);
			}
		}
	}
	return (1);
}

/**
 * topple - returns true if the version of the sandbox
 * @grid: the sandbox
 * @x: the x coordinate of the sandbox
 * @y: the y coordinate of the sandbox
*/
void topple(int grid[GRID_SIZE][GRID_SIZE], int x, int y)
{
	if (x >= 0 && x < GRID_SIZE && y >= 0 && y < GRID_SIZE)
	{
		grid[x][y] -= 4;

		if (x - 1 >= 0)
		{
			grid[x - 1][y]++;
		}
		if (x + 1 < GRID_SIZE)
		{
			grid[x + 1][y]++;
		}
		if (y - 1 >= 0)
		{
			grid[x][y - 1]++;
		}
		if (y + 1 < GRID_SIZE)
		{
			grid[x][y + 1]++;
		}
	}
}

/**
 * print_grid - Print a 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j != 0)
			{
				printf(" ");
			}
			printf("%d", grid[i][j]);
			printf("\n");
		}
		if (i != 1)
		{
			printf("\n");
		}
	}
	printf("\n");
}

/**
 * stabilize -  verifies that the version of the sandbox
 * @grid: the sandbox
*/
void stabilize(int grid[GRID_SIZE][GRID_SIZE])
{
	int temp[GRID_SIZE][GRID_SIZE];
	int i;
	int j;

	while (!is_stable(grid))
	{

		printf("=\n");
		print_grid(grid);
		printf("\n");

		for (i = 0; i < GRID_SIZE; i++)
		{
			for (j = 0; j < GRID_SIZE; j++)
			{
				temp[i][j] = grid[i][j];
			}
		}

		for (i = 0; i < GRID_SIZE; i++)
		{
			for (j = 0; j < GRID_SIZE; j++)
			{
				if (temp[i][j] > 3)
				{
					topple(grid, i, j);
				}
			}
		}
	}
}

/**
 * sandpiles_sum - calculate sum of sand in the given grid
 * @grid1: the grid
 * @grid2: the grid
*/
void sandpiles_sum(int grid1[GRID_SIZE][GRID_SIZE],
					int grid2[GRID_SIZE][GRID_SIZE])
{
	int i, j;

	for (i = 0; i < GRID_SIZE; i++)
	{
		for (j = 0; j < GRID_SIZE; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	stabilize(grid1);
}
