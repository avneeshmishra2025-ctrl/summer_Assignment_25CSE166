#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to check if s2 is a rotation of s1
int isRotation(char* s1, char* s2)
{
    int n = strlen(s1);
    int m = strlen(s2);
    
    // If lengths are not equal, s2 cannot be a rotation of s1
    if (n != m)
        return 0;
    
    // Create a temporary string with value s1 + s1
    char* temp = (char*)malloc((n * 2 + 1) * sizeof(char));
    strcpy(temp, s1);
    strcat(temp, s1);
    
    // Check if s2 is a substring of temp
    int result = (strstr(temp, s2) != NULL) ? 1 : 0;
    
    free(temp);
    return result;
}

int main()
{
    char s1[100], s2[100];
    
    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    // Remove newline character
    if (s1[strlen(s1) - 1] == '\n')
        s1[strlen(s1) - 1] = '\0';
    
    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);
    // Remove newline character
    if (s2[strlen(s2) - 1] == '\n')
        s2[strlen(s2) - 1] = '\0';
    
    if (isRotation(s1, s2))
        printf("\n'%s' is a rotation of '%s'\n", s2, s1);
    else
        printf("\n'%s' is NOT a rotation of '%s'\n", s2, s1);
    
    return 0;
}
