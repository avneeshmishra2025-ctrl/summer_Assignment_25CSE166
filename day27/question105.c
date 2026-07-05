#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define FILE_NAME "students.txt"

typedef struct {
    int id;
    char name[50];
    int age;
    float gpa;
} Student;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int loadStudents(Student students[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        *count = 0;
        return 0;
    }

    *count = 0;
    while (*count < MAX_STUDENTS && fread(&students[*count], sizeof(Student), 1, file) == 1) {
        (*count)++;
    }

    fclose(file);
    return 1;
}

int saveStudents(Student students[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&students[i], sizeof(Student), 1, file);
    }

    fclose(file);
    return 1;
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("%-8s %-20s %-6s %-6s\n", "ID", "Name", "Age", "GPA");
    printf("--------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-6d %-6.2f\n", students[i].id, students[i].name, students[i].age, students[i].gpa);
    }
}

int findStudentById(Student students[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Student list is full.\n");
        return;
    }

    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    clearInputBuffer();

    printf("Enter student name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0';

    printf("Enter student age: ");
    scanf("%d", &newStudent.age);
    clearInputBuffer();

    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);
    clearInputBuffer();

    students[*count] = newStudent;
    (*count)++;
    saveStudents(students, *count);
    printf("Student added successfully.\n");
}

void updateStudent(Student students[], int count) {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Enter new name: ");
    fgets(students[index].name, sizeof(students[index].name), stdin);
    students[index].name[strcspn(students[index].name, "\n")] = '\0';

    printf("Enter new age: ");
    scanf("%d", &students[index].age);
    clearInputBuffer();

    printf("Enter new GPA: ");
    scanf("%f", &students[index].gpa);
    clearInputBuffer();

    saveStudents(students, count);
    printf("Student updated successfully.\n");
}

void deleteStudent(Student students[], int *count) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, *count, id);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        students[i] = students[i + 1];
    }
    (*count)--;
    saveStudents(students, *count);
    printf("Student deleted successfully.\n");
}

void searchStudent(Student students[], int count) {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findStudentById(students, count, id);
    if (index == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("\nStudent Found:\n");
    printf("ID: %d\n", students[index].id);
    printf("Name: %s\n", students[index].name);
    printf("Age: %d\n", students[index].age);
    printf("GPA: %.2f\n", students[index].gpa);
}

int main(void) {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    loadStudents(students, &count);

    while (1) {
        printf("\nStudent Record Management System\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                searchStudent(students, count);
                break;
            case 4:
                updateStudent(students, count);
                break;
            case 5:
                deleteStudent(students, &count);
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
