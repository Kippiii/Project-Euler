#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(long);

int main(void) {
	int count = 1;
	long prime = 2;
	for(long i = 3; count < 10001; i++) {
		if(is_prime(i)) {
			count++;
			prime = i;
		}
	}
	
	printf("The 10001st prime number is %d.", prime);
	
	return 0;
}

bool is_prime(long n) {
	for(int i = 2; i <= sqrt(n); i++)
		if(n % i == 0)
			return false;
	return true;
}