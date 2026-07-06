#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME 100

typedef struct {
    int accountNumber;
    char name[MAX_NAME];
    double balance;
    int isActive;
} Account;

static Account accounts[MAX_ACCOUNTS];
static int accountCount = 0;
static int nextAccountNumber = 1001;

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

int findAccountIndexByNumber(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber && accounts[i].isActive) {
            return i;
        }
    }
    return -1;
}

void createAccount(void) {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = nextAccountNumber++;
    newAccount.isActive = 1;
    newAccount.balance = 0.0;

    printf("Enter account holder name: ");
    readLine(newAccount.name, MAX_NAME);
    if (strlen(newAccount.name) == 0) {
        printf("Name cannot be empty. Account not created.\n");
        return;
    }

    accounts[accountCount++] = newAccount;
    printf("Account created successfully. Account number: %d\n", newAccount.accountNumber);
}

void displayAccount(const Account *account) {
    printf("Account Number: %d\n", account->accountNumber);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
    printf("Status: %s\n", account->isActive ? "Active" : "Closed");
    printf("----------------------------------------\n");
}

void displayAllAccounts(void) {
    int found = 0;
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].isActive) {
            if (!found) {
                printf("Active accounts:\n");
                printf("----------------------------------------\n");
            }
            displayAccount(&accounts[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("No active accounts found.\n");
    }
}

void searchAccount(void) {
    int accountNumber;
    printf("Enter account number to search: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findAccountIndexByNumber(accountNumber);
    if (idx == -1) {
        printf("Account %d not found.\n", accountNumber);
    } else {
        displayAccount(&accounts[idx]);
    }
}

void deposit(void) {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter deposit amount: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid amount.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findAccountIndexByNumber(accountNumber);
    if (idx == -1) {
        printf("Account %d not found.\n", accountNumber);
        return;
    }

    accounts[idx].balance += amount;
    printf("Deposit successful. New balance: %.2f\n", accounts[idx].balance);
}

void withdraw(void) {
    int accountNumber;
    double amount;
    printf("Enter account number: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }

    printf("Enter withdrawal amount: ");
    if (scanf("%lf", &amount) != 1 || amount <= 0) {
        printf("Invalid amount.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findAccountIndexByNumber(accountNumber);
    if (idx == -1) {
        printf("Account %d not found.\n", accountNumber);
        return;
    }

    if (accounts[idx].balance < amount) {
        printf("Insufficient funds. Current balance: %.2f\n", accounts[idx].balance);
        return;
    }

    accounts[idx].balance -= amount;
    printf("Withdrawal successful. New balance: %.2f\n", accounts[idx].balance);
}

void closeAccount(void) {
    int accountNumber;
    printf("Enter account number to close: ");
    if (scanf("%d", &accountNumber) != 1) {
        printf("Invalid input.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();

    int idx = findAccountIndexByNumber(accountNumber);
    if (idx == -1) {
        printf("Account %d not found.\n", accountNumber);
        return;
    }

    accounts[idx].isActive = 0;
    printf("Account %d has been closed.\n", accountNumber);
}

void showMenu(void) {
    printf("\nBank Account System\n");
    printf("1. Create account\n");
    printf("2. Display all accounts\n");
    printf("3. Search account\n");
    printf("4. Deposit\n");
    printf("5. Withdraw\n");
    printf("6. Close account\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main(void) {
    int option;

    while (1) {
        showMenu();
        if (scanf("%d", &option) != 1) {
            printf("Invalid input. Please enter a number from 1 to 7.\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();

        switch (option) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAllAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                deposit();
                break;
            case 5:
                withdraw();
                break;
            case 6:
                closeAccount();
                break;
            case 7:
                printf("Exiting bank account system. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please choose between 1 and 7.\n");
                break;
        }
    }

    return 0;
}
