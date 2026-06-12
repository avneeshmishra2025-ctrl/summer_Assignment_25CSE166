#include <stdio.h>

int main(void)
{
    int n, i;
    unsigned long long a = 0, b = 1, next;

    printf("Enter the number of Fibonacci terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci series up to %d terms:\n", n);
    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%llu", a);
        } else if (i == 2) {
            printf(" %llu", b);
        } else {
            next = a + b;
            printf(" %llu", next);
            a = b;
            b = next;
        }
    }
    printf("\n");

    return 0;
}
