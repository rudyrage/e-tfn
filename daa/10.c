// Lab 10 : Program to solve fractional Knapsack Problem Source Code :

#include <stdio.h>

typedef struct {
  int weight;
  int value;
  float ratio;
} Item;

int main() {
  int n, capacity, step = 0;
  printf("Enter number of items and capacity of knapsack: ");
  scanf("%d %d", &n, &capacity);

  Item items[n];
  for (int i = 0; i < n; i++) {
    printf("Enter weight and value for item %d: ", i + 1);
    scanf("%d %d", &items[i].weight, &items[i].value);
    items[i].ratio = (float)items[i].value / items[i].weight;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      step++;
      if (items[i].ratio < items[j].ratio) {
        Item temp = items[i];
        items[i] = items[j];
        items[j] = temp;
      }
    }
  }

  int totalValue = 0;
  float totalWeight = 0.0;

  for (int i = 0; i < n; i++) {
    if (totalWeight + items[i].weight <= capacity) {
      totalWeight += items[i].weight;
      totalValue += items[i].value;
    } else {
      int remainingWeight = capacity - totalWeight;
      totalValue += items[i].value * ((float)remainingWeight / items[i].weight);
      break;
    }
  }

  printf("Maximum value in Knapsack = %d\n", totalValue);
  printf("Steps: %d\n", step);
  return 0;
}
