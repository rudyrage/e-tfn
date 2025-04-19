// Lab 13 :program for Prim's Minimum

#include <limits.h>
#include <stdio.h>

#define MAX 10

int minKey(int key[], int mstSet[], int n) {
  int min = INT_MAX, minIndex;
  for (int v = 0; v < n; v++) {
    if (mstSet[v] == 0 && key[v] < min) {
      min = key[v];
      minIndex = v;
    }
  }
  return minIndex;
}

void primMST(int graph[MAX][MAX], int n) {
  int parent[n];
  int key[n];
  int mstSet[n];
  int totalWeight = 0, steps = 0;

  for (int i = 0; i < n; i++) {
    key[i] = INT_MAX;
    mstSet[i] = 0;
  }

  key[0] = 0;
  parent[0] = -1;

  for (int count = 0; count < n - 1; count++) {
    int u = minKey(key, mstSet, n);
    mstSet[u] = 1;
    steps++;

    for (int v = 0; v < n; v++) {
      if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
        key[v] = graph[u][v];
        parent[v] = u;
      }
    }
  }

  printf("Minimum Spanning Tree (MST) edges:\n");
  for (int i = 1; i < n; i++) {
    printf("%d - %d: %d\n", parent[i], i, graph[i][parent[i]]);
    totalWeight += graph[i][parent[i]];
  }

  printf("Total weight of MST: %d\n", totalWeight);
  printf("Steps: %d\n", steps);
}

int main() {
  int n;

  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  int graph[MAX][MAX];
  printf("Enter the adjacency matrix of the graph:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  primMST(graph, n);

  return 0;
}
