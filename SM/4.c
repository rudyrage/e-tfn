#include <stdio.h>

#define MODULUS 2147483647
#define MULTIPLIER 1103515245
#define INCREMENT 12345
#define SEED 987654321

int generate_random_number(int *seed) {
  *seed = (*seed * MULTIPLIER + INCREMENT) % MODULUS;
  return *seed;
}

int main() {
  int seed = SEED;

  int num_random_numbers = 10;

  printf("Generating %d random numbers using the Linear Congruential Method:\n",
         num_random_numbers);

  for (int i = 0; i < num_random_numbers; i++) {
    int random_number = generate_random_number(&seed);
    printf("Random Number %d: %d\n", i + 1, random_number);
  }

  return 0;
}
