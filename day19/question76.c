#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size.\n");
        return 1;
    }

    int matrix[n][n];
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }

    printf("Sum of diagonal elements: %d\n", sum);
    return 0;
}

