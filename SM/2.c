#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CUSTOMERS 100

typedef struct {
  int arrival_time;
  int service_time;
  int waiting_time;
  int response_time;
} Customer;

void simulate_queue(int num_customers, Customer queue[]) {
  int total_waiting_time = 0;
  int total_response_time = 0;
  int total_service_time = 0;
  int server_busy_time = 0;

  int current_time = 0;

  for (int i = 0; i < num_customers; i++) {

    if (queue[i].arrival_time > current_time) {
      current_time = queue[i].arrival_time;
    }
    queue[i].waiting_time = current_time - queue[i].arrival_time;

    queue[i].response_time = queue[i].waiting_time + queue[i].service_time;

    total_waiting_time += queue[i].waiting_time;
    total_response_time += queue[i].response_time;
    total_service_time += queue[i].service_time;

    server_busy_time += queue[i].service_time;

    current_time += queue[i].service_time;
  }

  double average_waiting_time = (double)total_waiting_time / num_customers;
  double average_response_time = (double)total_response_time / num_customers;

  double server_utilization = (double)server_busy_time / current_time * 100;

  printf("Average Waiting Time: %.2f\n", average_waiting_time);
  printf("Average Response Time: %.2f\n", average_response_time);
  printf("Server Utilization: %.2f%%\n", server_utilization);
}

int main() {
  srand(time(NULL));

  int num_customers = 10;
  Customer queue[MAX_CUSTOMERS];

  for (int i = 0; i < num_customers; i++) {
    queue[i].arrival_time = rand() % 50;
    queue[i].service_time = rand() % 10 + 1;
  }

  for (int i = 0; i < num_customers - 1; i++) {
    for (int j = i + 1; j < num_customers; j++) {
      if (queue[i].arrival_time > queue[j].arrival_time) {

        Customer temp = queue[i];
        queue[i] = queue[j];
        queue[j] = temp;
      }
    }
  }

  simulate_queue(num_customers, queue);

  return 0;
}
