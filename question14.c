#include <stdio.h>

int main(void)
{
    int n, i;
    unsigned long long a = 0, b = 1, next = 0;

    printf("Enter the term number n: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    if (n == 1) {
        next = a;
    } else if (n == 2) {
        next = b;
    } else {
        for (i = 3; i <= n; i++) {
            next = a + b;
            a = b;
            b = next;
        }
    }

    printf("The %d%s Fibonacci term is: %llu\n", n,
           (n == 1 ? "st" : n == 2 ? "nd" : n == 3 ? "rd" : "th"), next);
    return 0;
}
