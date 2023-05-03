#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 10

int shared_data = 0;
sem_t semaphore;

void* increment_data(void* arg) {
    int thread_id = *(int*)arg;
    sem_wait(&semaphore);
    printf("Thread %d acquired semaphore and incremented data from %d to %d\n", thread_id, shared_data, shared_data + 1);
    shared_data++;
    sem_post(&semaphore);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    sem_init(&semaphore, 0, 1);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, increment_data, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Final data value is: %d\n", shared_data);

    sem_destroy(&semaphore);

    return 0;
}

