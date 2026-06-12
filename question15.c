#include <stdio.h>
#include <math.h>

int main(void)
{
    int number, original, remainder, digits = 0;
    int result = 0;

    printf("Enter an integer: ");
    if (scanf("%d", &number) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    original = number;
    int temp = number;

    if (temp == 0) {
        digits = 1;
    } else {
        while (temp != 0) {
            digits++;
            temp /= 10;
        }
    }

    temp = number;
    while (temp != 0) {
        remainder = temp % 10;
        result += (int)pow(remainder, digits);
        temp /= 10;
    }

    if (result == original) {
        printf("%d is an Armstrong number.\n", original);
    } else {
        printf("%d is not an Armstrong number.\n", original);
    }

    return 0;
}
