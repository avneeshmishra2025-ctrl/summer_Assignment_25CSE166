#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME 100

typedef struct {
    int itemId;
    char name[MAX_NAME];
    int quantity;
    double price;
} Item;

static Item inventory[MAX_ITEMS];
static int itemCount = 0;
static int nextItemId = 1;

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

int findItemIndexById(int id) {
    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].itemId == id) {
            return i;
        }
    }
    return -1;
}

void addItem(void) {
    if (itemCount >= MAX_ITEMS) {
        printf("Inventory full. Cannot add more items.\n");
        return;
    }

    Item newItem;
    newItem.itemId = nextItemId++;

    printf("Enter item name: ");
    readLine(newItem.name, MAX_NAME);
    if (strlen(newItem.name) == 0) {
        printf("Item name cannot be empty.\n");
        return;
    }

    printf("Enter quantity: ");
    if (scanf("%d", &newItem.quantity) != 1 || newItem.quantity < 0) {
        printf("Invalid quantity.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter price per unit: ");
    if (scanf("%lf", &newItem.price) != 1 || newItem.price < 0) {
        printf("Invalid price.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    inventory[itemCount++] = newItem;
    printf("Item added successfully with ID %d.\n", newItem.itemId);
}

void displayItem(const Item *item) {
    printf("Item ID: %d\n", item->itemId);
    printf("Name: %s\n", item->name);
    printf("Quantity: %d\n", item->quantity);
    printf("Price: %.2f\n", item->price);
    printf("Total value: %.2f\n", item->quantity * item->price);
    printf("----------------------------------------\n");
}

void displayAllItems(void) {
    if (itemCount == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("Inventory items:\n");
    printf("----------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        displayItem(&inventory[i]);
    }
}

void searchItem(void) {
    int id;
    printf("Enter item ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findItemIndexById(id);
    if (idx == -1) {
        printf("Item with ID %d not found.\n", id);
    } else {
        displayItem(&inventory[idx]);
    }
}

void updateItem(void) {
    int id;
    printf("Enter item ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findItemIndexById(id);
    if (idx == -1) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    printf("Enter new name (press enter to keep '%s'): ", inventory[idx].name);
    char name[MAX_NAME];
    readLine(name, MAX_NAME);
    if (strlen(name) > 0) {
        strncpy(inventory[idx].name, name, MAX_NAME - 1);
        inventory[idx].name[MAX_NAME - 1] = '\0';
    }

    printf("Enter new quantity (current %d): ", inventory[idx].quantity);
    int quantity;
    if (scanf("%d", &quantity) != 1 || quantity < 0) {
        printf("Invalid quantity.\n");
        clearInputBuffer();
        return;
    }
    inventory[idx].quantity = quantity;

    printf("Enter new price (current %.2f): ", inventory[idx].price);
    double price;
    if (scanf("%lf", &price) != 1 || price < 0) {
        printf("Invalid price.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    inventory[idx].price = price;
    printf("Item updated successfully.\n");
}

void removeItem(void) {
    int id;
    printf("Enter item ID to remove: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findItemIndexById(id);
    if (idx == -1) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    for (int i = idx; i < itemCount - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    itemCount--;
    printf("Item with ID %d removed from inventory.\n", id);
}

void showMenu(void) {
    printf("\nInventory Management System\n");
    printf("1. Add item\n");
    printf("2. Display all items\n");
    printf("3. Search item by ID\n");
    printf("4. Update item\n");
    printf("5. Remove item\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    int option;

    while (1) {
        showMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number from 1 to 6.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1:
                addItem();
                break;
            case 2:
                displayAllItems();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                removeItem();
                break;
            case 6:
                printf("Exiting inventory management system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose between 1 and 6.\n");
                break;
        }
    }

    return 0;
}
