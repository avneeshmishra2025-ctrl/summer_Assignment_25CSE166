#include <stdio.h>

int main() {
    int n, sum = 0;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    // Find all divisors and their sum
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    
    // Check if the number is perfect
    if (sum == n) {
        printf("%d is a perfect number\n", n);
    } else {
        printf("%d is not a perfect number\n", n);
    }
    
    return 0;
}
