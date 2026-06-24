#include <stdio.h>

// Function to find element with maximum frequency
int findMaxFrequency(int arr[], int n) {
    int maxElement = arr[0];
    int maxCount = 1;
    
    // Count frequency of each element
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        // Update if current element has higher frequency
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    
    return maxElement;
}

// Optimized function using single pass (for positive integers)
int findMaxFrequencyOptimized(int arr[], int n) {
    int maxElement = arr[0];
    int maxCount = 1;
    
    for (int i = 0; i < n; i++) {
        int count = 0;
        // Count occurrences only for elements we haven't checked
        for (int j = i; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        if (count > maxCount) {
            maxCount = count;
            maxElement = arr[i];
        }
    }
    
    return maxElement;
}

int main() {
    // Test case 1: Array with one element appearing most frequently
    int arr1[] = {1, 1, 1, 2, 2, 3};
    int n1 = 6;
    printf("Test case 1:\n");
    printf("Array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nMaximum frequency element: %d\n\n", findMaxFrequency(arr1, n1));
    
    // Test case 2: Different frequencies
    int arr2[] = {5, 5, 5, 5, 10, 10, 20};
    int n2 = 7;
    printf("Test case 2:\n");
    printf("Array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\nMaximum frequency element: %d\n\n", findMaxFrequency(arr2, n2));
    
    // Test case 3: Multiple elements appearing equally
    int arr3[] = {1, 2, 2, 3, 3, 3, 4};
    int n3 = 7;
    printf("Test case 3:\n");
    printf("Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\nMaximum frequency element: %d\n\n", findMaxFrequency(arr3, n3));
    
    // Test case 4: All elements appear once
    int arr4[] = {1, 2, 3, 4, 5};
    int n4 = 5;
    printf("Test case 4:\n");
    printf("Array: ");
    for (int i = 0; i < n4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\nMaximum frequency element: %d\n\n", findMaxFrequency(arr4, n4));
    
    // Test case 5: Using optimized version
    int arr5[] = {7, 7, 7, 9, 9, 15};
    int n5 = 6;
    printf("Test case 5 (Optimized):\n");
    printf("Array: ");
    for (int i = 0; i < n5; i++) {
        printf("%d ", arr5[i]);
    }
    printf("\nMaximum frequency element: %d\n", findMaxFrequencyOptimized(arr5, n5));
    
    return 0;
}
