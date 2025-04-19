// Lab2 : Implementation of Merge Sort :
// Source Code :

#include <stdio.h>

int step_count = 0;

void merge(int a[], int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (int i = 0; i < n2; i++)
    R[i] = a[m + 1 + i];
  int i = 0, j = 0, k = l;
  while (i < n1 && j < n2) {
    step_count++;
    if (L[i] <= R[j])
      a[k++] = L[i++];
    else
      a[k++] = R[j++];
  }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}

void merge_sort(int a[], int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    merge(a, l, m, r);
  }
}

int main() {
  int a[] = {64, 25, 12, 22, 11};
  int n = sizeof(a) / sizeof(a[0]);

  printf("Before: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  putchar('\n');

  merge_sort(a, 0, n - 1);

  printf("After: ");
  for (int i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\nSteps: %d\n", step_count);

  return 0;
}
