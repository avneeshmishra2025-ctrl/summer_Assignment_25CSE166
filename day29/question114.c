#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void readArray(int arr[], int *n) {
    int i;
    printf("Enter number of elements (1-%d): ", MAX_SIZE);
    scanf("%d", n);
    if (*n < 1 || *n > MAX_SIZE) {
        printf("Invalid size, using 0 elements.\n");
        *n = 0;
        return;
    }
    for (i = 0; i < *n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void displayArray(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }
    printf("Array elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

void minMaxArray(int arr[], int n, int *min, int *max) {
    if (n == 0) {
        *min = 0;
        *max = 0;
        return;
    }
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min) *min = arr[i];
        if (arr[i] > *max) *max = arr[i];
    }
}

void sortArray(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int arr[MAX_SIZE];
    int n = 0;
    int choice;
    int min, max;
    int sorted = 0;

    while (1) {
        printf("\nArray Operations Menu\n");
        printf("1. Read array\n");
        printf("2. Display array\n");
        printf("3. Sum of elements\n");
        printf("4. Average of elements\n");
        printf("5. Find minimum and maximum\n");
        printf("6. Sort array in ascending order\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                readArray(arr, &n);
                sorted = 0;
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Sum of elements = %d\n", sumArray(arr, n));
                }
                break;
            case 4:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    printf("Average of elements = %.2f\n", (double)sumArray(arr, n) / n);
                }
                break;
            case 5:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    minMaxArray(arr, n, &min, &max);
                    printf("Minimum = %d, Maximum = %d\n", min, max);
                }
                break;
            case 6:
                if (n == 0) {
                    printf("Array is empty.\n");
                } else {
                    sortArray(arr, n);
                    sorted = 1;
                    printf("Array sorted in ascending order.\n");
                }
                break;
            case 7:
                printf("Exiting array operations system.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}
