// Stack Implementation using Array in C
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack* s) { s->top = -1; }

int isFull(struct Stack* s) { return s->top == MAX - 1; }

int isEmpty(struct Stack* s) { return s->top == -1; }

void push(struct Stack* s, int val) {
    if (isFull(s)) { printf("Stack Overflow!\n"); return; }
    s->arr[++(s->top)] = val;
    printf("Pushed %d\n", val);
}

int pop(struct Stack* s) {
    if (isEmpty(s)) { printf("Stack Underflow!\n"); return -1; }
    return s->arr[(s->top)--];
}

int peek(struct Stack* s) {
    if (isEmpty(s)) { printf("Stack is empty!\n"); return -1; }
    return s->arr[s->top];
}

void display(struct Stack* s) {
    if (isEmpty(s)) { printf("Stack is empty!\n"); return; }
    printf("Stack (top to bottom): ");
    for (int i = s->top; i >= 0; i--)
        printf("%d ", s->arr[i]);
    printf("\n");
}

int main() {
    struct Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 25);
    push(&s, 37);
    push(&s, 48);
    display(&s);

    printf("Top element: %d\n", peek(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    display(&s);

    return 0;
}
