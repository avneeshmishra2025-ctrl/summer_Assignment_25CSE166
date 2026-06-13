#include <stdio.h>

int factorial(int n) {
    int fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int n, temp, sum = 0, digit;
    
    printf("Enter a number: ");
    scanf("%d", &n);
    
    temp = n;
    
    // Calculate sum of factorials of digits
    while (temp > 0) {
        digit = temp % 10;
        sum += factorial(digit);
        temp /= 10;
    }
    
    // Check if the number is strong
    if (sum == n) {
        printf("%d is a strong number\n", n);
    } else {
        printf("%d is not a strong number\n", n);
    }
    
    return 0;
}
