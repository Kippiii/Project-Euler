#include <stdio.h>

int main(void) {
    int sum = 0;

    for(int i = 0; i < 1000; i++)
        if(i % 5 == 0 || i % 3 == 0)
            sum += i;

    printf("The sum of all the multiples of 3 or 5 below 1000 are %d.", sum);

    return 0;
}
