// Lab 14 : implementation of Subset sum problem

#include <stdio.h>

#define MAX 20

int count = 0;

void findSubsetSum(int set[], int n, int target, int index, int current[],
                   int current_size) {
  if (index == n) {
    int sum = 0;
    for (int i = 0; i < current_size; i++) {
      sum += current[i];
    }
    if (sum == target) {
      count++;
      printf("Subset %d: {", count);
      for (int i = 0; i < current_size; i++) {
        printf("%d", current[i]);
        if (i < current_size - 1)
          printf(", ");
      }
      printf("}\n");
    }
    return;
  }

  current[current_size] = set[index];
  findSubsetSum(set, n, target, index + 1, current, current_size + 1);

  findSubsetSum(set, n, target, index + 1, current, current_size);
}

int main() {
  int set[MAX], n, target, current[MAX];

  printf("Enter the number of elements in the set: ");
  scanf("%d", &n);

  printf("Enter the elements of the set:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &set[i]);
  }

  printf("Enter the target sum: ");
  scanf("%d", &target);

  printf("Subsets that sum to %d:\n", target);
  findSubsetSum(set, n, target, 0, current, 0);

  printf("Total subsets found: %d\n", count);

  return 0;
}
