#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols;
    printf("Enter number of rows and columns: ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0) {
        fprintf(stderr, "Invalid dimensions\n");
        return 1;
    }

    int **matrix = malloc(rows * sizeof(int *));
    if (!matrix) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
        if (!matrix[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid input\n");
                return 1;
            }
        }
    }

    printf("Column-wise sums:\n");
    for (int j = 0; j < cols; j++) {
        int sum = 0;
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
        printf("Sum of column %d = %d\n", j + 1, sum);
    }

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
