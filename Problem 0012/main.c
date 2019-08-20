#include <stdio.h>
#include <math.h>

int get_factor_count(int);

int main(void) {
	int triangle_number = 1;
	for(int i = 2; get_factor_count(triangle_number) <= 500; i++)
		triangle_number += i;
	
	printf("The triangle number is %d.", triangle_number);
	
	return 0;
}

int get_factor_count(int n) {
	int count = 2;
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			count+=2;
	int square_root = sqrt(n);
	if(square_root*square_root == n)
		count--;
	return count;
}