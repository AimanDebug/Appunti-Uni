#ifndef MY_BARRIER_H
#define MY_BARRIER_H

#include <stddef.h>
#include <threads.h>

typedef struct my_barrier {
    mtx_t mutex; // The mutex associated with this barrier
    cnd_t condition;
    size_t barrier_count; // The number of threads need to pass the barrier
    size_t total_threads; // The number of threads that are currently waiting
} my_barrier_t;

// Initialize the barrier
void init_barrier(my_barrier_t* barrier,
        int mutex_type,
        size_t barrier_count);
// Deinitialize the barrier
void destroy_barrier(my_barrier_t* barrier);
// Set up barrier point
void wait_on_barrier(my_barrier_t* barrier);

#endif
