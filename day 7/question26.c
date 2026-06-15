#include <stdio.h>

// Recursive function to calculate Fibonacci number
int fibonacci(int n) {
    // Base cases: F(0) = 0, F(1) = 1
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }
    // Recursive case: F(n) = F(n-1) + F(n-2)
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    // Validate input
    if (num < 0) {
        printf("Fibonacci is not defined for negative numbers.\n");
    }
    else {
        int result = fibonacci(num);
        printf("Fibonacci number at position %d is %d\n", num, result);
    }
    
    return 0;
}
