#include <threads.h>
#include <stdio.h>

int counter = 0;

#define K 1000
#define MUTEX_VERSION

#ifdef MUTEX_VERSION
mtx_t mutex;
#endif

int worker(void* arg) {
    for (int i = 0; i < K; ++i) {
#ifdef MUTEX_VERSION
        mtx_lock(&mutex);
#endif

        ++counter;

#ifdef MUTEX_VERSION
        mtx_unlock(&mutex);
#endif
    }
    
    return 0;
}

#define T 10000

int main() {
    thrd_t threads[T];
#ifdef MUTEX_VERSION
    mtx_init(&mutex, mtx_plain);
#endif

    for (int i = 0; i < T; ++i)
        if (thrd_create(&threads[i], worker, NULL)) {
            fprintf(stderr, "Error creating thread %d\n", i);
            return 1;
        }

    for (int i = 0; i < T; ++i)
        if (thrd_join(threads[i], NULL)) {
            fprintf(stderr, "Error joining thread %d\n", i);
            return 1;
        }

    printf("K*T: %d, counter: %d\n", K * T, counter);

#ifdef MUTEX_VERSION
    mtx_destroy(&mutex);
#endif
}
