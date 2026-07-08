#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

int main(void)
{
    char names[MAX_STUDENTS][NAME_LEN];
    int rollNo[MAX_STUDENTS];
    float marks[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== Student Record System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_STUDENTS)
            {
                printf("Student list is full.\n");
                continue;
            }

            printf("Enter student name: ");
            fgets(names[count], NAME_LEN, stdin);
            names[count][strcspn(names[count], "\n")] = '\0';

            printf("Enter roll number: ");
            scanf("%d", &rollNo[count]);

            printf("Enter marks: ");
            scanf("%f", &marks[count]);
            getchar();

            count++;
            printf("Student added successfully!\n");
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No student records found.\n");
            }
            else
            {
                printf("\n--- Student Records ---\n");
                for (int i = 0; i < count; i++)
                {
                    printf("Name: %s\n", names[i]);
                    printf("Roll No: %d\n", rollNo[i]);
                    printf("Marks: %.2f\n", marks[i]);
                    printf("------------------------\n");
                }
            }
        }
        else if (choice == 3)
        {
            int targetRoll;
            int found = 0;

            printf("Enter roll number to search: ");
            scanf("%d", &targetRoll);
            getchar();

            for (int i = 0; i < count; i++)
            {
                if (rollNo[i] == targetRoll)
                {
                    printf("\nStudent found!\n");
                    printf("Name: %s\n", names[i]);
                    printf("Roll No: %d\n", rollNo[i]);
                    printf("Marks: %.2f\n", marks[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student not found.\n");
            }
        }
        else if (choice == 4)
        {
            printf("Exiting program.\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
