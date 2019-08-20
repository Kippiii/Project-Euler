#include <stdio.h>
#include <stdbool.h>

bool is_palindrome(int);

int main(void) {
	for(int i = 0; i < 999; i++) {
		for(int j = i / 2; j >= 0; j--) {
			int n = (999 - j) * (999 - (i - j));
			if(is_palindrome(n)) {
				printf("The largest palindrome is %d, which is a result of multiplying %d and %d.", n, i, j);
				return 0;
			}
		}
	}
	
	return 0;
}

bool is_palindrome(int n) {
	return (n % 1000) == ((n % 10000) / 1000 * 100 + (n % 100000) / 10000 * 10 + (n % 1000000) / 100000);
}