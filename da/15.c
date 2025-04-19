// Lab 15: implementation of job sequence in deadlines

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
  int id;
  int deadline;
  int profit;
} Job;

int compare(const void *a, const void *b) {
  return ((Job *)b)->profit - ((Job *)a)->profit;
}

void jobSequencing(Job jobs[], int n) {
  int result[MAX];
  int slot[MAX];
  int totalProfit = 0, count = 0;

  for (int i = 0; i < n; i++) {
    slot[i] = -1;
  }

  qsort(jobs, n, sizeof(Job), compare);

  for (int i = 0; i < n; i++) {

    for (int j = jobs[i].deadline - 1; j >= 0; j--) {
      if (slot[j] == -1) {
        slot[j] = i;
        totalProfit += jobs[i].profit;
        count++;
        break;
      }
    }
  }

  printf("Job Sequence that maximizes profit:\n");
  for (int i = 0; i < n; i++) {
    if (slot[i] != -1) {
      printf("Job %d with profit %d, Deadline %d\n", jobs[slot[i]].id,
             jobs[slot[i]].profit, jobs[slot[i]].deadline);
    }
  }
  printf("Total Profit: %d\n", totalProfit);
  printf("Total Jobs Scheduled: %d\n", count);
}

int main() {
  int n;

  printf("Enter the number of jobs: ");
  scanf("%d", &n);

  Job jobs[n];

  printf("Enter job details (ID, Deadline, Profit):\n");
  for (int i = 0; i < n; i++) {
    jobs[i].id = i + 1;
    scanf("%d %d", &jobs[i].deadline, &jobs[i].profit);
  }

  jobSequencing(jobs, n);

  return 0;
}
