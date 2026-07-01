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

    for (size_t i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)s[i];
        if (freq[ch] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }

    printf("No non-repeating character found\n");
    return 0;
}
