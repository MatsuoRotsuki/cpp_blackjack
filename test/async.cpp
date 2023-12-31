#include <iostream>
#include <future>
#include <atomic>
#include <chrono>

std::atomic<bool> exitFlag(false);

void threadFunction() {
    while (!exitFlag) {
        // Check if there is any input available
        std::future<bool> future = std::async(std::launch::async, []() {
            return static_cast<bool>(std::cin.rdbuf()->in_avail());
        });

        // Wait for either input or a timeout
        if (future.wait_for(std::chrono::milliseconds(100)) == std::future_status::ready) {
            std::string input;
            std::cin >> input;

            // Process the input or perform other tasks
        }

        // Check the exit flag
        if (exitFlag)
            break;

        // Continue processing or wait for input
    }

    // Perform any cleanup tasks before exiting the thread
    std::cout << "Thread is exiting.\n";
}

int main() {
    // Start the thread
    std::thread myThread(threadFunction);

    // Wait for user input to exit
    std::cout << "Press enter to exit.\n";
    std::cin.get(); // This will block until the user presses enter

    // Set the exit flag to signal the thread to exit
    exitFlag = true;

    // Wait for the thread to finish
    myThread.join();

    std::cout << "Main program exiting.\n";

    return 0;
}