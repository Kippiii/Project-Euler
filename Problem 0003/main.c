#include <stdio.h>
#include <math.h>
#define NUMBER 600851475143

int main(void) {
	long long num = NUMBER;
	
	for(long long i = 2; i < sqrt(num); i++) {
		if(num % i == 0) {
			num /= i;
			i = 2;
		}
	}
	
	printf("The largest factor of %.0f is %d.", (double) NUMBER, num);
	
	return 0;
}