#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Approach 1: Brute force - Check all pairs (O(n²) time, O(1) space)
void findPairBruteForce(int arr[], int n, int target) {
    printf("Brute force approach:\n");
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Pair found: (%d, %d)\n", arr[i], arr[j]);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No pair found with sum %d\n", target);
    }
}

// Approach 2: Two-pointer technique (O(n log n) time due to sorting, O(1) space)
void findPairTwoPointer(int arr[], int n, int target) {
    printf("\nTwo-pointer approach:\n");
    
    // Create copy and sort
    int *temp = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    qsort(temp, n, sizeof(int), compare);
    
    int left = 0, right = n - 1;
    int found = 0;
    
    while (left < right) {
        int sum = temp[left] + temp[right];
        
        if (sum == target) {
            printf("Pair found: (%d, %d)\n", temp[left], temp[right]);
            found = 1;
            left++;
            right--;
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    
    if (!found) {
        printf("No pair found with sum %d\n", target);
    }
    
    free(temp);
}

// Approach 3: Hash set approach simulation using array (O(n) time average, O(n) space)
void findPairHashSet(int arr[], int n, int target) {
    printf("\nHash set approach:\n");
    
    // Using a simple approach: for each element, check if (target - element) exists
    int found = 0;
    
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] == complement) {
                printf("Pair found: (%d, %d)\n", arr[i], complement);
                found = 1;
            }
        }
    }
    
    if (!found) {
        printf("No pair found with sum %d\n", target);
    }
}

int main() {
    // Test case 1: Array with multiple pairs
    int arr1[] = {1, 5, 7, -1, 5};
    int n1 = 5;
    int target1 = 6;
    
    printf("=== Test Case 1 ===\n");
    printf("Array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\nTarget sum: %d\n", target1);
    findPairBruteForce(arr1, n1, target1);
    findPairTwoPointer(arr1, n1, target1);
    findPairHashSet(arr1, n1, target1);
    
    // Test case 2: Array with no valid pair
    int arr2[] = {2, 4, 6, 8};
    int n2 = 4;
    int target2 = 15;
    
    printf("\n=== Test Case 2 ===\n");
    printf("Array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\nTarget sum: %d\n", target2);
    findPairBruteForce(arr2, n2, target2);
    findPairTwoPointer(arr2, n2, target2);
    findPairHashSet(arr2, n2, target2);
    
    // Test case 3: Array with one valid pair
    int arr3[] = {10, 20, 30, 40, 50};
    int n3 = 5;
    int target3 = 50;
    
    printf("\n=== Test Case 3 ===\n");
    printf("Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\nTarget sum: %d\n", target3);
    findPairBruteForce(arr3, n3, target3);
    findPairTwoPointer(arr3, n3, target3);
    findPairHashSet(arr3, n3, target3);
    
    // Test case 4: Array with negative numbers
    int arr4[] = {-5, -2, 0, 3, 7, 10};
    int n4 = 6;
    int target4 = 5;
    
    printf("\n=== Test Case 4 ===\n");
    printf("Array: ");
    for (int i = 0; i < n4; i++) {
        printf("%d ", arr4[i]);
    }
    printf("\nTarget sum: %d\n", target4);
    findPairBruteForce(arr4, n4, target4);
    findPairTwoPointer(arr4, n4, target4);
    findPairHashSet(arr4, n4, target4);
    
    return 0;
}
