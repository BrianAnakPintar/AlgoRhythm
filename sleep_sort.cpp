#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> SleepSort(const std::vector<int>& dataset) {
    int n = dataset.size();
    std::vector<int> out;
    std::vector<std::thread> threads;
    std::mutex mx;
    for (int i = 0; i < n; ++i) {
        int time = dataset[i];
        threads.emplace_back([i, time, &mx, &out]() {
            std::this_thread::sleep_for(std::chrono::seconds(time));
            mx.lock();
            out.push_back(time);
            // Just for fun let's see how this works live.
            std::cout << time << ' ' << std::flush;
            mx.unlock();
        });
    }

    for (auto& thread : threads) {
        thread.join();
    }
    return out;
}

int main(int argc, char* argv[]) {
    std::vector<int> v = {5,3,4,1,2,2, 10, 2, 3, 4,5, 6,1,1,3};
    std::vector<int> sorted = SleepSort(v);
    std::cout << "\nSorted string:\n";
    for (int val : sorted)
        std::cout << val << ' ';
}