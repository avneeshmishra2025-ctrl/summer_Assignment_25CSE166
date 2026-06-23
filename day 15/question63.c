#include <stdio.h>

int main(void)
{
    int n, d;
    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size\n");
        return 1;
    }

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number of positions to rotate right: ");
    if (scanf("%d", &d) != 1 || d < 0) {
        printf("Invalid rotation count\n");
        return 1;
    }

    d %= n;
    printf("Array after right rotation by %d:\n", d);
    for (int i = 0; i < n; i++) {
        int index = (i - d + n) % n;
        printf("%d ", arr[index]);
    }
    printf("\n");

    return 0;
}
