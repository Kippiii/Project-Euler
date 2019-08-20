#include <stdio.h>

int right_product(int, int, int[][20]);
int down_product(int, int, int[][20]);
int down_right_product(int, int, int[][20]);
int up_right_product(int, int, int[][20]);
void compare_products(int[], int, int*);

int main(void) {
	FILE *num_file;
	num_file = fopen("numbers.txt", "r");
	
	int nums[20][20];
	
	for(int i = 0; i < 20; i++)
		for(int j = 0; j < 20; j++)
			fscanf(num_file, "%d", &nums[i][j]);
	
	fclose(num_file);
	
	int max_product = 0;
	
	for(int y = 0; y < 3; y++) {
		for(int x = 0; x < 17; x++) {
			int products[] = {right_product(x, y, nums), down_product(x, y, nums), down_right_product(x, y, nums)};
			compare_products(products, 3, &max_product);
		}
	}
	
	for(int y = 3; y < 17; y++) {
		for(int x = 0; x < 17; x++) {
			int products[] = {right_product(x, y, nums), down_product(x, y, nums), down_right_product(x, y, nums), up_right_product(x, y, nums)};
			compare_products(products, 4, &max_product);
		}
	}
	
	for(int y = 17; y < 20; y++) {
		for(int x = 0; x < 17; x++) {
			int products[] = {right_product(x, y, nums), up_right_product(x, y, nums)};
			compare_products(products, 2, &max_product);
		}
	}
	
	for(int y = 0; y < 17; y++) {
		for(int x = 17; x < 20; x++) {
			int products[] = {down_product(x, y, nums)};
			compare_products(products, 1, &max_product);
		}
	}
	
	printf("The maximum product is %d.", max_product);
	
	return 0;
}

int right_product(int x, int y, int nums[][20]) {
	int product = 1;
	for(int i = 0; i < 4; i++)
		product *= nums[y][x + i];
	return product;
}

int down_product(int x, int y, int nums[][20]) {
	int product = 1;
	for(int i = 0; i < 4; i++)
		product *= nums[y + i][x];
	return product;
}

int down_right_product(int x, int y, int nums[][20]) {
	int product = 1;
	for(int i = 0; i < 4; i++)
		product *= nums[y + i][x + i];
	return product;
}

int up_right_product(int x, int y, int nums[][20]) {
	int product = 1;
	for(int i = 0; i < 4; i++)
		product *= nums[y - i][x + i];
	return product;
}

void compare_products(int products[], int length, int *max_product) {
	for(int i = 0; i < length; i++)
				if(products[i] > *max_product)
					*max_product = products[i];
}