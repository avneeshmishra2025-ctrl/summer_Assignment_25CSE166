#include <stdio.h>

int main(void) {
	int n, i, key, found = 0, pos = -1;
	if (printf("Enter number of elements: ") && fflush(stdout), scanf("%d", &n)!=1) return 0;
	if (n <= 0) {
		printf("Invalid size\n");
		return 0;
	}
	int a[n];
	printf("Enter %d elements:\n", n);
	for (i = 0; i < n; i++) {
		if (scanf("%d", &a[i])!=1) a[i]=0;
	}
	printf("Enter element to search: ");
	if (scanf("%d", &key)!=1) return 0;

	for (i = 0; i < n; i++) {
		if (a[i] == key) { found = 1; pos = i; break; }
	}

	if (found)
		printf("Element %d found at index %d\n", key, pos);
	else
		printf("Element %d not found\n", key);

	return 0;
}
