// Lab 9: program for Dijkstra's single source shortest path

#include <limits.h>
#include <stdio.h>

#define INF INT_MAX

int min_distance(int dist[], int spt_set[], int n) {
  int min = INF, min_index;
  for (int v = 0; v < n; v++) {
    if (spt_set[v] == 0 && dist[v] <= min) {
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

int main() {
  int n, source, step = 0;
  printf("Enter number of vertices: ");
  scanf("%d", &n);

  int graph[n][n], dist[n], spt_set[n];

  printf("Enter the adjacency matrix (use a large number for infinity):\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &graph[i][j]);

  printf("Enter the source vertex (0-based index): ");
  scanf("%d", &source);

  for (int i = 0; i < n; i++) {
    dist[i] = INF;
    spt_set[i] = 0;
  }
  dist[source] = 0;

  for (int count = 0; count < n - 1; count++) {
    int u = min_distance(dist, spt_set, n);
    spt_set[u] = 1;

    for (int v = 0; v < n; v++) {
      step++;
      if (!spt_set[v] && graph[u][v] != INF && dist[u] != INF &&
          dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }

  printf("Shortest distances from source vertex %d:\n", source);
  for (int i = 0; i < n; i++) {
    if (dist[i] == INF)
      printf("Vertex %d: INF\n", i);
    else
      printf("Vertex %d: %d\n", i, dist[i]);
  }

  printf("Steps: %d\n", step);
  return 0;
}
