// Lab4 : Implementation of  Randomized Quick Sort

#include <stdio.h>
#include <stdlib.h>

int step_count = 0;

int partition(int a[], int l, int h) {
  int p = a[h], i = l - 1;
  for (int j = l; j < h; j++) {
    step_count++;
    if (a[j] < p) {
      int t = a[++i];
      a[i] = a[j];
      a[j] = t;
    }
  }
  int t = a[i + 1];
  a[i + 1] = a[h];
  a[h] = t;
  return i + 1;
}

int rand_partition(int a[], int l, int h) {
  int r = l + rand() % (h - l + 1);
  int t = a[r];
  a[r] = a[h];
  a[h] = t;
  return partition(a, l, h);
}

void quick_sort(int a[], int l, int h) {
  if (l < h) {
    int pi = rand_partition(a, l, h);
    quick_sort(a, l, pi - 1);
    quick_sort(a, pi + 1, h);
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
