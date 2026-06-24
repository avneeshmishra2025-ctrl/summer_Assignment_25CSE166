#include <stdio.h>

// Function to find missing number in array
int findMissing(int arr[], int n) {
    // Sum of first (n+1) natural numbers = (n+1) * (n+2) / 2
    long expectedSum = (long)(n + 1) * (n + 2) / 2;
    
    // Calculate actual sum of array elements
    long actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += arr[i];
    }
    
    // Missing number
    return expectedSum - actualSum;
}

int main() {
    // Test case 1: Array contains numbers 1 to 5, missing 3
    int arr1[] = {1, 2, 4, 5};
    int n1 = 4;
    printf("Test case 1:\n");
    printf("Array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nMissing number: %d\n\n", findMissing(arr1, n1));
    
    // Test case 2: Array contains numbers 1 to 6, missing 2
    int arr2[] = {1, 3, 4, 5, 6};
    int n2 = 5;
    printf("Test case 2:\n");
    printf("Array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\nMissing number: %d\n\n", findMissing(arr2, n2));
    
    // Test case 3: Array contains numbers 1 to 7, missing 7
    int arr3[] = {1, 2, 3, 4, 5, 6};
    int n3 = 6;
    printf("Test case 3:\n");
    printf("Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\nMissing number: %d\n\n", findMissing(arr3, n3));
    
    // Test case 4: Array contains numbers 1 to 10, missing 5
    int arr4[] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    int n4 = 9;
    printf("Test case 4:\n");
    printf("Array: ");
    for (int i = 0; i < n4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\nMissing number: %d\n", findMissing(arr4, n4));
    
    return 0;
}
