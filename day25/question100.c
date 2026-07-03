#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n;
    printf("Enter number of words: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of words.\n");
        return 1;
    }

    while (getchar() != '\n');

    char **words = malloc(n * sizeof(char *));
    if (!words) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        words[i] = malloc(101);
        if (!words[i]) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int j = 0; j < i; j++) free(words[j]);
            free(words);
            return 1;
        }
        printf("Enter word %d: ", i + 1);
        if (!fgets(words[i], 101, stdin)) {
            fprintf(stderr, "Input error.\n");
            for (int j = 0; j <= i; j++) free(words[j]);
            free(words);
            return 1;
        }
        words[i][strcspn(words[i], "\n")] = '\0';
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }
    free(words);
    return 0;
}
