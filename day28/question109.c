#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_BOOKS 100
#define MAX_TITLE 100
#define MAX_AUTHOR 100

typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_AUTHOR];
    int year;
    int quantity;
    int borrowed;
} Book;

static Book library[MAX_BOOKS];
static int bookCount = 0;
static int nextBookId = 1;

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        ;
    }
}

void trimNewline(char *text) {
    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') {
        text[len - 1] = '\0';
    }
}

void readLine(char *buffer, size_t size) {
    if (fgets(buffer, (int)size, stdin) == NULL) {
        buffer[0] = '\0';
        return;
    }
    trimNewline(buffer);
}

int findBookIndexByID(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            return i;
        }
    }
    return -1;
}

void addBook(void) {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = nextBookId++;
    printf("Enter book title: ");
    readLine(newBook.title, MAX_TITLE);

    printf("Enter author name: ");
    readLine(newBook.author, MAX_AUTHOR);

    printf("Enter year of publication: ");
    if (scanf("%d", &newBook.year) != 1) {
        printf("Invalid year. Book not added.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter quantity available: ");
    if (scanf("%d", &newBook.quantity) != 1 || newBook.quantity < 0) {
        printf("Invalid quantity. Book not added.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    newBook.borrowed = 0;
    library[bookCount++] = newBook;
    printf("Book added successfully with ID %d.\n", newBook.id);
}

void displayBook(const Book *book) {
    printf("ID: %d\n", book->id);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
    printf("Year: %d\n", book->year);
    printf("Available: %d\n", book->quantity - book->borrowed);
    printf("Total copies: %d\n", book->quantity);
    printf("Borrowed: %d\n", book->borrowed);
    printf("----------------------------------------\n");
}

void displayAllBooks(void) {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Library inventory:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        displayBook(&library[i]);
    }
}

void searchBookByID(void) {
    int id;
    printf("Enter book ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBookIndexByID(id);
    if (idx == -1) {
        printf("Book with ID %d not found.\n", id);
    } else {
        displayBook(&library[idx]);
    }
}

void searchBookByTitle(void) {
    char query[MAX_TITLE];
    printf("Enter title keyword to search: ");
    readLine(query, MAX_TITLE);

    int found = 0;
    for (int i = 0; i < bookCount; i++) {
        if (strstr(library[i].title, query) != NULL || strstr(library[i].author, query) != NULL) {
            if (!found) {
                printf("Search results:\n");
                printf("----------------------------------------\n");
            }
            displayBook(&library[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No books matched '%s'.\n", query);
    }
}

void borrowBook(void) {
    int id;
    printf("Enter book ID to borrow: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBookIndexByID(id);
    if (idx == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    if (library[idx].borrowed >= library[idx].quantity) {
        printf("All copies of '%s' are currently borrowed.\n", library[idx].title);
    } else {
        library[idx].borrowed++;
        printf("You have borrowed '%s'. Available copies now: %d\n",
               library[idx].title,
               library[idx].quantity - library[idx].borrowed);
    }
}

void returnBook(void) {
    int id;
    printf("Enter book ID to return: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBookIndexByID(id);
    if (idx == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    if (library[idx].borrowed <= 0) {
        printf("No copies of '%s' are currently borrowed.\n", library[idx].title);
    } else {
        library[idx].borrowed--;
        printf("You have returned '%s'. Available copies now: %d\n",
               library[idx].title,
               library[idx].quantity - library[idx].borrowed);
    }
}

void removeBook(void) {
    int id;
    printf("Enter book ID to remove: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findBookIndexByID(id);
    if (idx == -1) {
        printf("Book with ID %d not found.\n", id);
        return;
    }

    for (int i = idx; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;
    printf("Book with ID %d removed from the library.\n", id);
}

void showMenu(void) {
    printf("\nLibrary Management System\n");
    printf("1. Add book\n");
    printf("2. Display all books\n");
    printf("3. Search book by ID\n");
    printf("4. Search book by title/author keyword\n");
    printf("5. Borrow book\n");
    printf("6. Return book\n");
    printf("7. Remove book\n");
    printf("8. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    int option;

    while (1) {
        showMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number from 1 to 8.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1:
                addBook();
                break;
            case 2:
                displayAllBooks();
                break;
            case 3:
                searchBookByID();
                break;
            case 4:
                searchBookByTitle();
                break;
            case 5:
                borrowBook();
                break;
            case 6:
                returnBook();
                break;
            case 7:
                removeBook();
                break;
            case 8:
                printf("Exiting library management system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose between 1 and 8.\n");
                break;
        }
    }

    return 0;
}
