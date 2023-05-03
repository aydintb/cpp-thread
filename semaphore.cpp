#include <pthread.h>
#include <semaphore.h>
#include <iostream>

// The shared resource that we want to protect
int counter = 0;

// The semaphore that we will use to protect the shared resource
sem_t semaphore;

// The function that will be executed by each thread
void* threadFunction(void* arg)
{
    // Wait for the semaphore to become available
    sem_wait(&semaphore);

    // Increment the counter
    counter++;

    // Print the current value of the counter
    std::cout << "Counter: " << counter << std::endl;

    // Release the semaphore
    sem_post(&semaphore);

    return NULL;
}

int main()
{
    // Initialize the semaphore with an initial value of 1
    sem_init(&semaphore, 0, 1);

    // Create two threads
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);

    // Wait for the threads to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // Destroy the semaphore
    sem_destroy(&semaphore);

    return 0;
}

