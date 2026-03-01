#include <threads.h>
#include <stdatomic.h>
#include <stdio.h>

atomic_int atomic_counter = 0;
int counter = 0;

int thread_func(void* arg) {
    for (int i = 0; i < 1000000; i++) {
        ++atomic_counter;
        ++counter;
    }

    return 0;
}

int main() {
    thrd_t threads[5];

    for (int i = 0; i < 5; i++) {
        thrd_create(&threads[i], thread_func, NULL);
    }

    for (int i = 0; i < 5; i++) {
        thrd_join(threads[i], NULL);
    }

    printf("Atomic Counter: %d\n", atomic_counter);
    printf("Non-Atomic Counter: %d\n", counter);
}
