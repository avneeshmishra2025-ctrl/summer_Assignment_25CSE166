#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define NAME_LEN 50

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    double price;
} Item;

void clearInput(void) {
    while (getchar() != '\n');
}

void addItem(Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full. Cannot add more items.\n");
        return;
    }

    Item item;
    item.id = *count + 1;

    printf("Enter item name: ");
    fgets(item.name, NAME_LEN, stdin);
    item.name[strcspn(item.name, "\n")] = '\0';

    printf("Enter quantity: ");
    if (scanf("%d", &item.quantity) != 1) {
        printf("Invalid quantity. Item not added.\n");
        clearInput();
        return;
    }

    printf("Enter price: ");
    if (scanf("%lf", &item.price) != 1) {
        printf("Invalid price. Item not added.\n");
        clearInput();
        return;
    }

    clearInput();
    inventory[*count] = item;
    (*count)++;
    printf("Item added with ID %d.\n", item.id);
}

int findItemIndex(Item inventory[], int count, int id) {
    for (int i = 0; i < count; i++) {
        if (inventory[i].id == id) {
            return i;
        }
    }
    return -1;
}

void removeItem(Item inventory[], int *count) {
    if (*count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int id;
    printf("Enter item ID to remove: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }

    int index = findItemIndex(inventory, *count, id);
    if (index < 0) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    for (int i = index; i < *count - 1; i++) {
        inventory[i] = inventory[i + 1];
    }
    (*count)--;
    printf("Item with ID %d removed.\n", id);
}

void updateQuantity(Item inventory[], int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int id, quantity;
    printf("Enter item ID to update quantity: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }

    int index = findItemIndex(inventory, count, id);
    if (index < 0) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    printf("Enter new quantity: ");
    if (scanf("%d", &quantity) != 1) {
        printf("Invalid quantity.\n");
        clearInput();
        return;
    }

    inventory[index].quantity = quantity;
    printf("Quantity for item ID %d updated to %d.\n", id, quantity);
}

void displayInventory(Item inventory[], int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    printf("\n%-5s %-20s %-10s %-10s\n", "ID", "Name", "Quantity", "Price");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-5d %-20s %-10d $%-9.2f\n", inventory[i].id, inventory[i].name,
               inventory[i].quantity, inventory[i].price);
    }
}

void searchItem(Item inventory[], int count) {
    if (count == 0) {
        printf("Inventory is empty.\n");
        return;
    }

    int id;
    printf("Enter item ID to search: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clearInput();
        return;
    }

    int index = findItemIndex(inventory, count, id);
    if (index < 0) {
        printf("Item with ID %d not found.\n", id);
        return;
    }

    printf("Item found:\n");
    printf("ID: %d\n", inventory[index].id);
    printf("Name: %s\n", inventory[index].name);
    printf("Quantity: %d\n", inventory[index].quantity);
    printf("Price: $%.2f\n", inventory[index].price);
}

int main(void) {
    Item inventory[MAX_ITEMS];
    int count = 0;
    int choice;

    while (1) {
        printf("\nInventory Management System\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Update quantity\n");
        printf("4. Display inventory\n");
        printf("5. Search item by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid choice. Please enter a number.\n");
            clearInput();
            continue;
        }
        clearInput();

        switch (choice) {
            case 1:
                addItem(inventory, &count);
                break;
            case 2:
                removeItem(inventory, &count);
                break;
            case 3:
                updateQuantity(inventory, count);
                break;
            case 4:
                displayInventory(inventory, count);
                break;
            case 5:
                searchItem(inventory, count);
                break;
            case 6:
                printf("Exiting inventory management system.\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
