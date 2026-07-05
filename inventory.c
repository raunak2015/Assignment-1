// Inventory Management System using Structures
#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem(int id, char* name, int qty, float price) {
    if (itemCount >= MAX_ITEMS) { printf("Inventory full!\n"); return; }
    inventory[itemCount].id = id;
    strcpy(inventory[itemCount].name, name);
    inventory[itemCount].quantity = qty;
    inventory[itemCount].price = price;
    itemCount++;
}

void displayAll() {
    printf("\n%-5s %-20s %-10s %-10s %-12s\n", "ID", "Name", "Qty", "Price", "Total Value");
    printf("%-5s %-20s %-10s %-10s %-12s\n", "---", "----", "---", "-----", "-----------");
    float grandTotal = 0;
    for (int i = 0; i < itemCount; i++) {
        float total = inventory[i].quantity * inventory[i].price;
        grandTotal += total;
        printf("%-5d %-20s %-10d %-10.2f %-12.2f\n",
            inventory[i].id, inventory[i].name,
            inventory[i].quantity, inventory[i].price, total);
    }
    printf("Grand Total Value: %.2f\n", grandTotal);
}

struct Item* searchById(int id) {
    for (int i = 0; i < itemCount; i++)
        if (inventory[i].id == id) return &inventory[i];
    return NULL;
}

int main() {
    addItem(101, "Pencil", 200, 2.50);
    addItem(102, "Notebook", 50, 45.00);
    addItem(103, "Pen", 150, 15.00);
    addItem(104, "Eraser", 100, 5.00);
    addItem(105, "Ruler", 75, 12.00);

    displayAll();

    struct Item* found = searchById(103);
    if (found) printf("\nFound: %s (Qty: %d)\n", found->name, found->quantity);

    return 0;
}
