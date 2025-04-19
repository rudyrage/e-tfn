// Lab 8: Program for Floyd Warshall Algorithm Source Code :

#include <stdio.h>

int main() {
  int n, step = 0;
  printf("Enter number of vertices: ");
  scanf("%d", &n);
  int dist[n][n];

  printf("Enter the adjacency matrix (use a large number for infinity):\n");
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      scanf("%d", &dist[i][j]);

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        step++;
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }

  printf("Shortest paths matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      printf("%4d ", dist[i][j]);
    putchar('\n');
  }

  printf("Steps: %d\n", step);
  return 0;
}
