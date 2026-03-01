#include <stdio.h>
#include <threads.h>

#define N 5

int thread_func(void* arg) {
    thrd_t receivedId = *(thrd_t*)arg;
    thrd_t calculatedId = thrd_current();
    printf("Received ID: %lu\n", receivedId);
    printf("Calculated ID: %lu\n", calculatedId);
    return thrd_success;
}

int main() {
    thrd_t threads[N];

    for (int i = 0; i < N; ++i)
        thrd_create(&threads[i],
               thread_func,
               &threads[i]
        );

    for (int i = 0; i < N; ++i) {
        thrd_t ret = thrd_join(threads[i], NULL);
        if (ret == thrd_success)
            printf("Thread with ID: %lu\n", threads[i]);
        else
            printf("Failure to join thread with ID: %lu\n", ret);
    }
}
