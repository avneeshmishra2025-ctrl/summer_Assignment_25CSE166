#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    printf("Enter number of names: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of names.\n");
        return 1;
    }

    while (getchar() != '\n'); // clear remaining input

    char **names = malloc(n * sizeof(char *));
    if (!names) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        names[i] = malloc(101);
        if (!names[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int j = 0; j < i; j++) {
                free(names[j]);
            }
            free(names);
            return 1;
        }
        printf("Enter name %d: ", i + 1);
        if (!fgets(names[i], 101, stdin)) {
            fprintf(stderr, "Input error.\n");
            for (int j = 0; j <= i; j++) {
                free(names[j]);
            }
            free(names);
            return 1;
        }
        names[i][strcspn(names[i], "\n")] = '\0';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    printf("\nNames sorted alphabetically:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
        free(names[i]);
    }
    free(names);
    return 0;
}
