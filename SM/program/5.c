#include <stdio.h>

unsigned long multiplicative_congruential(unsigned long seed, unsigned long a,
                                          unsigned long m) {
  return (a * seed) % m;
}

int main() {
  unsigned long seed = 12345;
  unsigned long a = 1664525;
  unsigned long m = 4294967296;
  unsigned int num_random_numbers = 10;

  unsigned long random_number = seed;

  printf("Generated random numbers using Multiplicative Congruential "
         "Generator:\n");
  for (unsigned int i = 0; i < num_random_numbers; i++) {
    random_number = multiplicative_congruential(random_number, a, m);
    printf("%lu\n", random_number);
  }

  return 0;
}
