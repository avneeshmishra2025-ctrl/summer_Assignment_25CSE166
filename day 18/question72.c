/* Sort array in descending order
 * Reads integer n then n integers from stdin, sorts in descending order,
 * and prints the sorted array space-separated.
 * Example input:
 * 5
 * 5 3 8 1 2
 * Output:
 * 8 5 3 2 1
 */
#include <stdio.h>
#include <stdlib.h>

void sort_descending(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int max_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] > a[max_idx]) max_idx = j;
        }
        if (max_idx != i) {
            int t = a[i];
            a[i] = a[max_idx];
            a[max_idx] = t;
        }
    }
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    int *a = malloc((size_t)n * sizeof *a);
    if (!a) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) a[i] = 0;
    }
    sort_descending(a, n);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}
