#include <stdio.h>

int main(void) {
    double x;
    int n;
    double result = 1.0;
    int i;

    printf("Enter base x: ");
    if (scanf("%lf", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter exponent n: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (n >= 0) {
        for (i = 0; i < n; i++) {
            result *= x;
        }
    } else {
        for (i = 0; i < -n; i++) {
            result *= x;
        }
        if (result != 0.0) {
            result = 1.0 / result;
        } else {
            printf("Result is undefined for x = 0 and negative exponent.\n");
            return 1;
        }
    }

    printf("%g^%d = %g\n", x, n, result);
    return 0;
}
