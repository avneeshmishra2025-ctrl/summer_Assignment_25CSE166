#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 10
#define MAX_ACCOUNTS 5

typedef struct {
    char type[10];      // "Deposit" or "Withdrawal"
    double amount;
    time_t timestamp;
} Transaction;

typedef struct {
    char accountHolder[50];
    double balance;
    int pin;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("❌ Maximum accounts reached!\n");
        return;
    }
    
    printf("\n========== CREATE NEW ACCOUNT ==========\n");
    printf("Enter account holder name: ");
    fgets(accounts[accountCount].accountHolder, sizeof(accounts[accountCount].accountHolder), stdin);
    accounts[accountCount].accountHolder[strcspn(accounts[accountCount].accountHolder, "\n")] = 0;
    
    printf("Enter a 4-digit PIN: ");
    scanf("%d", &accounts[accountCount].pin);
    getchar();
    
    accounts[accountCount].balance = 0.0;
    accounts[accountCount].transactionCount = 0;
    
    printf("✓ Account created successfully!\n");
    accountCount++;
}

int loginAccount(Account **loggedAccount) {
    char name[50];
    int pin;
    int i;
    
    printf("\n========== LOGIN ==========\n");
    printf("Enter account holder name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("Enter PIN: ");
    scanf("%d", &pin);
    getchar();
    
    for (i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountHolder, name) == 0 && accounts[i].pin == pin) {
            *loggedAccount = &accounts[i];
            printf("✓ Login successful! Welcome %s\n", name);
            return 1;
        }
    }
    
    printf("❌ Invalid name or PIN!\n");
    return 0;
}

void addTransaction(Account *account, const char *type, double amount) {
    if (account->transactionCount < MAX_TRANSACTIONS) {
        strcpy(account->transactions[account->transactionCount].type, type);
        account->transactions[account->transactionCount].amount = amount;
        account->transactions[account->transactionCount].timestamp = time(NULL);
        account->transactionCount++;
    }
}

void checkBalance(Account *account) {
    printf("\n========== ACCOUNT BALANCE ==========\n");
    printf("Account Holder: %s\n", account->accountHolder);
    printf("Current Balance: $%.2f\n", account->balance);
    printf("====================================\n");
}

void withdraw(Account *account) {
    double amount;
    
    printf("\n========== WITHDRAWAL ==========\n");
    printf("Current Balance: $%.2f\n", account->balance);
    printf("Enter withdrawal amount: $");
    scanf("%lf", &amount);
    getchar();
    
    if (amount <= 0) {
        printf("❌ Invalid amount! Must be greater than 0.\n");
        return;
    }
    
    if (amount > account->balance) {
        printf("❌ Insufficient funds! Available: $%.2f\n", account->balance);
        return;
    }
    
    account->balance -= amount;
    addTransaction(account, "Withdrawal", amount);
    printf("✓ Withdrawal successful!\n");
    printf("Remaining Balance: $%.2f\n", account->balance);
}

void deposit(Account *account) {
    double amount;
    
    printf("\n========== DEPOSIT ==========\n");
    printf("Current Balance: $%.2f\n", account->balance);
    printf("Enter deposit amount: $");
    scanf("%lf", &amount);
    getchar();
    
    if (amount <= 0) {
        printf("❌ Invalid amount! Must be greater than 0.\n");
        return;
    }
    
    account->balance += amount;
    addTransaction(account, "Deposit", amount);
    printf("✓ Deposit successful!\n");
    printf("New Balance: $%.2f\n", account->balance);
}

void viewTransactionHistory(Account *account) {
    int i;
    
    printf("\n========== TRANSACTION HISTORY ==========\n");
    printf("Account: %s\n\n", account->accountHolder);
    
    if (account->transactionCount == 0) {
        printf("No transactions yet.\n");
    } else {
        printf("%-15s %-15s %-20s\n", "Type", "Amount", "Date & Time");
        printf("================================================\n");
        
        for (i = 0; i < account->transactionCount; i++) {
            printf("%-15s $%-14.2f %s", 
                   account->transactions[i].type,
                   account->transactions[i].amount,
                   ctime(&account->transactions[i].timestamp));
        }
    }
    printf("========================================\n");
}

void atmMenu(Account *loggedAccount) {
    int choice;
    
    while (1) {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. View Transaction History\n");
        printf("5. Logout\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                checkBalance(loggedAccount);
                break;
            case 2:
                withdraw(loggedAccount);
                break;
            case 3:
                deposit(loggedAccount);
                break;
            case 4:
                viewTransactionHistory(loggedAccount);
                break;
            case 5:
                printf("✓ Logged out successfully!\n");
                return;
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    int choice;
    Account *loggedAccount = NULL;
    
    printf("====== WELCOME TO ATM SIMULATION ======\n\n");
    
    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Create New Account\n");
        printf("2. Login to Account\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        getchar();
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (loginAccount(&loggedAccount)) {
                    atmMenu(loggedAccount);
                }
                break;
            case 3:
                printf("\nThank you for using our ATM. Goodbye!\n");
                return 0;
            default:
                printf("❌ Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
