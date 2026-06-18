#include <stdio.h>

int main(void) {
    int rows = 5;

    for (int i = 1; i <= rows; i++) {
        for (int j = 0; j < i; j++) {
            putchar('A' + j);
        }
        for (int j = i - 2; j >= 0; j--) {
            putchar('A' + j);
        }
        putchar('\n');
    }

    return 0;
}
