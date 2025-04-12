#include <math.h>
#include <stdio.h>

#define SAMPLE_SIZE 10

double ks_test(double sample[], int n) {

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (sample[i] > sample[j]) {
        double temp = sample[i];
        sample[i] = sample[j];
        sample[j] = temp;
      }
    }
  }

  double d_plus = 0.0;
  double d_minus = 0.0;

  for (int i = 0; i < n; i++) {

    double ecdf_sample = (i + 1) / (double)n;
    double cdf_uniform = sample[i];

    d_plus = fmax(d_plus, ecdf_sample - cdf_uniform);
    d_minus = fmax(d_minus, cdf_uniform - (i / (double)n));
  }

  double ks_statistic = fmax(d_plus, d_minus);

  return ks_statistic;
}

int main() {

  double sample[SAMPLE_SIZE] = {0.1, 0.4, 0.35, 0.8, 0.95,
                                0.5, 0.7, 0.2,  0.6, 0.9};

  double ks_statistic = ks_test(sample, SAMPLE_SIZE);

  printf("KS Statistic: %f\n", ks_statistic);

  double critical_value = 1.36 / sqrt(SAMPLE_SIZE);

  if (ks_statistic > critical_value) {
    printf("The sample does not follow the uniform distribution.\n");
  } else {
    printf("The sample follows the uniform distribution.\n");
  }

  return 0;
}
