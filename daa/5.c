// Lab5 : implementation of 0/1 Knapsack problem using Dynamic approach

#include <stdio.h>

int max(int a, int b) { return a > b ? a : b; }

int main() {
  int n, cap;
  printf("Enter number of items and capacity: ");
  scanf("%d %d", &n, &cap);
  int w[n], p[n], dp[n + 1][cap + 1];

  printf("Enter weights: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &w[i]);
  printf("Enter profits: ");
  for (int i = 0; i < n; i++)
    scanf("%d", &p[i]);

  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= cap; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (w[i - 1] <= j)
        dp[i][j] = max(p[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
      else
        dp[i][j] = dp[i - 1][j];
    }

  printf("Table:\n");
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= cap; j++)
      printf("%2d ", dp[i][j]);
    putchar('\n');
  }

  printf("Max Profit: %d\n", dp[n][cap]);
  return 0;
}
