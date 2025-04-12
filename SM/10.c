#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SEQUENCE_LENGTH 100
#define TEST_VALUE 1

void generate_random_sequence(int sequence[], int length) {
  for (int i = 0; i < length; i++) {
    sequence[i] = rand() % 2;
  }
}

void gap_test(int sequence[], int length, int test_value) {
  int gap_count = 0;
  int current_gap = 0;
  int total_gaps = 0;
  int gap_frequencies[SEQUENCE_LENGTH] = {0};

  for (int i = 0; i < length; i++) {
    if (sequence[i] == test_value) {
      if (current_gap > 0) {
        gap_frequencies[current_gap]++;

        total_gaps++;
      }
      current_gap = 0;
    } else {
      current_gap++;
    }
  }

  printf("Gap Distribution (Gap length: Frequency):\n");
  for (int i = 1; i <= SEQUENCE_LENGTH; i++) {
    if (gap_frequencies[i] > 0) {
      printf("Gap length %d: %d occurrences\n", i, gap_frequencies[i]);
    }
  }

  printf("\nTotal Gaps Found: %d\n", total_gaps);
}

int main() {
  srand(time(NULL));

  int sequence[SEQUENCE_LENGTH];
  generate_random_sequence(sequence, SEQUENCE_LENGTH);

  printf("Generated Random Sequence:\n");
  for (int i = 0; i < SEQUENCE_LENGTH; i++) {
    printf("%d ", sequence[i]);
    if (i > 0 && i % 5 == 0)
      putchar('\n');
  }
  printf("\n\n");

  gap_test(sequence, SEQUENCE_LENGTH, TEST_VALUE);

  return 0;
}
