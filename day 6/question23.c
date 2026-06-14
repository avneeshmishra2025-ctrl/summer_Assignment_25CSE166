#include <stdio.h>

int main(void) {
    unsigned int num;
    unsigned int count = 0;

    printf("Enter a number: ");
    if (scanf("%u", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }

    printf("Number of set bits: %u\n", count);
    return 0;
}
