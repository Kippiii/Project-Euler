#include <stdio.h>

long long sum_squared(int);
long long sum_of_squares(int);

int main(void) {
	printf("The difference is %d.", sum_squared(100) - sum_of_squares(100));
	
	return 0;
}

long long sum_squared(int n) {
	long sum = 0;
	for(int i = 1; i <= n; i++)
		sum += i;
	return sum * sum;
}

long long sum_of_squares(int n) {
	long long sum = 0;
	for(int i = 1; i <= n; i++)
		sum += i * i;
	return sum;
}