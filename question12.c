#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(void) {
    int a, b;

    printf("Enter two integers: ");
    if (scanf("%d %d", &a, &b) != 2) {
        printf("Invalid input\n");
        return 1;
    }

    if (a == 0 || b == 0) {
        printf("LCM is 0\n");
        return 0;
    }

    int g = gcd(a < 0 ? -a : a, b < 0 ? -b : b);
    long long lcm = (long long)a / g * b;
    if (lcm < 0)
        lcm = -lcm;

    printf("LCM of %d and %d is %lld\n", a, b, lcm);
    return 0;
}
