#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_QUESTIONS 5
#define MAX_OPTIONS 4

typedef struct {
    char question[200];
    char options[MAX_OPTIONS][100];
    int correctAnswer;  // 1, 2, 3, or 4
} Question;

typedef struct {
    int score;
    int totalQuestions;
    int correctAnswers;
} QuizResult;

Question quizQuestions[MAX_QUESTIONS] = {
    {
        "What is the capital of France?",
        {"London", "Berlin", "Paris", "Madrid"},
        3
    },
    {
        "Which planet is known as the Red Planet?",
        {"Venus", "Mars", "Jupiter", "Saturn"},
        2
    },
    {
        "Who wrote 'Romeo and Juliet'?",
        {"Charles Dickens", "William Shakespeare", "Mark Twain", "Jane Austen"},
        2
    },
    {
        "What is the largest ocean on Earth?",
        {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
        4
    },
    {
        "In what year did the Titanic sink?",
        {"1912", "1915", "1920", "1905"},
        1
    }
};

void displayWelcome() {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║       WELCOME TO QUIZ APPLICATION  ║\n");
    printf("║     Test Your General Knowledge   ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    printf("📝 This quiz contains %d questions\n", MAX_QUESTIONS);
    printf("⏱️  You need to select the correct answer\n");
    printf("📊 Your score will be displayed at the end\n\n");
}

void displayQuestion(int questionNum, Question *q) {
    int i;
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║  Question %d of %d\n", questionNum, MAX_QUESTIONS);
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("❓ %s\n\n", q->question);
    
    for (i = 0; i < MAX_OPTIONS; i++) {
        printf("   %d) %s\n", i + 1, q->options[i]);
    }
    printf("\n");
}

int getValidAnswer() {
    int answer;
    
    while (1) {
        printf("Your answer (1-4): ");
        
        if (scanf("%d", &answer) != 1) {
            // Clear invalid input
            while (getchar() != '\n');
            printf("❌ Invalid input! Please enter a number between 1 and 4.\n");
            continue;
        }
        
        if (answer >= 1 && answer <= 4) {
            return answer;
        } else {
            printf("❌ Please enter a number between 1 and 4.\n");
        }
    }
}

void displayAnswerFeedback(int userAnswer, int correctAnswer, Question *q) {
    printf("\n");
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
    
    if (userAnswer == correctAnswer) {
        printf("✓ CORRECT! 🎉\n");
    } else {
        printf("✗ INCORRECT! ❌\n");
        printf("Your answer: %s\n", q->options[userAnswer - 1]);
    }
    
    printf("Correct answer: %s\n", q->options[correctAnswer - 1]);
    printf("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n");
}

QuizResult runQuiz() {
    QuizResult result;
    int i, userAnswer;
    
    result.correctAnswers = 0;
    result.totalQuestions = MAX_QUESTIONS;
    
    for (i = 0; i < MAX_QUESTIONS; i++) {
        displayQuestion(i + 1, &quizQuestions[i]);
        userAnswer = getValidAnswer();
        
        if (userAnswer == quizQuestions[i].correctAnswer) {
            result.correctAnswers++;
        }
        
        displayAnswerFeedback(userAnswer, quizQuestions[i].correctAnswer, &quizQuestions[i]);
    }
    
    result.score = (result.correctAnswers * 100) / MAX_QUESTIONS;
    return result;
}

void displayResults(QuizResult result) {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║           QUIZ COMPLETED!          ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    printf("📊 YOUR RESULTS:\n");
    printf("   Correct Answers: %d out of %d\n", result.correctAnswers, result.totalQuestions);
    printf("   Score: %d%%\n\n", result.score);
    
    if (result.score >= 90) {
        printf("   Rating: ⭐⭐⭐⭐⭐ EXCELLENT!\n");
    } else if (result.score >= 80) {
        printf("   Rating: ⭐⭐⭐⭐ VERY GOOD!\n");
    } else if (result.score >= 70) {
        printf("   Rating: ⭐⭐⭐ GOOD!\n");
    } else if (result.score >= 60) {
        printf("   Rating: ⭐⭐ FAIR!\n");
    } else {
        printf("   Rating: ⭐ NEED IMPROVEMENT!\n");
    }
    printf("\n");
}

char getRetakeChoice() {
    char choice;
    
    while (1) {
        printf("Would you like to retake the quiz? (y/n): ");
        scanf(" %c", &choice);
        
        if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N') {
            return tolower(choice);
        } else {
            printf("❌ Invalid input! Please enter 'y' or 'n'.\n");
        }
    }
}

int main() {
    QuizResult result;
    char retake;
    
    displayWelcome();
    
    while (1) {
        result = runQuiz();
        displayResults(result);
        
        retake = getRetakeChoice();
        if (retake == 'n') {
            break;
        }
        printf("\n");
    }
    
    printf("\n╔════════════════════════════════════╗\n");
    printf("║  Thank you for taking the quiz!   ║\n");
    printf("║       Keep learning! Goodbye!      ║\n");
    printf("╚════════════════════════════════════╝\n\n");
    
    return 0;
}
