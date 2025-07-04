#include <iostream>
#include <future>
#include <thread>

void job(size_t job_id)
{
    std::cout << job_id << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(job_id));
}

std::string job_converter(size_t job_id)
{
    return std::to_string(job_id);
}

int main()
{
    size_t concurrency_size = std::thread::hardware_concurrency();
    std::cout << "hardware_concurrency: " << concurrency_size << std::endl;

    /*std::cout << "jthread" << std::endl;
    {
        std::vector<std::jthread> threads;

        for (size_t i = 0; i < concurrency_size / 2; ++i)
        {
            threads.emplace_back(job, concurrency_size-i);
        }
    }*/

    std::cout << "thread" << std::endl;
    {
        std::vector<std::thread> threads;

        for (size_t i = 0; i < concurrency_size / 2; ++i)
        {
            threads.emplace_back(job, concurrency_size-i);
        }

        for (auto &thread : threads) {
            thread.join();
        }
    }

    {
        std::future<std::string> f = std::async(std::launch::async, job_converter, 100500);
        std::cout << "future result: " << f.get() << std::endl;
    }
    return 0;
}
