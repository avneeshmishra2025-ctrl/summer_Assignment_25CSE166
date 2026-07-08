#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100
#define NAME_LEN 50
#define DEPT_LEN 30

int main(void)
{
    char names[MAX_EMPLOYEES][NAME_LEN];
    int ids[MAX_EMPLOYEES];
    char departments[MAX_EMPLOYEES][DEPT_LEN];
    float salaries[MAX_EMPLOYEES];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== Mini Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_EMPLOYEES)
            {
                printf("Employee list is full.\n");
                continue;
            }

            printf("Enter employee name: ");
            fgets(names[count], NAME_LEN, stdin);
            names[count][strcspn(names[count], "\n")] = '\0';

            printf("Enter employee ID: ");
            scanf("%d", &ids[count]);

            printf("Enter department: ");
            getchar();
            fgets(departments[count], DEPT_LEN, stdin);
            departments[count][strcspn(departments[count], "\n")] = '\0';

            printf("Enter salary: ");
            scanf("%f", &salaries[count]);
            getchar();

            count++;
            printf("Employee added successfully!\n");
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No employee records found.\n");
            }
            else
            {
                printf("\n--- Employee Records ---\n");
                for (int i = 0; i < count; i++)
                {
                    printf("Name: %s\n", names[i]);
                    printf("ID: %d\n", ids[i]);
                    printf("Department: %s\n", departments[i]);
                    printf("Salary: %.2f\n", salaries[i]);
                    printf("------------------------\n");
                }
            }
        }
        else if (choice == 3)
        {
            int targetId;
            int found = 0;

            printf("Enter employee ID to search: ");
            scanf("%d", &targetId);
            getchar();

            for (int i = 0; i < count; i++)
            {
                if (ids[i] == targetId)
                {
                    printf("\nEmployee found!\n");
                    printf("Name: %s\n", names[i]);
                    printf("ID: %d\n", ids[i]);
                    printf("Department: %s\n", departments[i]);
                    printf("Salary: %.2f\n", salaries[i]);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Employee not found.\n");
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
