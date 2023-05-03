#include <iostream>
#include <thread>
#include <shared_mutex>

// The shared resource that we want to protect
int data = 0;

// The read-write lock that we will use to protect the shared resource
std::shared_mutex rw_mutex;

// The function that will be executed by each reader thread
void readerFunction()
{
    // Acquire a shared lock to read the data
    rw_mutex.lock_shared();

    // Read the data
    std::cout << "Reader " << std::this_thread::get_id() << " read data: " << data << std::endl;

    // Release the shared lock
    rw_mutex.unlock_shared();
}

// The function that will be executed by each writer thread
void writerFunction()
{
    // Acquire an exclusive lock to write to the data
    rw_mutex.lock();

    // Write to the data
    data++;
    std::cout << "Writer " << std::this_thread::get_id() << " wrote data: " << data << std::endl;

    // Release the exclusive lock
    rw_mutex.unlock();
}

int main()
{
    // Create four reader threads
    std::thread reader1(readerFunction);
    std::thread reader2(readerFunction);
    std::thread reader3(readerFunction);
    std::thread reader4(readerFunction);

    // Create two writer threads
    std::thread writer1(writerFunction);
    std::thread writer2(writerFunction);

    // Wait for all threads to finish
    reader1.join();
    reader2.join();
    reader3.join();
    reader4.join();
    writer1.join();
    writer2.join();

    return 0;
}

