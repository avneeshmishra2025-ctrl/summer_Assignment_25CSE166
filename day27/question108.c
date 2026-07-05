#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "marksheets.txt"

typedef struct {
    int rollNo;
    char name[50];
    int marks[5];
    float percentage;
    char grade;
} StudentMarksheet;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int loadMarksheetData(StudentMarksheet students[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        *count = 0;
        return 0;
    }

    *count = 0;
    while (*count < MAX_STUDENTS && fread(&students[*count], sizeof(StudentMarksheet), 1, file) == 1) {
        (*count)++;
    }

    fclose(file);
    return 1;
}

int saveMarksheetData(StudentMarksheet students[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&students[i], sizeof(StudentMarksheet), 1, file);
    }

    fclose(file);
    return 1;
}

void calculateResult(StudentMarksheet *student) {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->marks[i];
    }

    student->percentage = (float)sum / 5.0;

    if (student->percentage >= 90) {
        student->grade = 'A';
    } else if (student->percentage >= 75) {
        student->grade = 'B';
    } else if (student->percentage >= 60) {
        student->grade = 'C';
    } else if (student->percentage >= 40) {
        student->grade = 'D';
    } else {
        student->grade = 'F';
    }
}

void displayMarksheet(StudentMarksheet students[], int count) {
    if (count == 0) {
        printf("No marksheet records found.\n");
        return;
    }

    printf("\nMarksheet Records:\n");
    printf("%-8s %-20s %-8s %-8s %-8s %-8s %-8s %-8s %-8s\n", "Roll No", "Name", "Sub1", "Sub2", "Sub3", "Sub4", "Sub5", "Percent", "Grade");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-8d %-8d %-8d %-8d %-8d %-8.2f %-8c\n",
               students[i].rollNo,
               students[i].name,
               students[i].marks[0],
               students[i].marks[1],
               students[i].marks[2],
               students[i].marks[3],
               students[i].marks[4],
               students[i].percentage,
               students[i].grade);
    }
}

int findStudentByRollNo(StudentMarksheet students[], int count, int rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            return i;
        }
    }
    return -1;
}

void addStudentMarksheet(StudentMarksheet students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Marksheet list is full.\n");
        return;
    }

    StudentMarksheet newStudent;
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNo);
    clearInputBuffer();

    printf("Enter student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &newStudent.marks[i]);
    }
    clearInputBuffer();

    calculateResult(&newStudent);
    students[*count] = newStudent;
    (*count)++;
    saveMarksheetData(students, *count);
    printf("Marksheet added successfully.\n");
}

void updateStudentMarksheet(StudentMarksheet students[], int count) {
    int rollNo;
    printf("Enter roll number to update: ");
    scanf("%d", &rollNo);
    clearInputBuffer();

    int index = findStudentByRollNo(students, count, rollNo);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new marks for 5 subjects:\n");
    for (int i = 0; i < 5; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &students[index].marks[i]);
    }
    clearInputBuffer();

    calculateResult(&students[index]);
    saveMarksheetData(students, count);
    printf("Marksheet updated successfully.\n");
}

void deleteStudentMarksheet(StudentMarksheet students[], int *count) {
    int rollNo;
    printf("Enter roll number to delete: ");
    scanf("%d", &rollNo);
    clearInputBuffer();

    int index = findStudentByRollNo(students, *count, rollNo);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    saveMarksheetData(students, *count);
    printf("Marksheet deleted successfully.\n");
}

void searchStudentMarksheet(StudentMarksheet students[], int count) {
    int rollNo;
    printf("Enter roll number to search: ");
    scanf("%d", &rollNo);
    clearInputBuffer();

    int index = findStudentByRollNo(students, count, rollNo);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nMarksheet Found:\n");
    printf("Roll No: %d\n", students[index].rollNo);
    printf("Name: %s\n", students[index].name);
    printf("Marks: %d, %d, %d, %d, %d\n",
           students[index].marks[0], students[index].marks[1], students[index].marks[2], students[index].marks[3], students[index].marks[4]);
    printf("Percentage: %.2f\n", students[index].percentage);
    printf("Grade: %c\n", students[index].grade);
}

int main(void) {
    StudentMarksheet students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadMarksheetData(students, &count);

    while (1) {
        printf("\nMarksheet Generation System\n");
        printf("1. Add Marksheet\n");
        printf("2. View All Marksheet\n");
        printf("3. Search Marksheet\n");
        printf("4. Update Marksheet\n");
        printf("5. Delete Marksheet\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudentMarksheet(students, &count);
                break;
            case 2:
                displayMarksheet(students, count);
                break;
            case 3:
                searchStudentMarksheet(students, count);
                break;
            case 4:
                updateStudentMarksheet(students, count);
                break;
            case 5:
                deleteStudentMarksheet(students, &count);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
