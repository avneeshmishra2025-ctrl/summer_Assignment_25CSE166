#include <stdio.h>
#include <string.h>

int main(void) {
    char binary[65];
    int decimal = 0;
    int length;

    printf("Enter a binary number: ");
    if (scanf("%64s", binary) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    length = strlen(binary);
    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("Invalid binary number.\n");
            return 1;
        }
        decimal = decimal * 2 + (binary[i] - '0');
    }

    printf("Decimal: %d\n", decimal);
    return 0;
}
