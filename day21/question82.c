#include <stdio.h>

void reverse_string(char *s) {
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }

    int left = 0;
    int right = len - 1;
    while (left < right) {
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int main(void) {
    char str[100];

    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            str[i] = '\0';
            break;
        }
        i++;
    }

    reverse_string(str);
    printf("Reversed string: %s\n", str);
    return 0;
}
