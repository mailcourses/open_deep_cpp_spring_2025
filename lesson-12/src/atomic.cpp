#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int32_t> data = 0;

void increment(size_t id)
{
    data += 1; // data = data + 1
    /*
    int tmp = data + 1; // 1 // 2
    data = tmp; // 2 // 1
    */
    //std::cout << id << ") data = " << data << "\n";
}

int main()
{
    size_t threads_cnt = 32;
    std::vector<std::thread> threads;
    threads.reserve(threads_cnt);

    for (size_t i = 0; i < threads_cnt; ++i)
    {
        threads.emplace_back(increment, i);
    }

    for (auto &thread : threads)
    {
        thread.join();
    }
    std::cout << "data: " << data << "\n";
}
