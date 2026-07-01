#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1001];
    if (!fgets(s, sizeof(s), stdin)) {
        return 0;
    }

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        len--;
    }

    int freq[256] = {0};
    for (size_t i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)s[i];
        freq[ch]++;
    }

    int maxCount = 0;
    unsigned char maxChar = 0;
    for (int i = 0; i < 256; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxChar = (unsigned char)i;
        }
    }

    if (maxCount > 0) {
        printf("%c\n", maxChar);
    } else {
        printf("No characters found\n");
    }

    return 0;
}
