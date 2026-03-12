#include <math.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

struct {
  float *vector;
  size_t length;
  float k;
} g_thread_input;

atomic_uint g_add_index;

void fprint_float_vec(FILE *out_stream, float vector[], size_t length) {
  fprintf(out_stream, "[");

  if (length == 0) {
    fprintf(out_stream, "]");
    return;
  }

  --length;

  for (size_t i = 0; i < length; ++i)
    fprintf(out_stream, "%f, ", vector[i]);

  fprintf(out_stream, "%f]", vector[length]);
}

int thrd_exp_and_add(void *arg) {
  size_t *index = (size_t *)arg;

  // Exponentiate
  g_thread_input.vector[*index] =
      powf(g_thread_input.vector[*index], g_thread_input.k);

  // Add
  // Await turn
  while (atomic_load(&g_add_index) != *index) {
    // Busy wait
  }

  if (*index != 0)
    // Sum with previous
    g_thread_input.vector[*index] += g_thread_input.vector[*index - 1];

  atomic_store(&g_add_index, atomic_load(&g_add_index) + 1);
  return 0;
}

void solve() {
  // Initialization
  thrd_t *threads = (thrd_t *)malloc(sizeof(thrd_t) * g_thread_input.length);
  size_t *input_indices =
      (size_t *)malloc(sizeof(size_t) * g_thread_input.length);
  atomic_init(&g_add_index, 0);

  for (size_t i = 0; i < g_thread_input.length; ++i) {
    input_indices[i] = i;
    if (thrd_create(&threads[i], thrd_exp_and_add, &input_indices[i]) !=
        thrd_success) {
      fprintf(stderr, "Error in creating thread %zu, exiting...", i);
      exit(EXIT_FAILURE);
    }
  }

  for (size_t i = 0; i < g_thread_input.length; ++i)
    if (thrd_join(threads[i], NULL) != thrd_success) {
      fprintf(stderr, "Error in joining thread %zu, exiting...", i);
      exit(EXIT_FAILURE);
    }

  free(input_indices);
  free(threads);
}

int main() {
  printf("Input vector size: ");
  scanf("%zu", &g_thread_input.length);

  g_thread_input.vector =
      (float *)malloc(sizeof(float) * g_thread_input.length);

  for (size_t i = 0; i < g_thread_input.length; ++i) {
    printf("Input element [%zu]: ", i);
    scanf("%f", &g_thread_input.vector[i]);
  }

  printf("Input k (power): ");
  scanf("%f", &g_thread_input.k);

  printf("\nInput vector:\n");
  fprint_float_vec(stdout, g_thread_input.vector, g_thread_input.length);

  printf("\n\nCalculating result...\n");
  solve();
  printf("Output vector:\n");
  fprint_float_vec(stdout, g_thread_input.vector, g_thread_input.length);
  printf("\n");

  free(g_thread_input.vector);
}
