
#include <stdio.h>
#include <stdlib.h>

void selection_sort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (a[j] < a[min_idx]) min_idx = j;
        }
        if (min_idx != i) {
            int t = a[i];
            a[i] = a[min_idx];
            a[min_idx] = t;
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
    selection_sort(a, n);
    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar('\n');
    free(a);
    return 0;
}
