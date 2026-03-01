#include "my_barrier.h"

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void mutex_error() {
  fprintf(stderr,
          "Thread %lu: Could not lock/unlock "
          "barrier mutex, exiting.\n",
          thrd_current());
  exit(1);
}

void cond_error() {
  fprintf(stderr,
          "Thread %lu: Could not wait/signal/broadcast "
          "barrier condition variable, exiting.\n",
          thrd_current());
}

void init_barrier(my_barrier_t *barrier, int mutex_type,
                  size_t barrier_count) {
  mtx_init(&barrier->mutex, mutex_type);
  cnd_init(&barrier->condition);
  barrier->barrier_count = barrier_count;
  barrier->total_threads = 0;
}

void destroy_barrier(my_barrier_t *barrier) {
  mtx_destroy(&barrier->mutex);
  cnd_init(&barrier->condition);
}

void wait_on_barrier(my_barrier_t *barrier) {
  if (mtx_lock(&barrier->mutex) != thrd_success)
    mutex_error();

  // New thread entered
  ++barrier->total_threads;

  while (barrier->total_threads < barrier->barrier_count) {
    printf("Thread %lu: Barrier locked, %zu threads waiting.\n", thrd_current(),
           barrier->total_threads + 1);

    if (cnd_wait(&barrier->condition, &barrier->mutex) != thrd_success)
      cond_error();
  }

  if (cnd_broadcast(&barrier->condition) != thrd_success)
    mutex_error();

  // Unlock mutext to allow others to wake up
  if (mtx_unlock(&barrier->mutex) != thrd_success)
    mutex_error();

  printf("Thread %lu: Barrier broken, continuing...\n", thrd_current());
}
