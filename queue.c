// Queue Implementation using Array in C
#include <stdio.h>
#define MAX 100

struct Queue {
    int arr[MAX];
    int front, rear, size;
};

void initQueue(struct Queue* q) { q->front = 0; q->rear = -1; q->size = 0; }

int isFull(struct Queue* q) { return q->size == MAX; }

int isEmpty(struct Queue* q) { return q->size == 0; }

void enqueue(struct Queue* q, int val) {
    if (isFull(q)) { printf("Queue is full!\n"); return; }
    q->rear = (q->rear + 1) % MAX;
    q->arr[q->rear] = val;
    q->size++;
    printf("Enqueued: %d\n", val);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); return -1; }
    int val = q->arr[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return val;
}

int frontVal(struct Queue* q) {
    if (isEmpty(q)) return -1;
    return q->arr[q->front];
}

void display(struct Queue* q) {
    if (isEmpty(q)) { printf("Queue is empty!\n"); return; }
    printf("Queue (front to rear): ");
    for (int i = 0; i < q->size; i++)
        printf("%d ", q->arr[(q->front + i) % MAX]);
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    display(&q);

    printf("Front: %d\n", frontVal(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    return 0;
}
