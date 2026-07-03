#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n1, n2;

    printf("Enter number of elements in first sorted array: ");
    if (scanf("%d", &n1) != 1 || n1 < 0) {
        fprintf(stderr, "Invalid input for first array size.\n");
        return 1;
    }

    printf("Enter number of elements in second sorted array: ");
    if (scanf("%d", &n2) != 1 || n2 < 0) {
        fprintf(stderr, "Invalid input for second array size.\n");
        return 1;
    }

    int *a = malloc(n1 * sizeof(int));
    int *b = malloc(n2 * sizeof(int));
    int *merged = malloc((n1 + n2) * sizeof(int));

    if (!a || !b || !merged) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a);
        free(b);
        free(merged);
        return 1;
    }

    printf("Enter %d sorted integers for the first array:\n", n1);
    for (int i = 0; i < n1; i++) {
        if (scanf("%d", &a[i]) != 1) {
            fprintf(stderr, "Invalid input for first array elements.\n");
            free(a);
            free(b);
            free(merged);
            return 1;
        }
    }

    printf("Enter %d sorted integers for the second array:\n", n2);
    for (int i = 0; i < n2; i++) {
        if (scanf("%d", &b[i]) != 1) {
            fprintf(stderr, "Invalid input for second array elements.\n");
            free(a);
            free(b);
            free(merged);
            return 1;
        }
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            merged[k++] = a[i++];
        } else {
            merged[k++] = b[j++];
        }
    }

    while (i < n1) {
        merged[k++] = a[i++];
    }
    while (j < n2) {
        merged[k++] = b[j++];
    }

    printf("Merged sorted array:\n");
    for (int idx = 0; idx < n1 + n2; idx++) {
        printf("%d ", merged[idx]);
    }
    printf("\n");

    free(a);
    free(b);
    free(merged);
    return 0;
}
