#include <stdio.h>

#define MAX_LENGTH 400

int main(void) {
	int digits[MAX_LENGTH];
	for(int i = 0; i < MAX_LENGTH; i++)
		digits[i] = 0;
	
	digits[0] = 2;
	int length = 1;
	
	for(int i = 1; i < 1000; i++) {
		int remainder = 0;
		for(int j = 0; j < length; j++) {
			int n = digits[j] * 2 + remainder;
			digits[j] = n % 10;
			remainder = n / 10;
		}
		if(remainder != 0) {
			digits[length] = remainder;
			length++;
		}
	}
	
	int sum = 0;
	for(int i = 0; i < length; i++)
		sum += digits[i];
	
	printf("The sum of the digits is %d.", sum);
	
	return 0;
}