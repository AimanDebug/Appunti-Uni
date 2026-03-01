#include <threads.h>
#include <time.h>
#include <stdio.h>

typedef struct {
    int id;
    unsigned int sleep_time;
} worker_arg_t;

int worker(void* arg) {
    worker_arg_t* input = (worker_arg_t*)arg;
    printf("T%d: start\n", input->id);
    // Sleep for 2 seconds
    thrd_sleep(&(struct timespec){.tv_sec = input->sleep_time}, NULL);
    printf("T%d: end\n", input->id);
    return input->id * 10;
}

#define N 5

int main() {
    thrd_t threads[N];

    for (int i = 0; i < N; ++i)
        if (thrd_create(&threads[i], worker, &(worker_arg_t){.id = i, .sleep_time = 2})) {
            fprintf(stderr, "Failed to create thread %d\n", i);
            return 1;
        }

    for (int i = 0; i < N; ++i) {
        int res;
        if (thrd_join(threads[i], &res)) {
            fprintf(stderr, "Failed to join thread %d\n", i);
            return 1;
        }
        printf("Main: joined %d with result %d\n", i, res);
    }
}
