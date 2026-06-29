#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[200];
    int vowels = 0;
    int consonants = 0;

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (isalpha((unsigned char)ch)) {
            ch = tolower((unsigned char)ch);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
