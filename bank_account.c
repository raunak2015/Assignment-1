// Bank Account Simulation using Structures in C
#include <stdio.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    char type[20];
    double balance;
};

void deposit(struct Account* acc, double amount) {
    if (amount <= 0) { printf("Invalid amount!\n"); return; }
    acc->balance += amount;
    printf("Deposited %.2f. New balance: %.2f\n", amount, acc->balance);
}

void withdraw(struct Account* acc, double amount) {
    if (amount <= 0) { printf("Invalid amount!\n"); return; }
    if (amount > acc->balance) { printf("Insufficient funds!\n"); return; }
    acc->balance -= amount;
    printf("Withdrawn %.2f. New balance: %.2f\n", amount, acc->balance);
}

void displayAccount(struct Account acc) {
    printf("\n--- Account Details ---\n");
    printf("Account No: %d\n", acc.accNo);
    printf("Name:       %s\n", acc.name);
    printf("Type:       %s\n", acc.type);
    printf("Balance:    %.2f\n", acc.balance);
}

int main() {
    struct Account acc;
    acc.accNo = 1001;
    strcpy(acc.name, "Raunak Shahu");
    strcpy(acc.type, "Savings");
    acc.balance = 5000.00;

    displayAccount(acc);
    deposit(&acc, 2500.00);
    withdraw(&acc, 800.00);
    withdraw(&acc, 10000.00);
    displayAccount(acc);

    return 0;
}
