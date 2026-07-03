#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void) {
    char str1[1001];
    char str2[1001];
    bool seen1[256] = {false};
    bool seen2[256] = {false};

    printf("Enter first string: ");
    if (!fgets(str1, sizeof(str1), stdin)) {
        return 1;
    }
    printf("Enter second string: ");
    if (!fgets(str2, sizeof(str2), stdin)) {
        return 1;
    }

    // Remove newline characters if present
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    for (size_t i = 0; str1[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str1[i];
        seen1[ch] = true;
    }
    for (size_t i = 0; str2[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)str2[i];
        seen2[ch] = true;
    }

    printf("Common characters:\n");
    for (int ch = 0; ch < 256; ch++) {
        if (seen1[ch] && seen2[ch]) {
            printf("%c ", (char)ch);
        }
    }
    printf("\n");

    return 0;
}
