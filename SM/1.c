#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_POINTS 1000000

double monte_carlo_pi() {
  int inside_circle = 0;

  for (int i = 0; i < NUM_POINTS; i++) {
    double x = (double)rand() / RAND_MAX;
    double y = (double)rand() / RAND_MAX;

    if (x * x + y * y <= 1.0) {
      inside_circle++;
    }
  }

  return 4.0 * inside_circle / NUM_POINTS;
}

int main() {

  srand(time(NULL));

  double estimated_pi = monte_carlo_pi();

  printf("Monte Carlo estimate of Pi: %f\n", estimated_pi);

  return 0;
}
