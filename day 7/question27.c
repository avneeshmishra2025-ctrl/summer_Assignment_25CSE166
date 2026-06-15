#include <stdio.h>

// Recursive function to calculate sum of digits
int sumOfDigits(int n) {
    // Base case: if n is 0, sum is 0
    if (n == 0) {
        return 0;
    }
    // Recursive case: add last digit and sum of remaining digits
    else {
        return (n % 10) + sumOfDigits(n / 10);
    }
}

int main() {
    int num;
    
    printf("Enter a non-negative integer: ");
    scanf("%d", &num);
    
    // Validate input
    if (num < 0) {
        printf("Please enter a non-negative number.\n");
    }
    else {
        int result = sumOfDigits(num);
        printf("Sum of digits of %d is %d\n", num, result);
    }
    
    return 0;
}
