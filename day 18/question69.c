
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *a, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int swapped = 0;
		for (int j = 0; j < n - 1 - i; ++j) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				swapped = 1;
			}
		}
		if (!swapped) break;
	}
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	if (n <= 0) return 0;
	int *a = malloc((size_t)n * sizeof *a);
	if (!a) return 1;
	for (int i = 0; i < n; ++i) {
		if (scanf("%d", &a[i]) != 1) a[i] = 0;
	}
	bubble_sort(a, n);
	for (int i = 0; i < n; ++i) {
		if (i) putchar(' ');
		printf("%d", a[i]);
	}
	putchar('\n');
	free(a);
	return 0;
}

