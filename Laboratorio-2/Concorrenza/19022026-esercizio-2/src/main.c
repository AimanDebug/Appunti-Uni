#include <threads.h>
#include <time.h>
#include <stdio.h>

int logger(void* arg) {
    while (1) {
        printf("Worker thread is running...\n");
        thrd_sleep(&(struct timespec){.tv_sec = 1}, NULL);
    }
}

int main() {
    thrd_t logger_thread;

    if (thrd_create(&logger_thread, logger, NULL) != thrd_success) {
        fprintf(stderr, "Failed to create logger thread\n");
        return 1;
    }

    thrd_detach(logger_thread);
    thrd_sleep(&(struct timespec){.tv_sec = 3}, NULL);
    printf("Main thread exiting\n");
}
