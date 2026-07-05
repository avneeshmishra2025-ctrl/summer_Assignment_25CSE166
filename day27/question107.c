#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define FILE_NAME "salaries.txt"

typedef struct {
    int employeeId;
    char employeeName[50];
    float basicSalary;
    float allowance;
    float deduction;
    float netSalary;
} SalaryRecord;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int loadSalaryRecords(SalaryRecord records[], int *count) {
    FILE *file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        *count = 0;
        return 0;
    }

    *count = 0;
    while (*count < MAX_RECORDS && fread(&records[*count], sizeof(SalaryRecord), 1, file) == 1) {
        (*count)++;
    }

    fclose(file);
    return 1;
}

int saveSalaryRecords(SalaryRecord records[], int count) {
    FILE *file = fopen(FILE_NAME, "wb");
    if (file == NULL) {
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&records[i], sizeof(SalaryRecord), 1, file);
    }

    fclose(file);
    return 1;
}

void displaySalaryRecords(SalaryRecord records[], int count) {
    if (count == 0) {
        printf("No salary records found.\n");
        return;
    }

    printf("\nSalary Records:\n");
    printf("%-10s %-20s %-12s %-10s %-10s %-12s\n", "Emp ID", "Name", "Basic", "Allowance", "Deduction", "Net Salary");
    printf("--------------------------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-12.2f %-10.2f %-10.2f %-12.2f\n",
               records[i].employeeId,
               records[i].employeeName,
               records[i].basicSalary,
               records[i].allowance,
               records[i].deduction,
               records[i].netSalary);
    }
}

int findRecordById(SalaryRecord records[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (records[i].employeeId == id) {
            return i;
        }
    }
    return -1;
}

void addSalaryRecord(SalaryRecord records[], int *count) {
    if (*count >= MAX_RECORDS) {
        printf("Salary record list is full.\n");
        return;
    }

    SalaryRecord newRecord;
    printf("Enter employee ID: ");
    scanf("%d", &newRecord.employeeId);
    clearInputBuffer();

    printf("Enter employee name: ");
    fgets(newRecord.employeeName, sizeof(newRecord.employeeName), stdin);
    newRecord.employeeName[strcspn(newRecord.employeeName, "\n")] = '\0';

    printf("Enter basic salary: ");
    scanf("%f", &newRecord.basicSalary);
    clearInputBuffer();

    printf("Enter allowance: ");
    scanf("%f", &newRecord.allowance);
    clearInputBuffer();

    printf("Enter deduction: ");
    scanf("%f", &newRecord.deduction);
    clearInputBuffer();

    newRecord.netSalary = newRecord.basicSalary + newRecord.allowance - newRecord.deduction;

    records[*count] = newRecord;
    (*count)++;
    saveSalaryRecords(records, *count);
    printf("Salary record added successfully.\n");
}

void updateSalaryRecord(SalaryRecord records[], int count) {
    int id;
    printf("Enter employee ID to update: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findRecordById(records, count, id);
    if (index == -1) {
        printf("Salary record not found.\n");
        return;
    }

    printf("Enter new basic salary: ");
    scanf("%f", &records[index].basicSalary);
    clearInputBuffer();

    printf("Enter new allowance: ");
    scanf("%f", &records[index].allowance);
    clearInputBuffer();

    printf("Enter new deduction: ");
    scanf("%f", &records[index].deduction);
    clearInputBuffer();

    records[index].netSalary = records[index].basicSalary + records[index].allowance - records[index].deduction;

    saveSalaryRecords(records, count);
    printf("Salary record updated successfully.\n");
}

void deleteSalaryRecord(SalaryRecord records[], int *count) {
    int id;
    printf("Enter employee ID to delete: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findRecordById(records, *count, id);
    if (index == -1) {
        printf("Salary record not found.\n");
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        records[i] = records[i + 1];
    }
    (*count)--;
    saveSalaryRecords(records, *count);
    printf("Salary record deleted successfully.\n");
}

void searchSalaryRecord(SalaryRecord records[], int count) {
    int id;
    printf("Enter employee ID to search: ");
    scanf("%d", &id);
    clearInputBuffer();

    int index = findRecordById(records, count, id);
    if (index == -1) {
        printf("Salary record not found.\n");
        return;
    }

    printf("\nSalary Record Found:\n");
    printf("Employee ID: %d\n", records[index].employeeId);
    printf("Name: %s\n", records[index].employeeName);
    printf("Basic Salary: %.2f\n", records[index].basicSalary);
    printf("Allowance: %.2f\n", records[index].allowance);
    printf("Deduction: %.2f\n", records[index].deduction);
    printf("Net Salary: %.2f\n", records[index].netSalary);
}

int main(void) {
    SalaryRecord records[MAX_RECORDS];
    int count = 0;
    int choice;

    loadSalaryRecords(records, &count);

    while (1) {
        printf("\nSalary Management System\n");
        printf("1. Add Salary Record\n");
        printf("2. View All Salary Records\n");
        printf("3. Search Salary Record\n");
        printf("4. Update Salary Record\n");
        printf("5. Delete Salary Record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        clearInputBuffer();

        switch (choice) {
            case 1:
                addSalaryRecord(records, &count);
                break;
            case 2:
                displaySalaryRecords(records, count);
                break;
            case 3:
                searchSalaryRecord(records, count);
                break;
            case 4:
                updateSalaryRecord(records, count);
                break;
            case 5:
                deleteSalaryRecord(records, &count);
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
