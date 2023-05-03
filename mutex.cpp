#include <iostream>
#include <thread>
#include <mutex>

// The shared resource that we want to protect
int counter = 0;

// The mutex that we will use to protect the shared resource
std::mutex mutex;

// The function that will be executed by each thread
void threadFunction()
{
    // Lock the mutex
    mutex.lock();

    // Increment the counter
    counter++;

    // Print the current value of the counter
    std::cout << "Counter: " << counter << std::endl;

    // Unlock the mutex
    mutex.unlock();
}

int main()
{
    // Create two threads
    std::thread thread1(threadFunction);
    std::thread thread2(threadFunction);

    // Wait for the threads to finish
    thread1.join();
    thread2.join();

    return 0;
}


