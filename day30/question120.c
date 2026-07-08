#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    int rollNo;
    float marks;
} Student;

void clearInputBuffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void addStudent(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS)
    {
        printf("Student list is full.\n");
        return;
    }

    printf("Enter student name: ");
    fgets(students[*count].name, NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';

    printf("Enter roll number: ");
    scanf("%d", &students[*count].rollNo);
    clearInputBuffer();

    printf("Enter marks: ");
    scanf("%f", &students[*count].marks);
    clearInputBuffer();

    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(const Student students[], int count)
{
    if (count == 0)
    {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Marks: %.2f\n", students[i].marks);
        printf("------------------------\n");
    }
}

int searchStudent(const Student students[], int count, int rollNo)
{
    for (int i = 0; i < count; i++)
    {
        if (students[i].rollNo == rollNo)
        {
            return i;
        }
    }
    return -1;
}

void deleteStudent(Student students[], int *count, int rollNo)
{
    int index = searchStudent(students, *count, rollNo);

    if (index == -1)
    {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++)
    {
        students[i] = students[i + 1];
    }

    (*count)--;
    printf("Student deleted successfully!\n");
}

int main(void)
{
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== Mini Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        if (choice == 1)
        {
            addStudent(students, &count);
        }
        else if (choice == 2)
        {
            displayStudents(students, count);
        }
        else if (choice == 3)
        {
            int roll;
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            clearInputBuffer();

            int index = searchStudent(students, count, roll);
            if (index == -1)
            {
                printf("Student not found.\n");
            }
            else
            {
                printf("\nStudent found!\n");
                printf("Name: %s\n", students[index].name);
                printf("Roll No: %d\n", students[index].rollNo);
                printf("Marks: %.2f\n", students[index].marks);
            }
        }
        else if (choice == 4)
        {
            int roll;
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            clearInputBuffer();
            deleteStudent(students, &count, roll);
        }
        else if (choice == 5)
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
