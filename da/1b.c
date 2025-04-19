// Insertion Sort :
// Source Code :

#include <stdio.h>

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]), step_count = 0;

  printf("Before: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  putchar('\n');
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      step_count++;
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i) {
      int t = arr[i];
      arr[i] = arr[min];
      arr[min] = t;
    }
  }

  printf("After:");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\nSteps: %d\n", step_count);

  return 0;
}
