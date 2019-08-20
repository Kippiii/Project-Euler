#include <stdio.h>

int main(void) {
	unsigned int sum = 0;
	int num1 = 1;
	int num2 = 1;
	
	while(num2 <= 4000000) {
		if(num2 % 2 == 0)
			sum += num2;
		int fib = num1 + num2;
		num1 = num2;
		num2 = fib;
	}
	
	printf("The sum of the even fibonacci numbers is %d.", sum);
	
	return 0;
}