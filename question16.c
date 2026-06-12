#include <stdio.h>
#include <math.h>

int power(int base, int exp)
{
    int result = 1;
    while (exp > 0) {
        result *= base;
        exp--;
    }
    return result;
}

int countDigits(int number)
{
    int digits = 0;
    if (number == 0) {
        return 1;
    }
    while (number != 0) {
        digits++;
        number /= 10;
    }
    return digits;
}

int isArmstrong(int number)
{
    int original = number;
    int digits = countDigits(number);
    int sum = 0;

    while (number != 0) {
        int digit = number % 10;
        sum += power(digit, digits);
        number /= 10;
    }

    return sum == original;
}

int main(void)
{
    int lower, upper;

    printf("Enter lower bound: ");
    if (scanf("%d", &lower) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Enter upper bound: ");
    if (scanf("%d", &upper) != 1 || upper < lower) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Armstrong numbers between %d and %d:\n", lower, upper);
    for (int i = lower; i <= upper; i++) {
        if (isArmstrong(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
