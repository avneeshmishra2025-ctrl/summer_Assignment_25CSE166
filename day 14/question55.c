#include <stdio.h>
#include <limits.h>

int main(void) {
    int n, i;
    int largest = INT_MIN, second_largest = INT_MIN;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1) return 0;
    if (n < 2) {
        printf("Need at least two elements\n");
        return 0;
    }

    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) a[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (a[i] > largest) {
            second_largest = largest;
            largest = a[i];
        } else if (a[i] > second_largest && a[i] < largest) {
            second_largest = a[i];
        }
    }

    if (second_largest == INT_MIN) {
        printf("No second largest element found\n");
    } else {
        printf("Second largest element is %d\n", second_largest);
    }

    return 0;
}
