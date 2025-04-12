#include <math.h>
#include <stdio.h>

#define SEED 1234
#define NUM_DIGITS 4

int generate_random_number(int seed) {
  long long squared = (long long)seed * seed;
  int num_digits = (int)log10(squared) + 1;

  int start_pos = (num_digits - NUM_DIGITS) / 2;

  int divisor = pow(10, num_digits - NUM_DIGITS);
  int middle_digits = (squared / divisor) % (int)pow(10, NUM_DIGITS);

  return middle_digits;
}

int main() {
  int seed = SEED;
  int num_random_numbers = 10;

  printf("Generating %d random numbers using the Mid-Square Method:\n",
         num_random_numbers);

  for (int i = 0; i < num_random_numbers; i++) {
    seed = generate_random_number(seed);
    printf("Random Number %d: %d\n", i + 1, seed);
  }

  return 0;
}
