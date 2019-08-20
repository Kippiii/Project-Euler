#include <stdio.h>

int main(void) {
	int a, b, c;
	for(a = 999; a >= 1; a--) {
		for(b = a + 1; b <= 999; b++) {
			if(a*a + b*b == (1000 - a - b)*(1000 - a - b)) {
				c = 1000 - a - b;
				printf("The product is %d.", a * b * c);
				return 0;
			}
		}
	}
	
	return 0;
}