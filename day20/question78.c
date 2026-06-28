#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    printf("Enter the order of the square matrix: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid matrix order\n");
        return 1;
    }

    int **matrix = malloc(n * sizeof(int *));
    if (!matrix) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
        if (!matrix[i]) {
            fprintf(stderr, "Memory allocation failed\n");
            return 1;
        }
    }

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                fprintf(stderr, "Invalid matrix element\n");
                return 1;
            }
        }
    }

    int symmetric = 1;
    for (int i = 0; i < n && symmetric; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                symmetric = 0;
                break;
            }
        }
    }

    if (symmetric) {
        printf("The matrix is symmetric.\n");
    } else {
        printf("The matrix is not symmetric.\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
