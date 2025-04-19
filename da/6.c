// Lab 6: implementation Of Matrix chain Multiplication Problem Source Code :

#include <stdio.h>

int main() {
  int n, step = 0;
  printf("Enter number of matrices: ");
  scanf("%d", &n);
  int d[n + 1];
  printf("Enter dimensions: ");
  for (int i = 0; i <= n; i++)
    scanf("%d", &d[i]);

  int m[n][n];
  for (int i = 0; i < n; i++)
    m[i][i] = 0;

  for (int L = 2; L <= n; L++) {
    for (int i = 0; i <= n - L; i++) {
      int j = i + L - 1;
      m[i][j] = 1e9;
      for (int k = i; k < j; k++) {
        step++;
        int cost = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
        if (cost < m[i][j])
          m[i][j] = cost;
      }
    }
  }

  printf("Table:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      if (j < i)
        printf(" - ");
      else
        printf("%3d ", m[i][j]);
    putchar('\n');
  }

  printf("Min Multiplications: %d\n", m[0][n - 1]);
  printf("Steps: %d\n", step);
  return 0;
}
