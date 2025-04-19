// Lab 1 : Implementation of Bubble , Selection and Insertion Sort :  Selection

// sort Source Code :

#include <stdio.h>

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]), step_count = 0;

  printf("Before: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  putchar('\n');
  for (int i = 0; i < n; i++) {
    int swapped = 0;
    for (int j = 0; j < n - i - 1; j++) {
      step_count++;
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
      }
    }
    if (!swapped)
      break;
  }

  printf("After:");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\nSteps: %d\n", step_count);

  return 0;
}
