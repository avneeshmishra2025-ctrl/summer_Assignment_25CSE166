#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int n, i, j;
    bool foundDuplicate = false;

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

    printf("Duplicate elements:\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                bool alreadyPrinted = false;
                for (int k = 0; k < i; k++) {
                    if (a[k] == a[i]) {
                        alreadyPrinted = true;
                        break;
                    }
                }
                if (!alreadyPrinted) {
                    printf("%d\n", a[i]);
                    foundDuplicate = true;
                }
                break;
            }
        }
    }

    if (!foundDuplicate) {
        printf("No duplicates found\n");
    }

    return 0;
}
