#include<stdio.h>

// Function to remove duplicates from array
int removeDuplicates(int arr[], int n) {
    int i, j, k;
    
    // Starting with first element as unique
    k = 1;
    
    // Compare each element with other elements
    for (i = 1; i < n; i++) {
        // Check if current element is duplicate
        int isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        
        // If not duplicate, add to array
        if (!isDuplicate) {
            arr[k++] = arr[i];
        }
    }
    
    return k; // Return new length
}

int main() {
    int arr[] = {10, 20, 20, 30, 10, 40, 30, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    // Remove duplicates
    int newLength = removeDuplicates(arr, n);
    
    printf("Array after removing duplicates:\n");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    printf("Original length: %d\n", n);
    printf("New length: %d\n", newLength);
    
    return 0;
}
