#include <stdio.h>

// Recursive function to reverse a number
void reverseNumber(int n) {
    // Base case: if n is 0, stop recursion
    if (n == 0) {
        return;
    }
    // Print the last digit
    printf("%d", n % 10);
    // Recursive call with remaining digits
    reverseNumber(n / 10);
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
        printf("Reverse of %d is: ", num);
        reverseNumber(num);
        printf("\n");
    }
    
    return 0;
}
