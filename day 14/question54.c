#include <stdio.h>

int main(void) {
    int n, i, key, count = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) {
        printf("Invalid size\n");
        return 0;
    }

    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) a[i] = 0;
    }

    printf("Enter element to count: ");
    if (scanf("%d", &key) != 1) return 0;

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            count++;
        }
    }

    if (count > 0)
        printf("Element %d occurs %d time%s\n", key, count, count == 1 ? "" : "s");
    else
        printf("Element %d not found\n", key);

    return 0;
}
