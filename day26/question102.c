#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    char citizenship[20];
    int isRegistered;
    int hasFelony;
} Voter;

void displayEligibilityStatus(Voter voter) {
    printf("\n========== VOTING ELIGIBILITY CHECK ==========\n");
    printf("Name: %s\n", voter.name);
    printf("Age: %d\n", voter.age);
    printf("Citizenship: %s\n", voter.citizenship);
    printf("Registered: %s\n", voter.isRegistered ? "Yes" : "No");
    printf("Felony Record: %s\n\n", voter.hasFelony ? "Yes" : "No");
    
    printf("ELIGIBILITY CRITERIA:\n");
    printf("✓ Age 18 or older: %s\n", voter.age >= 18 ? "PASS" : "FAIL");
    printf("✓ Citizen: %s\n", strcmp(voter.citizenship, "Yes") == 0 ? "PASS" : "FAIL");
    printf("✓ Registered to vote: %s\n", voter.isRegistered ? "PASS" : "FAIL");
    printf("✓ No felony conviction: %s\n", !voter.hasFelony ? "PASS" : "FAIL");
    
    printf("\n========== RESULT ==========\n");
    
    if (voter.age >= 18 && 
        strcmp(voter.citizenship, "Yes") == 0 && 
        voter.isRegistered && 
        !voter.hasFelony) {
        printf("✓✓✓ ELIGIBLE TO VOTE ✓✓✓\n");
    } else {
        printf("✗✗✗ NOT ELIGIBLE TO VOTE ✗✗✗\n");
        printf("\nReasons for ineligibility:\n");
        if (voter.age < 18) {
            printf("  - Age must be at least 18 years old (currently %d)\n", voter.age);
        }
        if (strcmp(voter.citizenship, "Yes") != 0) {
            printf("  - Must be a citizen of the country\n");
        }
        if (!voter.isRegistered) {
            printf("  - Must be registered to vote\n");
        }
        if (voter.hasFelony) {
            printf("  - Cannot have felony conviction\n");
        }
    }
    printf("=============================================\n\n");
}

int main() {
    int numVoters, i;
    Voter voter;
    char citizenship;
    
    printf("====== VOTING ELIGIBILITY SYSTEM ======\n\n");
    printf("How many voters would you like to check? ");
    scanf("%d", &numVoters);
    getchar();  // Clear input buffer
    
    for (i = 0; i < numVoters; i++) {
        printf("\n--- Voter %d ---\n", i + 1);
        
        printf("Enter name: ");
        fgets(voter.name, sizeof(voter.name), stdin);
        voter.name[strcspn(voter.name, "\n")] = 0;  // Remove newline
        
        printf("Enter age: ");
        scanf("%d", &voter.age);
        
        printf("Are you a citizen? (y/n): ");
        scanf(" %c", &citizenship);
        strcpy(voter.citizenship, citizenship == 'y' || citizenship == 'Y' ? "Yes" : "No");
        
        printf("Are you registered to vote? (y/n): ");
        scanf(" %c", &citizenship);
        voter.isRegistered = (citizenship == 'y' || citizenship == 'Y') ? 1 : 0;
        
        printf("Do you have a felony conviction? (y/n): ");
        scanf(" %c", &citizenship);
        voter.hasFelony = (citizenship == 'y' || citizenship == 'Y') ? 1 : 0;
        getchar();  // Clear input buffer
        
        displayEligibilityStatus(voter);
    }
    
    printf("Voting eligibility check complete!\n");
    return 0;
}
