#include <stdio.h>

#define NUMBER_COUNT 100
#define DIGITS 50

void digit_addition(int[], int*, int*);

int main(void) {
	int nums[NUMBER_COUNT][DIGITS];
	FILE *num_file;
	num_file = fopen("numbers.txt", "r");
	
	for(int i = 0; i < NUMBER_COUNT; i++) {
		for(int j = DIGITS - 1; j >= 0; j--)
			fscanf(num_file, "%1d", &nums[i][j]);
	}
	
	fclose(num_file);
	
	int solution[DIGITS];
	for(int i = 0; i < DIGITS; i++)
		solution[i] = 0;
	int overlap = 0;
	for(int i = 0; i < DIGITS; i++) {
		int digit_array[NUMBER_COUNT];
		for(int j = 0; j < NUMBER_COUNT; j++)
			digit_array[j] = nums[j][i];
		digit_addition(digit_array, &solution[i], &overlap);
	}
	
	printf("%d", overlap);
	for(int i = DIGITS - 1; i >= 0; i--)
		printf("%d", solution[i]);
	
	return 0;
}

void digit_addition(int digit_array[], int *solution, int *overlap) {
	int n = *overlap;
	for(int i = 0; i < NUMBER_COUNT; i++)
		n += digit_array[i];
	*solution = n % 10;
	*overlap = n / 10;
}