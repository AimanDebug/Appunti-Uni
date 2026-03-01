#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>

#define N 5

struct {
  int *vector;
  int length;
  int norm;
} g_result;

typedef struct {
  int index;
  int i;
} thrd_input;

atomic_int acc = 0;

int thrd_func(void *arg) {
  thrd_input *input = (thrd_input *)arg;
  g_result.vector[input->index] = pow(g_result.vector[input->index], input->i);
  atomic_fetch_add(&acc, g_result.vector[input->index]);
  return 0;
}

int main() {
  printf("Input vector length: ");
  scanf("%d", &g_result.length);

  g_result.vector = (int *)malloc(sizeof(int) * g_result.length);

  printf("Input i power: ");
  int i_power;
  scanf("%d", &i_power);

  for (size_t i = 0; i < g_result.length; ++i) {
    printf("Input element %zu: ", i);
    scanf("%d", &g_result.vector[i]);
  }

  printf("\n");

  thrd_t *threads = (thrd_t *)malloc(sizeof(thrd_t) * g_result.length);
  thrd_input *inputs =
      (thrd_input *)malloc(sizeof(thrd_input) * g_result.length);

  // Calculate norm for each component
  for (size_t i = 0; i < g_result.length; ++i) {
    inputs[i] = (thrd_input){.i = i_power, .index = i};
    thrd_create(&threads[i], thrd_func, (void *)&inputs[i]);
  }

  // Wait for them to finish
  for (size_t i = 0; i < g_result.length; ++i)
    thrd_join(threads[i], NULL);

  g_result.norm = pow(acc, 1/(double)i_power);
  printf("Norm: %d\n", g_result.norm);

  free(g_result.vector);
  free(threads);
  free(inputs);
}
