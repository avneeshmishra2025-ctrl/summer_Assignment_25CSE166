#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int choice;
    double num1, num2, result;

    while (1) {
        printf("\nMenu-driven Calculator\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus (integers only)\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number between 1 and 6.\n");
            while (getchar() != '\n');
            continue;
        }

        if (choice == 6) {
            printf("Exiting calculator.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("Result: %.2f\n", result);
                }
                break;
            case 5: {
                int a, b;
                printf("Enter two integers: ");
                if (scanf("%d %d", &a, &b) != 2) {
                    printf("Invalid integer input.\n");
                    while (getchar() != '\n');
                    break;
                }
                if (b == 0) {
                    printf("Error: Modulus by zero is not allowed.\n");
                } else {
                    printf("Result: %d\n", a % b);
                }
                break;
            }
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }

        while (getchar() != '\n');
    }

    return 0;
}
