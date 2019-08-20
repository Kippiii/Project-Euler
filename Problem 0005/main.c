#include <stdio.h>

int main(void) {
	int n = 1;
	for(int i = 2; i <= 20; i++) {
		if(n % i != 0) {
			int s = n % i;
			if(s != 1 && i % s == 0)
				n *= i / s;
			else
				n *= i;
		}
	}
	
	printf("The smallest number that is evenly divisible by the numbers from 1 to 20 is %d.", n);
	
	return 0;
}