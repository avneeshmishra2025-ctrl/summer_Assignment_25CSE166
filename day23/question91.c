#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char s1[1001], s2[1001];
    if (!fgets(s1, sizeof(s1), stdin) || !fgets(s2, sizeof(s2), stdin)) {
        return 0;
    }

    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    if (len1 > 0 && s1[len1 - 1] == '\n') {
        s1[len1 - 1] = '\0';
        len1--;
    }
    if (len2 > 0 && s2[len2 - 1] == '\n') {
        s2[len2 - 1] = '\0';
        len2--;
    }

    if (len1 != len2) {
        printf("Not anagrams\n");
        return 0;
    }

    int freq[256] = {0};
    for (size_t i = 0; i < len1; i++) {
        unsigned char c = (unsigned char)tolower((unsigned char)s1[i]);
        freq[c]++;
    }
    for (size_t i = 0; i < len2; i++) {
        unsigned char c = (unsigned char)tolower((unsigned char)s2[i]);
        freq[c]--;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("Not anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}
