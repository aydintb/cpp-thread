#include <iostream>
#include <atomic>
#include <thread>

// The atomic variable that we will use
std::atomic<int> counter(0);

// The function that will be executed by the threads
void incrementCounter()
{
    for (int i = 0; i < 1000000; ++i)
    {
        counter++; // Increment the counter atomically
    }
}

int main()
{
    // Create two threads
    std::thread thread1(incrementCounter);
    std::thread thread2(incrementCounter);

    // Wait for both threads to finish
    thread1.join();
    thread2.join();

    // Print the final value of the counter
    std::cout << "Counter: " << counter << std::endl;

    return 0;
}

