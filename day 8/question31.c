#include <stdio.h>

int main() {
    int rows, i;

    printf("Enter the number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    for (i = 0; i < rows; i++) {
        printf("A B C D\n");
    }

    return 0;
}
