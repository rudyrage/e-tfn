// Lab3 : Implementation of Quick Sort :

#include <stdio.h>

int step_count = 0;

int partition(int a[], int low, int high) {
  int p = a[high], i = low - 1;
  for (int j = low; j < high; j++) {
    step_count++;
    if (a[j] < p) {
      int t = a[++i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  int t = a[i + 1];
  a[i + 1] = a[high];
  a[high] = t;
  return i + 1;
}

void quick_sort(int a[], int low, int high) {
  if (low < high) {
    int pi = partition(a, low, high);
    quick_sort(a, low, pi - 1);
    quick_sort(a, pi + 1, high);
  }
}

int main() {
  int a[] = {64, 25, 12, 22, 11};
  int n = sizeof(a) / sizeof(a[0]);

  printf("Before: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  putchar('\n');

  quick_sort(a, 0, n - 1);

  printf("After: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\nSteps: %d\n", step_count);

  return 0;
}
