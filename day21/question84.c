#include <stdio.h>
#include <ctype.h>

int main(void) {
    char str[200];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper((unsigned char)str[i]);
    }

    printf("Uppercase string: %s", str);
    return 0;
}
