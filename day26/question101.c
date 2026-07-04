#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 0;
    char playAgain;
    
    srand(time(0));  // Seed the random number generator
    
    printf("====== NUMBER GUESSING GAME ======\n");
    printf("Try to guess the secret number between 1 and 100!\n\n");
    
    do {
        secretNumber = (rand() % 100) + 1;  // Generate random number 1-100
        attempts = 0;
        
        printf("I'm thinking of a number between 1 and 100. Can you guess it?\n");
        
        while (1) {
            printf("\nEnter your guess: ");
            scanf("%d", &guess);
            attempts++;
            
            if (guess < 1 || guess > 100) {
                printf("Please enter a number between 1 and 100!\n");
                continue;
            }
            
            if (guess < secretNumber) {
                printf("Too low! Try again.\n");
            } else if (guess > secretNumber) {
                printf("Too high! Try again.\n");
            } else {
                printf("\n🎉 Congratulations! You guessed it in %d attempts!\n", attempts);
                break;
            }
        }
        
        printf("\nDo you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
        printf("\n");
        
    } while (playAgain == 'y' || playAgain == 'Y');
    
    printf("Thanks for playing! Goodbye!\n");
    return 0;
}
