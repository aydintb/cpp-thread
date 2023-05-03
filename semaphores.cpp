#include <iostream>
#include <thread>
#include <mutex>

#define NUM_THREADS 10

int shared_data = 0;
std::mutex mutex;

void increment_data(int thread_id) {
    mutex.lock();
    std::cout << "Thread " << thread_id << " acquired mutex and incremented data from " << shared_data << " to " << shared_data + 1 << std::endl;
    shared_data++;
    mutex.unlock();
}

int main() {
    std::thread threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i] = std::thread(increment_data, i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i].join();
    }

    std::cout << "Final data value is: " << shared_data << std::endl;

    return 0;
}

