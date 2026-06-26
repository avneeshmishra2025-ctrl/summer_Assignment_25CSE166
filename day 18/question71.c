/* Binary Search program
 * Reads integer n, then n sorted integers, then target value.
 * Prints the 0-based index of target if found, otherwise -1.
 * Example input:
 * 5
 * 1 2 3 5 8
 * 5
 * Output:
 * 3
 */
#include <stdio.h>
#include <stdlib.h>

int binary_search(int *a, int n, int target) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) { printf("-1\n"); return 0; }
    int *a = malloc((size_t)n * sizeof *a);
    if (!a) return 1;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &a[i]) != 1) a[i] = 0;
    }
    int target;
    if (scanf("%d", &target) != 1) { free(a); return 0; }
    int idx = binary_search(a, n, target);
    printf("%d\n", idx);
    free(a);
    return 0;
}
