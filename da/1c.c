// BubbleSort :
// Source Code :

#include <stdio.h>

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]), step_count = 0;

  printf("Before: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  putchar('\n');
  for (int i = 1; i < n; i++) {
    int key = arr[i], j = i - 1;
    while (j >= 0 && arr[j] > key) {
      step_count++;
      arr[j + 1] = arr[j];
      j--;
    }
    if (j >= 0)
      step_count++;
    arr[j + 1] = key;
  }

  printf("After: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\nSteps: %d\n", step_count);

  return 0;
}
