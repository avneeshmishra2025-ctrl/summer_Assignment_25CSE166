#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_TITLE 50
#define MAX_AUTHOR 50

int main(void)
{
    char titles[MAX_BOOKS][MAX_TITLE];
    char authors[MAX_BOOKS][MAX_AUTHOR];
    int available[MAX_BOOKS];
    int count = 0;
    int choice;

    while (1)
    {
        printf("\n===== Mini Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            if (count >= MAX_BOOKS)
            {
                printf("Library is full.\n");
                continue;
            }

            printf("Enter book title: ");
            fgets(titles[count], MAX_TITLE, stdin);
            titles[count][strcspn(titles[count], "\n")] = '\0';

            printf("Enter author name: ");
            fgets(authors[count], MAX_AUTHOR, stdin);
            authors[count][strcspn(authors[count], "\n")] = '\0';

            printf("Enter 1 if available, 0 if borrowed: ");
            scanf("%d", &available[count]);
            getchar();

            count++;
            printf("Book added successfully!\n");
        }
        else if (choice == 2)
        {
            if (count == 0)
            {
                printf("No books available.\n");
            }
            else
            {
                printf("\n--- Library Books ---\n");
                for (int i = 0; i < count; i++)
                {
                    printf("Title: %s\n", titles[i]);
                    printf("Author: %s\n", authors[i]);
                    printf("Status: %s\n", available[i] ? "Available" : "Borrowed");
                    printf("------------------------\n");
                }
            }
        }
        else if (choice == 3)
        {
            char searchTitle[MAX_TITLE];
            int found = 0;

            printf("Enter title to search: ");
            fgets(searchTitle, MAX_TITLE, stdin);
            searchTitle[strcspn(searchTitle, "\n")] = '\0';

            for (int i = 0; i < count; i++)
            {
                if (strcmp(titles[i], searchTitle) == 0)
                {
                    printf("\nBook found!\n");
                    printf("Title: %s\n", titles[i]);
                    printf("Author: %s\n", authors[i]);
                    printf("Status: %s\n", available[i] ? "Available" : "Borrowed");
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Book not found.\n");
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
