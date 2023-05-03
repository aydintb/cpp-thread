#include <iostream>
#include <future>

// The function that will be executed by the worker thread
void workerFunction(std::future<int>& fut)
{
    // Wait for the message from the main thread
    int data = fut.get();

    // Process the message
    std::cout << "Worker function received data: " << data << std::endl;
}

int main()
{
    // Create a promise to send the message to the worker thread
    std::promise<int> prom;

    // Get the future object to receive the result from the worker thread
    std::future<int> fut = prom.get_future();

    // Create the worker thread and pass it the future object
    std::thread worker(workerFunction, std::ref(fut));

    // Send the message to the worker thread
    prom.set_value(42);

    // Wait for the worker thread to finish
    worker.join();

    return 0;
}

