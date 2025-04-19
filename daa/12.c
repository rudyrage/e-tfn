// Lab12 : Kruskal's algorithm to find Minimum Spanning Tree of a given
// connected, undirected graph

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
  int u, v, weight;
} Edge;

int parent[MAX], rank[MAX];

int find(int i) {
  if (parent[i] != i)
    parent[i] = find(parent[i]);
  return parent[i];
}

void union_set(int u, int v) {
  int root_u = find(u);
  int root_v = find(v);

  if (root_u != root_v) {

    if (rank[root_u] > rank[root_v]) {
      parent[root_v] = root_u;
    } else if (rank[root_u] < rank[root_v]) {
      parent[root_u] = root_v;
    } else {
      parent[root_v] = root_u;
      rank[root_u]++;
    }
  }
}

int compare(const void *a, const void *b) {
  return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int main() {
  int n, m, total_weight = 0, steps = 0;

  printf("Enter the number of vertices and edges: ");
  scanf("%d %d", &n, &m);

  Edge edges[m];

  for (int i = 0; i < n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  printf("Enter the edges (u v weight):\n");
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
  }

  qsort(edges, m, sizeof(Edge), compare);

  printf("Minimum Spanning Tree (MST) edges:\n");
  for (int i = 0; i < m; i++) {
    steps++;
    int u = edges[i].u;
    int v = edges[i].v;
    int weight = edges[i].weight;

    if (find(u) != find(v)) {
      union_set(u, v);
      total_weight += weight;
      printf("%d - %d: %d\n", u, v, weight);
    }
  }

  printf("Total weight of MST: %d\n", total_weight);
  printf("Steps: %d\n", steps);

  return 0;
}
