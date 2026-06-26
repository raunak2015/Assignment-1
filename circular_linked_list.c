// Circular Linked List in C
#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode* next;
};

struct CNode* createNode(int data) {
    struct CNode* node = (struct CNode*)malloc(sizeof(struct CNode));
    node->data = data;
    node->next = node; // points to itself
    return node;
}

void insertEnd(struct CNode** head, int data) {
    struct CNode* newNode = createNode(data);
    if (!*head) { *head = newNode; return; }
    struct CNode* temp = *head;
    while (temp->next != *head) temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

void deleteNode(struct CNode** head, int key) {
    if (!*head) return;
    struct CNode* curr = *head, *prev = NULL;
    while (curr->data != key) {
        if (curr->next == *head) { printf("Not found!\n"); return; }
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == *head && prev == NULL) { free(curr); *head = NULL; return; }
    if (curr == *head) {
        prev = *head;
        while (prev->next != *head) prev = prev->next;
        *head = curr->next;
        prev->next = *head;
    } else {
        prev->next = curr->next;
    }
    free(curr);
}

void display(struct CNode* head) {
    if (!head) { printf("Empty!\n"); return; }
    struct CNode* temp = head;
    printf("Circular List: ");
    do { printf("%d -> ", temp->data); temp = temp->next; } while (temp != head);
    printf("(back to head)\n");
}

int main() {
    struct CNode* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    display(head);
    deleteNode(&head, 2);
    display(head);
    return 0;
}
