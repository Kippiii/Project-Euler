#include <stdio.h>

#define GRID_SIZE 20

long long path_count(int, int, long long[][GRID_SIZE + 1]);

int main(void) {
	long long memo[GRID_SIZE + 1][GRID_SIZE + 1];
	for(int i = 0; i < GRID_SIZE + 1; i++)
		for(int j = 0; j < GRID_SIZE + 1; j++)
			memo[i][j] = -1;
	
	printf("The number of available paths is %f.", (double) path_count(0, 0, memo));
	
	return 0;
}

long long path_count(int x, int y, long long memo[][GRID_SIZE + 1]) {
	long long count = -1;
	if(memo[y][x] != -1)
		return memo[y][x];
	
	if(x == GRID_SIZE && y == GRID_SIZE)
		count = 1;
	else if(x == GRID_SIZE)
		count = path_count(x, y + 1, memo);
	else if(y == GRID_SIZE)
		count = path_count(x + 1, y, memo);
	else 
		count = path_count(x + 1, y, memo) + path_count(x, y + 1, memo);
	
	memo[y][x] = count;
	return count;
}