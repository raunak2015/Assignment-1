// Doubly Linked List in C
#include <stdio.h>
#include <stdlib.h>

struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
};

struct DNode* createNode(int data) {
    struct DNode* node = (struct DNode*)malloc(sizeof(struct DNode));
    node->data = data;
    node->prev = node->next = NULL;
    return node;
}

void insertFront(struct DNode** head, int data) {
    struct DNode* node = createNode(data);
    node->next = *head;
    if (*head) (*head)->prev = node;
    *head = node;
}

void insertEnd(struct DNode** head, int data) {
    struct DNode* node = createNode(data);
    if (!*head) { *head = node; return; }
    struct DNode* temp = *head;
    while (temp->next) temp = temp->next;
    temp->next = node;
    node->prev = temp;
}

void deleteNode(struct DNode** head, int key) {
    struct DNode* temp = *head;
    while (temp && temp->data != key) temp = temp->next;
    if (!temp) { printf("Not found!\n"); return; }
    if (temp->prev) temp->prev->next = temp->next;
    else *head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
}

void printForward(struct DNode* head) {
    printf("Forward:  ");
    while (head) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

void printBackward(struct DNode* head) {
    if (!head) return;
    while (head->next) head = head->next;
    printf("Backward: ");
    while (head) { printf("%d ", head->data); head = head->prev; }
    printf("\n");
}

int main() {
    struct DNode* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertFront(&head, 5);
    printForward(head);
    printBackward(head);
    deleteNode(&head, 20);
    printf("After deleting 20:\n");
    printForward(head);
    return 0;
}
