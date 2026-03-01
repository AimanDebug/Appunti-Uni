#include <threads.h>
#include <stdio.h>

#include "my_barrier.h"

my_barrier_t barrier;

int thread_func(void* arg) {
    wait_on_barrier(&barrier);
    return 0;
}

#define N 5

int main() {
    thrd_t threads[N];
    init_barrier(&barrier, mtx_plain, N);

    for (size_t i = 0; i < N; ++i)
        thrd_create(&threads[i], thread_func, NULL);

    for (size_t i = 0; i < N; ++i)
        thrd_join(threads[i], NULL);

    destroy_barrier(&barrier);
}
