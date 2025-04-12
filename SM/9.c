#include <math.h>
#include <stdio.h>

#define NUM_CATEGORIES 5

double chi_square(double observed[], double expected[], int n) {
  double chi_square_stat = 0.0;

  for (int i = 0; i < n; i++) {
    chi_square_stat += pow(observed[i] - expected[i], 2) / expected[i];
  }

  return chi_square_stat;
}

int main() {

  double observed[NUM_CATEGORIES] = {15, 18, 12, 20, 25};

  double expected[NUM_CATEGORIES] = {18, 18, 18, 18, 18};

  double chi_square_stat = chi_square(observed, expected, NUM_CATEGORIES);

  printf("Chi-Square Statistic: %f\n", chi_square_stat);

  int degrees_of_freedom = NUM_CATEGORIES - 1;

  double critical_value = 9.488;

  printf("Degrees of Freedom: %d\n", degrees_of_freedom);
  printf("Critical Value (from Chi-Square distribution table): %f\n",
         critical_value);

  if (chi_square_stat > critical_value) {
    printf("Reject the null hypothesis: The data does not fit the expected "
           "distribution.\n");
  } else {
    printf("Fail to reject the null hypothesis: The data fits the expected "
           "distribution.\n");
  }

  return 0;
}
