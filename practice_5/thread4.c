#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NTHREADS 5
void *myFun(void *x)
{
    int tid;
    tid = *((int *) x);
    printf("Hi from thread %d!\n", tid);
    return NULL;
}
int main(int argc, char *argv[])
{
    pthread_t threads[NTHREADS];
    int thread_args[NTHREADS];
    int rc, i;
    /* spawn the threads */
    for (i=0; i<NTHREADS; ++i)
    {
        thread_args[i] = i;
        printf("spawning thread %d\n", i);
        rc = pthread_create(&threads[i], NULL, myFun, (void *) &thread_args[i]);
        if (rc != 0) {
            fprintf(stderr, "Error creating thread %d\n", i);
            exit(1);
        }
    }
    /* wait for threads to finish */
    for (i=0; i<NTHREADS; ++i) {
        rc = pthread_join(threads[i], NULL);
        if (rc != 0) {
            fprintf(stderr, "Error joining thread %d\n", i);
            exit(1);
        }
    }
    return 1;
}
