// Graph Depth First Search (DFS) in C
#include <stdio.h>
#define MAX 100

int adj[MAX][MAX];
int visited[MAX];

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i])
            dfs(i, n);
    }
}

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
    int n = 7;
    addEdge(0, 1); addEdge(0, 2);
    addEdge(1, 3); addEdge(1, 4);
    addEdge(2, 5); addEdge(2, 6);

    printf("DFS traversal from vertex 0: ");
    dfs(0, n);
    printf("\n");

    // Reset and DFS from different starting vertex
    for (int i = 0; i < MAX; i++) visited[i] = 0;
    printf("DFS traversal from vertex 3: ");
    dfs(3, n);
    printf("\n");

    return 0;
}
