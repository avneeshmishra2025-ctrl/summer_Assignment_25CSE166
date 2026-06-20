#include <stdio.h>

int isPerfectNumber(int n) {
    if (n <= 1) {
        return 0;
    }

    int sum = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            int pair = n / i;
            if (pair != i) {
                sum += pair;
            }
        }
    }

    return sum == n;
}

int main(void) {
    int number;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        return 1;
    }

    if (isPerfectNumber(number)) {
        printf("%d is a perfect number.\n", number);
    } else {
        printf("%d is not a perfect number.\n", number);
    }

    return 0;
}
