
#include <stdio.h>
#include <math.h>

/* Returns 1 if n is prime, 0 otherwise. Handles n <= 1 as non-prime. */
int is_prime(int n) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if (n % 2 == 0 || n % 3 == 0) return 0;
	int i;
	for (i = 5; (long long)i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return 0;
	}
	return 1;
}

/* Minimal main to demonstrate usage. Reads an integer and prints result. */
int main(void) {
	int x;
	if (scanf("%d", &x) != 1) return 0;
	if (is_prime(x))
		printf("%d is prime\n", x);
	else
		printf("%d is not prime\n", x);
	return 0;
}
