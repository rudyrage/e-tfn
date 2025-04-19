// Lab 11: program to solve N Queen Problem using backtracking

#include <stdio.h>

int step = 0;

int is_safe(int board[][10], int row, int col, int n) {
  for (int i = 0; i < row; i++) {
    if (board[i][col] == 1)
      return 0;
    if (col - (row - i) >= 0 && board[i][col - (row - i)] == 1)
      return 0;
    if (col + (row - i) < n && board[i][col + (row - i)] == 1)
      return 0;
  }
  return 1;
}

int solve_nqueens(int board[][10], int row, int n) {
  step++;
  if (row == n)
    return 1;

  for (int col = 0; col < n; col++) {
    if (is_safe(board, row, col, n)) {
      board[row][col] = 1;
      if (solve_nqueens(board, row + 1, n))
        return 1;
      board[row][col] = 0;
    }
  }
  return 0;
}

int main() {
  int n;
  printf("Enter the value of N: ");
  scanf("%d", &n);

  int board[10][10] = {0};

  if (solve_nqueens(board, 0, n)) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        printf("%d ", board[i][j]);
      }
      printf("\n");
    }
    printf("Steps: %d\n", step);
  } else {
    printf("No solution exists\n");
  }

  return 0;
}
