#include <stdio.h>

int main() {
    long n;
    long largestPrimeFactor = -1;
    
    printf("Enter a number: ");
    scanf("%ld", &n);
    
    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        largestPrimeFactor = 2;
        n = n / 2;
    }
    
    // Check odd factors from 3 onwards
    for (long i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            largestPrimeFactor = i;
            n = n / i;
        }
    }
    
    // If n is still greater than 1, then it's a prime factor
    if (n > 1) {
        largestPrimeFactor = n;
    }
    
    printf("Largest prime factor: %ld\n", largestPrimeFactor);
    
    return 0;
}
