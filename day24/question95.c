#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function to find the longest word in a string
void findLongestWord(char* str, char* longestWord)
{
    char word[100];
    int i = 0, j = 0;
    int maxLen = 0;
    int currentLen = 0;
    
    strcpy(longestWord, "");
    
    while (str[i] != '\0') {
        // Check if character is part of a word (alphanumeric)
        if (isalnum(str[i])) {
            word[j++] = str[i];
            currentLen++;
        } else {
            // End of word reached
            if (currentLen > 0) {
                word[j] = '\0';
                
                // Update longest word if current word is longer
                if (currentLen > maxLen) {
                    maxLen = currentLen;
                    strcpy(longestWord, word);
                }
                
                j = 0;
                currentLen = 0;
            }
        }
        i++;
    }
    
    // Check the last word (in case string doesn't end with space)
    if (currentLen > 0) {
        word[j] = '\0';
        if (currentLen > maxLen) {
            strcpy(longestWord, word);
        }
    }
}

int main()
{
    char str[500], longestWord[100];
    
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character
    if (str[strlen(str) - 1] == '\n')
        str[strlen(str) - 1] = '\0';
    
    // Find the longest word
    findLongestWord(str, longestWord);
    
    if (strlen(longestWord) > 0) {
        printf("\nLongest word: '%s'\n", longestWord);
        printf("Length: %lu\n", strlen(longestWord));
    } else {
        printf("\nNo words found in the input.\n");
    }
    
    return 0;
}
