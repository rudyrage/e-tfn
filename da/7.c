// Lab 7 : Implementation of Dynamic Programming based C++ program to find
// minimum number operations to convert str1 to str2

#include <stdio.h>
#include <string.h>

int min(int a, int b, int c) {
  return a < b ? (a < c ? a : c) : (b < c ? b : c);
}

int main() {
  char str1[100], str2[100];
  printf("Enter first string: ");
  scanf("%s", str1);
  printf("Enter second string: ");
  scanf("%s", str2);

  int m = strlen(str1), n = strlen(str2);
  int dp[m + 1][n + 1];

  for (int i = 0; i <= m; i++)
    dp[i][0] = i;
  for (int j = 0; j <= n; j++)
    dp[0][j] = j;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
    }
  }

  printf("Minimum operations: %d\n", dp[m][n]);
  return 0;
}
