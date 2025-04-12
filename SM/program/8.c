#include <stdio.h>

#define N 10

double mean(double data[], int n) {
  double sum = 0.0;
  for (int i = 0; i < n; i++) {
    sum += data[i];
  }
  return sum / n;
}

double autocorrelation(double data[], int n, int lag) {
  double mu = mean(data, n);
  double numerator = 0.0;
  double denominator = 0.0;

  for (int i = 0; i < n - lag; i++) {
    numerator += (data[i] - mu) * (data[i + lag] - mu);
  }

  for (int i = 0; i < n; i++) {
    denominator += (data[i] - mu) * (data[i] - mu);
  }

  return numerator / denominator;
}

int main() {

  double data[N] = {0.1, 0.2, 0.4, 0.5, 0.7, 0.6, 0.9, 0.8, 0.7, 0.9};

  for (int lag = 1; lag <= 5; lag++) {
    double acf = autocorrelation(data, N, lag);
    printf("Autocorrelation at lag %d: %f\n", lag, acf);
  }

  return 0;
}
