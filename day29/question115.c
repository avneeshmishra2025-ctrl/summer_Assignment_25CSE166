#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 256

void clearInput(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void readString(const char *prompt, char str[]) {
    printf("%s", prompt);
    if (fgets(str, MAX_LEN, stdin) != NULL) {
        str[strcspn(str, "\n")] = '\0';
    }
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int isPalindrome(const char str[]) {
    char filtered[MAX_LEN];
    int len = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isalnum((unsigned char)str[i])) {
            filtered[len++] = tolower((unsigned char)str[i]);
        }
    }
    filtered[len] = '\0';

    for (int i = 0; i < len / 2; i++) {
        if (filtered[i] != filtered[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    char str1[MAX_LEN] = "";
    char str2[MAX_LEN] = "";
    char temp[MAX_LEN];
    int choice;

    while (1) {
        printf("\nString Operations Menu\n");
        printf("1. Read Strings\n");
        printf("2. Display Strings\n");
        printf("3. Length of Strings\n");
        printf("4. Copy String 1 to String 2\n");
        printf("5. Concatenate String 1 and String 2\n");
        printf("6. Compare Strings\n");
        printf("7. Reverse String 1\n");
        printf("8. Check if String 1 is Palindrome\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                readString("Enter String 1: ", str1);
                readString("Enter String 2: ", str2);
                break;
            case 2:
                printf("String 1: %s\n", str1);
                printf("String 2: %s\n", str2);
                break;
            case 3:
                printf("Length of String 1 = %zu\n", strlen(str1));
                printf("Length of String 2 = %zu\n", strlen(str2));
                break;
            case 4:
                strcpy(str2, str1);
                printf("String 2 copied from String 1.\n");
                break;
            case 5:
                if (strlen(str1) + strlen(str2) < MAX_LEN) {
                    strcat(str1, str2);
                    printf("Concatenated string stored in String 1.\n");
                } else {
                    printf("Cannot concatenate: result would exceed maximum length.\n");
                }
                break;
            case 6:
                {
                    int cmp = strcmp(str1, str2);
                    if (cmp == 0) {
                        printf("Strings are equal.\n");
                    } else if (cmp < 0) {
                        printf("String 1 is less than String 2.\n");
                    } else {
                        printf("String 1 is greater than String 2.\n");
                    }
                }
                break;
            case 7:
                strcpy(temp, str1);
                reverseString(temp);
                printf("Reversed String 1: %s\n", temp);
                break;
            case 8:
                if (isPalindrome(str1)) {
                    printf("String 1 is a palindrome.\n");
                } else {
                    printf("String 1 is not a palindrome.\n");
                }
                break;
            case 9:
                printf("Exiting string operation system.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
