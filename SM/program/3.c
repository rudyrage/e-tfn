#include <stdio.h>

#define NUM_STATES 3

void multiply_matrices(double matrix1[NUM_STATES][NUM_STATES],
                       double matrix2[NUM_STATES], double result[NUM_STATES]) {
  for (int i = 0; i < NUM_STATES; i++) {
    result[i] = 0;
    for (int j = 0; j < NUM_STATES; j++) {
      result[i] += matrix1[i][j] * matrix2[j];
    }
  }
}

void print_state_probabilities(double state_probabilities[NUM_STATES],
                               int step) {
  printf("Step %d:\n", step);
  for (int i = 0; i < NUM_STATES; i++) {
    printf("State S%d Probability: %.4f\n", i, state_probabilities[i]);
  }
  printf("\n");
}

int main() {

  double transition_matrix[NUM_STATES][NUM_STATES] = {
      {0.6, 0.3, 0.1}, {0.2, 0.5, 0.3}, {0.3, 0.4, 0.3}};

  double state_probabilities[NUM_STATES] = {1.0, 0.0, 0.0};

  double result[NUM_STATES];

  int num_steps = 10;

  print_state_probabilities(state_probabilities, 0);

  for (int step = 1; step <= num_steps; step++) {

    multiply_matrices(transition_matrix, state_probabilities, result);

    for (int i = 0; i < NUM_STATES; i++) {
      state_probabilities[i] = result[i];
    }

    print_state_probabilities(state_probabilities, step);
  }

  return 0;
}
