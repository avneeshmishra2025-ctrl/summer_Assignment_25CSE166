#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to remove duplicate characters from a string
void removeDuplicates(char* str, char* result)
{
    int i = 0, j = 0;
    int seen[256] = {0};  // Array to track seen characters (ASCII range)
    
    while (str[i] != '\0') {
        // If character not seen before, add to result
        if (!seen[(unsigned char)str[i]]) {
            result[j++] = str[i];
            seen[(unsigned char)str[i]] = 1;
        }
        i++;
    }
    
    result[j] = '\0';
}

// Alternative function using character position tracking
void removeDuplicatesAlternative(char* str, char* result)
{
    int i = 0, j = 0;
    int len = strlen(str);
    
    while (i < len) {
        int found = 0;
        
        // Check if character already exists in result
        for (int k = 0; k < j; k++) {
            if (result[k] == str[i]) {
                found = 1;
                break;
            }
        }
        
        // If not found, add to result
        if (!found) {
            result[j++] = str[i];
        }
        
        i++;
    }
    
    result[j] = '\0';
}

int main()
{
    char str[100], result[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    // Remove duplicates
    removeDuplicates(str, result);
    
    printf("\nOriginal string:  %s\n", str);
    printf("After removing duplicates: %s\n", result);
    printf("Original length: %lu\n", strlen(str));
    printf("New length: %lu\n", strlen(result));
    
    return 0;
}
