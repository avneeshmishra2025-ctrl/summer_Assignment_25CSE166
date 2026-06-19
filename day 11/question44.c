#include <stdio.h>

unsigned long long factorial(unsigned int n) {
    if (n == 0) {
        return 1ULL;
    }
    unsigned long long result = 1ULL;
    for (unsigned int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main(void) {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &num) != 1) {
        printf("Invalid input\n");
        return 1;
    }

    unsigned long long fact = factorial(num);
    printf("Factorial of %u is %llu\n", num, fact);
    return 0;
}
