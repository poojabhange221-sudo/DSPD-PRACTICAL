//Consider the undirected graph G, consisting of n nodes laid out in a 3 -by- 3 grid: Start searching at node 1, and break ties for exploring the next node based on lower numerical order (i.e. add nodes to a queue low to high, add nodes to a stack high to low). (a) In what order are nodes marked as explored by BFS? (b) In what order are nodes marked as explored by DFS? program in c
#include <stdio.h>
#include <stdlib.h>
#define MAX 9
int adj[MAX + 1][MAX + 1];
int visited[MAX + 1];
void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}
void BFS(int start) {
    int queue[MAX + 1], front = 0, rear = 0;
    for (int i = 1; i <= MAX; i++) visited[i] = 0;
    queue[rear++] = start;
    visited[start] = 1;
    printf("BFS Order: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);
        for (int i = 1; i <= MAX; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void DFS(int start) {
    int stack[MAX + 1], top = -1;
    for (int i = 1; i <= MAX; i++) visited[i] = 0;
    stack[++top] = start;
    printf("DFS Order: ");
    while (top >= 0) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);
            for (int i = MAX; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}

int main() {
    addEdge(1, 2); addEdge(1, 4);
    addEdge(2, 3); addEdge(2, 5);
    addEdge(3, 6);
    addEdge(4, 5); addEdge(4, 7);
    addEdge(5, 6); addEdge(5, 8);
    addEdge(6, 9);
    addEdge(7, 8);
    addEdge(8, 9);
    BFS(1);
    DFS(1);
    return 0;
}
