#include <stdio.h>

void printFibonacci(int n) {
    if (n <= 0) {
        printf("No terms to display.\n");
        return;
    }

    int a = 0;
    int b = 1;

    printf("Fibonacci series: ");
    for (int i = 1; i <= n; i++) {
        printf("%d", a);
        if (i < n) {
            printf(" ");
        }
        int next = a + b;
        a = b;
        b = next;
    }
    printf("\n");
}

int main(void) {
    int count;

    printf("Enter the number of Fibonacci terms: ");
    if (scanf("%d", &count) != 1) {
        return 1;
    }

    printFibonacci(count);
    return 0;
}
