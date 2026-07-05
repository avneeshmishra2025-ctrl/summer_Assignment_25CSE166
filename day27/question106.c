#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define FILE_NAME "employees.txt"

typedef struct {
    int id;
    char name[50];
    int age;
    float salary;
} Employee;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int loadEmployees(Employee employees[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        *count = 0;
        return 0;
    }

    *count = 0;
    while (*count < MAX_EMPLOYEES && fread(&employees[*count], sizeof(Employee), 1, file) == 1) {
        (*count)++;
    }

    fclose(file);
    return 1;
}

int saveEmployees(Employee employees[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&employees[i], sizeof(Employee), 1, file);
    }

    fclose(file);
    return 1;
}

void displayEmployees(Employee employees[], int count) {
    if (count == 0) {
        printf("No employee records found.\n");
        return;
    }

    printf("\nEmployee Records:\n");
    printf("%-8s %-20s %-6s %-10s\n", "ID", "Name", "Age", "Salary");
    printf("----------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-8d %-20s %-6d %-10.2f\n", employees[i].id, employees[i].name, employees[i].age, employees[i].salary);
    }
}

int findEmployeeById(Employee employees[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee list is full.\n");
        return;
    }

    Employee newEmployee;
    printf("Enter employee ID: ");
    scanf("%d", &newEmployee.id);
    clearInputBuffer();

    printf("Enter employee name: ");
    fgets(newEmployee.name, sizeof(newEmployee.name), stdin);
    newEmployee.name[strcspn(newEmployee.name, "\n")] = '\0';

    printf("Enter employee age: ");
    scanf("%d", &newEmployee.age);
    clearInputBuffer();

    printf("Enter salary: ");
    scanf("%f", &newEmployee.salary);
    clearInputBuffer();

    employees[*count] = newEmployee;
    (*count)++;
    saveEmployees(employees, *count);
    printf("Employee added successfully.\n");
}

void updateEmployee(Employee employees[], int count) {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("Enter new name: ");
    fgets(employees[index].name, sizeof(employees[index].name), stdin);
    employees[index].name[strcspn(employees[index].name, "\n")] = '\0';

    printf("Enter new age: ");
    scanf("%d", &employees[index].age);
    clearInputBuffer();

    printf("Enter new salary: ");
    scanf("%f", &employees[index].salary);
    clearInputBuffer();

    saveEmployees(employees, count);
    printf("Employee updated successfully.\n");
}

void deleteEmployee(Employee employees[], int *count) {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, *count, id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        employees[i] = employees[i + 1];
    }
    (*count)--;
    saveEmployees(employees, *count);
    printf("Employee deleted successfully.\n");
}

void searchEmployee(Employee employees[], int count) {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findEmployeeById(employees, count, id);
    if (index == -1) {
        printf("Employee not found.\n");
        return;
    }

    printf("\nEmployee Found:\n");
    printf("ID: %d\n", employees[index].id);
    printf("Name: %s\n", employees[index].name);
    printf("Age: %d\n", employees[index].age);
    printf("Salary: %.2f\n", employees[index].salary);
}

int main(void) {
    Employee employees[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    loadEmployees(employees, &count);

    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. View All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Employee\n");
        printf("5. Delete Employee\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addEmployee(employees, &count);
                break;
            case 2:
                displayEmployees(employees, count);
                break;
            case 3:
                searchEmployee(employees, count);
                break;
            case 4:
                updateEmployee(employees, count);
                break;
            case 5:
                deleteEmployee(employees, &count);
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
