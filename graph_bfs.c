// Graph Breadth First Search (BFS) in C
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = -1, qSize = 0;

void enqueue(int v) { queue[++rear] = v; qSize++; }
int dequeue() { qSize--; return queue[front++]; }
int isQueueEmpty() { return qSize == 0; }

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1; // undirected
}

void bfs(int start, int n) {
    visited[start] = 1;
    enqueue(start);
    printf("BFS traversal: ");

    while (!isQueueEmpty()) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adj[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int n = 6;
    addEdge(0, 1); addEdge(0, 2);
    addEdge(1, 3); addEdge(1, 4);
    addEdge(2, 5);

    printf("Graph has %d vertices\n", n);
    bfs(0, n);

    return 0;
}
