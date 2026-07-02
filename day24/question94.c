#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to compress a string using run-length encoding
void compressString(char* str, char* compressed)
{
    int i = 0, j = 0;
    int count;
    int len = strlen(str);
    
    while (i < len) {
        count = 1;
        
        // Count consecutive identical characters
        while (i + count < len && str[i] == str[i + count]) {
            count++;
        }
        
        // Add character to compressed string
        compressed[j++] = str[i];
        
        // Add count if greater than 1
        if (count > 1) {
            // Convert count to string
            char countStr[10];
            sprintf(countStr, "%d", count);
            
            // Append count digits to compressed string
            for (int k = 0; countStr[k] != '\0'; k++) {
                compressed[j++] = countStr[k];
            }
        }
        
        i += count;
    }
    
    compressed[j] = '\0';
}

// Function to check if compression is beneficial
int shouldCompress(char* original, char* compressed)
{
    return strlen(compressed) < strlen(original);
}

int main()
{
    char str[100], compressed[200];
    
    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    // Compress the string
    compressString(str, compressed);
    
    printf("\nOriginal string:   %s (Length: %lu)\n", str, strlen(str));
    printf("Compressed string: %s (Length: %lu)\n", compressed, strlen(compressed));
    
    if (shouldCompress(str, compressed)) {
        printf("Compression: %lu → %lu bytes (saved %lu bytes)\n", 
               strlen(str), strlen(compressed), strlen(str) - strlen(compressed));
    } else {
        printf("No compression benefit. Original string is shorter or equal.\n");
    }
    
    return 0;
}
