#include <threads.h>
#include <stdio.h>

#define PIPPO 10
#define PLUTO 10

int pluto(void* arg) {
    printf("Pluto thread %d: bao!\n", *(int*)arg);
    return 0;
}

int pippo(void* arg) {
    printf("Pippo thread %d: Devo aspettare %d pluti...\n", *(int*)arg, PLUTO);

    thrd_t threadPluto[PLUTO];

    for (int i = 0; i < PLUTO; ++i)
        thrd_create(&threadPluto[i], pluto, &i);

    for (int i = 0; i < PLUTO; ++i)
        thrd_join(threadPluto[i], NULL);
    
    printf("Ho finito di aspettare i pluti, ora posso moririre.\n");
    return 0;
}

int main() {
    thrd_t threadPippo[PIPPO];

    for (int i = 0; i < PIPPO; ++i) {
        thrd_create(&threadPippo[i], pippo, &i);
    }

    for (int i = 0; i < PIPPO; ++i) {
        thrd_join(threadPippo[i], NULL);
    }

    return 0;
}
