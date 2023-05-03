#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// The shared resource that we want to protect
int data = 0;

// The mutex that we will use to protect the shared resource
std::mutex data_mutex;

// The condition variable that we will use to signal when the data has been updated
std::condition_variable data_cv;

// The function that will be executed by the reader thread
void readerFunction()
{
    // Acquire the mutex lock to read the data
    std::unique_lock<std::mutex> lock(data_mutex);

    // Wait until the data has been updated
    data_cv.wait(lock, []{ return data > 0; });

    // Read the data
    std::cout << "Reader " << std::this_thread::get_id() << " read data: " << data << std::endl;
}

// The function that will be executed by the writer thread
void writerFunction()
{
    // Acquire the mutex lock to write to the data
    std::unique_lock<std::mutex> lock(data_mutex);

    // Write to the data
    data = 42;
    std::cout << "Writer " << std::this_thread::get_id() << " wrote data: " << data << std::endl;

    // Signal the condition variable to wake up any waiting readers
    data_cv.notify_all();
}

int main()
{
    // Create a reader thread
    std::thread reader(readerFunction);

    // Create a writer thread
    std::thread writer(writerFunction);

    // Wait for both threads to finish
    reader.join();
    writer.join();

    return 0;
}

